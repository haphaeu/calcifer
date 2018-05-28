#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "OrcFxAPI.h"
#include "ExternalFunction.h"


using namespace Orcina;

static void PrintDiagnostics(LPCWSTR DiagnosticString)
{
  int Status;
  C_ExternalFunctionPrint(DiagnosticString, &Status);
  if(!StatusOK(Status))
    ThrowError(L"Unable to print diagnostics.");
}

// Checks the status value, returns ture if the status value is stOK.
bool StatusOK(int Status)
{
  return Status==stOK;
}

// Returns the integer VarID corresponding to a named result variable
int GetResultVarID(TOrcFxAPIHandle ObjectHandle, LPCWSTR ResultName)
{
  int Result, Status;
  C_GetVarID(ObjectHandle, ResultName, &Result, &Status);
  if(!StatusOK(Status))
    ThrowError(L"Unable to get VarID.");
  return Result;
}

// Used to throw an CExternalFunctionException exception.
void ThrowError(const wstring &Message)
{
  throw new CExternalFunctionException(Message);
}

void ThrowError(LPCWSTR Message)
{
  ThrowError(wstring(Message));
}


// Function to report errors back to OrcaFlex using C_RecordExternalFunctionError.
// The function also checks to see if C_GetLastErrorString has any additional
// information that can be reported along side the user specified message.
void ReportError(TExtFnInfo &ExtFnInfo, LPCWSTR pMessage)
{
  wstring error;
  int len=C_GetLastErrorString(NULL);
  if(len>1) {
    wchar_t *LastErrorString = new wchar_t[len];
    C_GetLastErrorString(LastErrorString);
    error+=LastErrorString;
    delete [] LastErrorString;
    error+=L"  ";
  }
  error+=pMessage;

  int Status;
  C_RecordExternalFunctionError(&ExtFnInfo, error.c_str(), &Status);
  // There is no point checking the status here as we have already failed to
  // report the error. Reporting another error would most likely fail as well.
}

// Case insensitive test of string equality
bool SameText(LPCWSTR pString1, LPCWSTR pString2)
{
  return _wcsicmp(pString1, pString2)==0;
}

// Case insensitive test of string equality, but only compare the first count characters
bool SameText(LPCWSTR pString1, LPCWSTR pString2, size_t count)
{
  return _wcsnicmp(pString1, pString2, count)==0;
}

void RegisterResult(
  TExtFnInfo *lpExtFnInfo,
  int ResultID,
  LPCTSTR Name,
  LPCTSTR Units)
{
  int Status=stOK;
  TExtFnResultInfo EFRInfo = {sizeof(EFRInfo), ResultID, Name, Units};
  C_RegisterExternalFunctionResult(lpExtFnInfo, &EFRInfo, &Status);
  if(!StatusOK(Status))
    ThrowError(L"Unable to register result.");
}


////////// CParams class //////////
CParams::CParams(LPCWSTR Params) :
  wstring(Params)
{
}

wstring CParams::Trim(const wstring &s) const
{
  wstring Result=s;
  wstring Whitespaces(L" \t\f\v\n\r");

  size_t Pos=Result.find_first_not_of(Whitespaces);
  
  
  if(Pos==wstring::npos) {
    Result.clear();
    return Result;
  }
  Result.erase(0, Pos);
  Pos=Result.find_last_not_of(Whitespaces);
  if(Pos!=wstring::npos)
    Result.erase(Pos+1);
  return Result;
}

wstring CParams::GetValueOf(LPCWSTR Name, LPCWSTR DefaultValue) const
{
  wistringstream paramstream(*this, wistringstream::in);
  wstring line;
  
  //PrintDiagnostics(L"in GetValueOf");
          
  while (getline(paramstream, line)) {
    //remove comments from this line
    size_t pos=line.find(L"//");
    if (pos!=wstring::npos)
      line.erase(pos);

    //looking for name=value pairs
    pos=line.find(L"=");
    if (pos!=wstring::npos)
    {
      wstring name=line;
      name=Trim(name.erase(pos));
      if (SameText(name.c_str(), Name))
      {
        line.erase(0, pos+1);
        return Trim(line);
      }
    }
  }

  return DefaultValue;
}

// Overloaded TVector2 operators.
bool operator ==(TVector2 V1, TVector2 V2)
{
  return V1.X==V2.X && V1.Y==V2.Y;
}
bool operator !=(TVector2 V1, TVector2 V2)
{
  return !(V1==V2);
}

////////// CTable class //////////
CTable::CTable(LPCWSTR Parameters, LPCWSTR XName, LPCWSTR YName)
{
  CParams Params(Parameters);
  vector<double> x=Values(Params, XName);
  vector<double> y=Values(Params, YName);
  if(x.size()!=y.size())
    ThrowError(L"There are a different numbers of X and Y values.");
  if(x.size()==0)
    ThrowError(L"No X and Y values were found.");
  for (size_t i=0; i<x.size(); i++) {
    TVector2 value = {x[i], y[i]};
    m_data.push_back(value);
  }
}

vector<double> CTable::Values(CParams Params, LPCWSTR Name)
{
  vector<double> result;
  wistringstream valuestream(Params.GetValueOf(Name), wistringstream::in);
  double item;
  while(valuestream >> item) {
    result.push_back(item);
  }
  return result;
}

double CTable::YAtX(double XValue) const
{
  // Find the X bracket. The unusual loop limits mean that
  // we will extrapolate for values outside the table.
  int i;
  for(i=1; i<Count()-1; i++)
  {
    if(X(i)>XValue)
      break;
  }

  // Linearly interpolate the required value.
  double Gradient=(Y(i)-Y(i-1))/(X(i)-X(i-1));
  return Y(i-1) + Gradient*(XValue-X(i-1));
}

bool CTable::MonotoneIncreasing() const
{
  for(int i=1; i<Count(); i++)
    if(m_data[i-1].X>=m_data[i].X || m_data[i-1].Y>=m_data[i].Y)
      return false;
  return true;
}