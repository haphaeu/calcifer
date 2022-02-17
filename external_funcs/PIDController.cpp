#include <windows.h>
#include "OrcFxAPI.h"
#include "ExternalFunction.h"

struct PIDState {
  bool Valid;
  double Time;
  double Signal;
  double iedt;
  double dedt;
};

struct StateData
{
  PIDState Now;
  PIDState Prev;
};

// Structure to store all the data required between calls.
struct PersistentData
{
  TOrcFxAPIHandle ObjectHandle;
  TObjectExtra2 ObjectExtra;
  double kP;
  double kD;
  double kI;
  double k0;
  double Target;
  double ControlStartTime;
  int VarID;
  wstring WingName;
  double InitialValue;
  StateData State;
  double MinValue;
  double MaxValue;
  bool OutputDiagnostics;
};

TPeriod InstantaneousValue={pnInstantaneousValue};

const int iedtResultID=0;
const int dedtResultID=1;

// Local helper functions.
static void Initialise
(
  TOrcFxAPIHandle ObjectHandle,
  LPCWSTR ParamsText,
  LPVOID &lpData,
  double InitialValue,
  LPVOID lpStoredData,
  int LengthOfStoredData
);
static double CalculateValue(double Time, BOOL NewTimeStep, PersistentData &Data);
static void StoreStateCreate(PersistentData &Data, LPVOID &lpStateData, int &LengthOfStateData);
static void StoreStateDestroy();
static double DeriveResult(PIDState const &Now, int const ResultID);
static void LogResultCreate(PersistentData &Data, int &LengthOfLogData, LPVOID &pLogData);
static double GetInstantaneousValue(int VarID, TOrcFxAPIHandle ObjectHandle, const TObjectExtra2 &ObjectExtra);
static void PrintDiagnostics(LPCWSTR DiagnosticString);

// Added by Rafael
#ifdef __cplusplus
extern "C" {
#endif
// Entry point function.
//void __stdcall PIDController(TExtFnInfo &ExtFnInfo)
void __declspec(dllexport) PIDController(TExtFnInfo &ExtFnInfo)
{
  //PrintDiagnostics(L"in PIDController \n");
  
  EXTERNAL_FUNCTIONS_TRY
  {
    switch(ExtFnInfo.Action)
    {
    case eaRegisterResults:
    {
      //PrintDiagnostics(L"  eaRegisterResults\n");
      // Register the results that we can support.

      RegisterResult(&ExtFnInfo, iedtResultID, (wstring(ExtFnInfo.lpDataName)+L" PID iedt").c_str(), L"LLTT");
      RegisterResult(&ExtFnInfo, dedtResultID, (wstring(ExtFnInfo.lpDataName)+L" PID dedt").c_str(), L"LL/TT");
    }
    case eaInitialise:
    {
      //PrintDiagnostics(L"  eaInitialise\n");
      if(!StructureContains(ExtFnInfo, NewTimeStep))
        ThrowError(L"This external function requires OrcaFlex version 9.5 or later");
      LPVOID lpStateData=ExtFnInfo.lpStateData;
      int LengthOfStateData=ExtFnInfo.LengthOfStateData;
      Initialise(ExtFnInfo.ObjectHandle, ExtFnInfo.lpObjectParameters, ExtFnInfo.lpData, ExtFnInfo.Value, lpStateData, LengthOfStateData);
      break;
    }
    case eaFinalise:
    {
      PersistentData* pData = (PersistentData*)ExtFnInfo.lpData;
      if(pData->OutputDiagnostics)
        PrintDiagnostics(L"Finalised\n");
      //cast added by Rafael:
      delete (PersistentData*)ExtFnInfo.lpData;
      break;
    }
    case eaCalculate:
    {
      //PrintDiagnostics(L"  eaCalculate\n");
      PersistentData* pData = (PersistentData*)ExtFnInfo.lpData;
      ExtFnInfo.Value = CalculateValue(ExtFnInfo.SimulationTime, ExtFnInfo.NewTimeStep, *pData);
      break;
    }
    case eaStoreStateCreate:
    {
      PrintDiagnostics(L"  eaStoreStateCreate\n");
      PersistentData* pData = (PersistentData*)ExtFnInfo.lpData;
      StoreStateCreate(*pData, ExtFnInfo.lpStateData, ExtFnInfo.LengthOfStateData);
      break;
    }
    case eaStoreStateDestroy:
    {
      PrintDiagnostics(L"  eaStoreStateDestroy\n");
      StoreStateDestroy();
      break;
    }
    case eaDeriveResult:
    {
      PrintDiagnostics(L"  eaDeriveResult\n");
      PIDState* pNow = (PIDState*)ExtFnInfo.lpLogData;
      ExtFnInfo.Value = DeriveResult(*pNow, ExtFnInfo.ResultID);
      break;
    }
    case eaLogResultCreate:
    {
      //PrintDiagnostics(L"  eaLogResultCreate\n");
      PersistentData* pData = (PersistentData*)ExtFnInfo.lpData;
      LogResultCreate(*pData, ExtFnInfo.LengthOfLogData, ExtFnInfo.lpLogData);
      break;
    }
    case eaLogResultDestroy:
      break;
    }
  }
  EXTERNAL_FUNCTIONS_CATCH(ExtFnInfo)
}
#ifdef __cplusplus
}
#endif
static double CalculateValue(double Time, BOOL NewTimeStep, PersistentData &Data)
{
  if(Time<Data.ControlStartTime)
    return Data.InitialValue;

  StateData* pState = &Data.State;

  if(NewTimeStep && pState->Now.Valid)
  {
    pState->Prev.Time = pState->Now.Time;
    pState->Prev.Signal = pState->Now.Signal;
    pState->Prev.iedt = pState->Now.iedt;
    pState->Prev.Valid = true;
  }

  double Signal = GetInstantaneousValue(Data.VarID, Data.ObjectHandle, Data.ObjectExtra);

  pState->Now.Time = Time;
  pState->Now.Signal = Signal;
  pState->Now.iedt = pState->Prev.iedt;
  pState->Now.Valid = true;

  double Target = Data.Target;
  double e = Target - pState->Now.Signal;
  if(pState->Prev.Valid) {
    double prev_e = Target - pState->Prev.Signal;
    double dt = pState->Now.Time - pState->Prev.Time;
    pState->Now.dedt = (e-prev_e)/dt;
    pState->Now.iedt += dt*(e+prev_e)/2.0;
    if(Data.OutputDiagnostics)
    {
      wostringstream diagnostics;
      diagnostics << "e=" << e << "\tdedt=" << pState->Now.dedt << "\tiedt=" << pState->Now.iedt << "\n";
      PrintDiagnostics(diagnostics.str().c_str());
    }
  }

  double Result = Data.kP*e + Data.kI*pState->Now.iedt + Data.kD*pState->Now.dedt + Data.k0;

  // Limit the output from the PID controller.
  Result = max(Result, Data.MinValue);
  Result = min(Result, Data.MaxValue);
  return Result;
}

static void PrintDiagnostics(LPCWSTR DiagnosticString)
{
  int Status;
  C_ExternalFunctionPrint(DiagnosticString, &Status);
  if(!StatusOK(Status))
    ThrowError(L"Unable to print diagnostics.");
}

static double GetInstantaneousValue(int VarID, TOrcFxAPIHandle ObjectHandle, const TObjectExtra2 &ObjectExtra)
{
  double Result;
  int Status;
  C_GetTimeHistory2(ObjectHandle, &ObjectExtra, &InstantaneousValue, VarID, &Result, &Status);
  if(!StatusOK(Status))
    ThrowError(L"Unable to get instantaneous value of signal.");
  return Result;
}

static void Initialise(TOrcFxAPIHandle ObjectHandle, LPCWSTR ParamsText, LPVOID &lpData, double InitialValue, LPVOID lpStateData, int LengthOfStateData)
{
  // New some memory to store the persistent, per external function,
  // variables and associate it with the external function. This
  // memory will be delete when the DLL is finalised.
  PersistentData *pData=new PersistentData;
  memset(pData, 0, sizeof(*pData));
  lpData=pData;
  
  PrintDiagnostics(L"in Initialise()\n");
  
  //PrintDiagnostics(L"  Setting bits\n");
  // Set up bits of the ObjectExtra structure that we know.
  pData->ObjectExtra.Size=sizeof(TObjectExtra2);
  pData->ObjectExtra.LinePoint=ptArcLength;
  pData->State.Now.Valid=false;
  pData->State.Prev.Valid=false;
  pData->InitialValue=InitialValue;
  
  //PrintDiagnostics(L"  Reading parameters\n");
  // Read parameters.
  CParams Params(ParamsText); 
  wstring ControlledObjectName=Params.GetValueOf(L"ControlledVariableObjectName");
  wstring ControlledVarName=Params.GetValueOf(L"ControlledVariableResultName");
  pData->ObjectExtra.ArcLength=Params.GetValueOf(L"ObjectExtra.ArcLength", 0.0);
  // this line crashes
  //pData->WingName=Params.GetValueOf(L"ObjectExtra.WingName");
  //if(!pData->WingName.empty()) 
  //  pData->ObjectExtra.WingName=pData->WingName.c_str();
  
  pData->ObjectExtra.WinchConnectionPoint=Params.GetValueOf(L"ObjectExtra.WinchConnectionPoint", 0L);
  pData->Target=Params.GetValueOf(L"DesiredValue", 0.0);
  pData->kI=Params.GetValueOf(L"kI", 0.0);
  pData->kP=Params.GetValueOf(L"kP", 0.0);
  pData->kD=Params.GetValueOf(L"kD", 0.0);
  pData->k0=Params.GetValueOf(L"k0", 0.0);
  // If no value of ControlStartTime is specified then we activate the control system at the start of the simulation
  pData->ControlStartTime=Params.GetValueOf(L"ControlStartTime", -OrcinaInfinity());
  pData->State.Prev.iedt=Params.GetValueOf(L"Initial e/D", 0.0);
  pData->State.Now.dedt=Params.GetValueOf(L"Initial De", 0.0);
  pData->MinValue=Params.GetValueOf(L"MinValue", -OrcinaInfinity());
  pData->MaxValue=Params.GetValueOf(L"MaxValue", OrcinaInfinity());
  pData->OutputDiagnostics=SameText(Params.GetValueOf(L"OutputDiagnostics",L"No").c_str(), L"Yes");

  // Get the model handle..
  //PrintDiagnostics(L"  getting ModelHandle\n");
  TOrcFxAPIHandle ModelHandle;
  int Status;
  C_GetModelHandle(ObjectHandle, &ModelHandle, &Status);
  
  if(!StatusOK(Status))
    ThrowError(L"Unable to get the model handle from the object handle.");

  // Get the object from which the differential result will be calculated.
  TObjectInfo ObjectInfo;
  C_ObjectCalled(ModelHandle, ControlledObjectName.c_str(), &ObjectInfo, &Status);
  if(!StatusOK(Status))
    ThrowError(L"Unable to get the controlled object's handle from its name.");

  pData->ObjectHandle=ObjectInfo.ObjectHandle;

  // Get the var ID of the target variable.
  pData->VarID=GetResultVarID(pData->ObjectHandle, ControlledVarName.c_str());

  // If we have some stored data passed in then a part run simulation
  // has been loaded, so pick up where we left off instead of from the start
  // by restoring the data provided.
  if(lpStateData)
  {
    if(LengthOfStateData!=sizeof(pData->State))
      ThrowError(L"The length of the state data was not as expected.");
    memcpy(&pData->State, lpStateData, LengthOfStateData);
  }

  if(pData->OutputDiagnostics)
    PrintDiagnostics(L"Initialised\n");
}

static void StoreStateCreate(PersistentData &Data, LPVOID &lpStateData, int &LengthOfStateData)
{
  // If required we could "new" a memory block here, but in this case the data
  // is in a format that we can simply pass the pointer to it.
  lpStateData=&Data.State;
  LengthOfStateData=sizeof(Data.State);
}

static void StoreStateDestroy()
{
  // If we had "new'ed" a memory block in StoreStateCreate we could delete it here.
  // In this case there is nothing to do as no memory was allocated.
}

static double DeriveResult(PIDState const &Now, int const ResultID)
{
  // Return the results required.
  double Value=OrcinaUndefinedReal();
  if(Now.Valid)
  {
    switch(ResultID)
    {
    case iedtResultID:
      Value=Now.iedt;
      break;
    case dedtResultID:
      Value=Now.dedt;
      break;
    }
  }
  return Value;
}

static void LogResultCreate(PersistentData &Data, int &LengthOfLogData, LPVOID &pLogData)
{
  LengthOfLogData=sizeof(Data.State.Now);
  pLogData=&Data.State.Now;
}
