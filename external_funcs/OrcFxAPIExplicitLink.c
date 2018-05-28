#include "OrcFxAPI.h"

static HMODULE _Module = NULL;

// Added by Rafael
//void __stdcall InitializeOrcFxAPI(HMODULE Module)
void __declspec(dllexport) InitializeOrcFxAPI(HMODULE Module)
{
    _Module = Module;
}

void __stdcall C_ClearModel(
    TOrcFxAPIHandle ModelHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_ClearModel");
    proc(ModelHandle, lpStatus);
}

void __stdcall C_CopyBuffer(
    TOrcFxAPIHandle SourceBufferHandle,
    unsigned char *lpDestBuffer,
    int64_t DestBufferLen,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle SourceBufferHandle, unsigned char *lpDestBuffer, int64_t DestBufferLen, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CopyBuffer");
    proc(SourceBufferHandle, lpDestBuffer, DestBufferLen, lpStatus);
}

void __stdcall C_CreateClone(
    TOrcFxAPIHandle SourceObjectHandle,
    TOrcFxAPIHandle *lpClonedObjectHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle SourceObjectHandle, TOrcFxAPIHandle *lpClonedObjectHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CreateClone");
    proc(SourceObjectHandle, lpClonedObjectHandle, lpStatus);
}

void __stdcall C_CreateClone2(
    TOrcFxAPIHandle SourceObjectHandle,
    TOrcFxAPIHandle DestModelHandle,
    TOrcFxAPIHandle *lpClonedObjectHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle SourceObjectHandle, TOrcFxAPIHandle DestModelHandle, TOrcFxAPIHandle *lpClonedObjectHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CreateClone2");
    proc(SourceObjectHandle, DestModelHandle, lpClonedObjectHandle, lpStatus);
}

void __stdcall C_CreateModel(
    TOrcFxAPIHandle *lpModelHandle,
    HWND hCaller,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle *lpModelHandle, HWND hCaller, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CreateModel");
    proc(lpModelHandle, hCaller, lpStatus);
}

void __stdcall C_CreateModel2(
    TOrcFxAPIHandle *lpModelHandle,
    const TCreateModelParams *lpCreateModelParams,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle *lpModelHandle, const TCreateModelParams *lpCreateModelParams, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CreateModel2");
    proc(lpModelHandle, lpCreateModelParams, lpStatus);
}

void __stdcall C_CreateObject(
    TOrcFxAPIHandle ModelHandle,
    int ObjectType,
    TOrcFxAPIHandle *lpObjectHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int ObjectType, TOrcFxAPIHandle *lpObjectHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CreateObject");
    proc(ModelHandle, ObjectType, lpObjectHandle, lpStatus);
}

void __stdcall C_DestroyModel(
    TOrcFxAPIHandle ModelHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_DestroyModel");
    proc(ModelHandle, lpStatus);
}

void __stdcall C_DestroyObject(
    TOrcFxAPIHandle ObjectHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_DestroyObject");
    proc(ObjectHandle, lpStatus);
}

void __stdcall C_DisableInMemoryLogging(
    TOrcFxAPIHandle ModelHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_DisableInMemoryLogging");
    proc(ModelHandle, lpStatus);
}

void __stdcall C_DisableModule(
    int Module,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(int Module, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_DisableModule");
    proc(Module, lpStatus);
}

void __stdcall C_EnumerateObjectsA(
    TOrcFxAPIHandle ModelHandle,
    TEnumerateObjectsProcA EnumerateObjectsProc,
    int *lpNumOfObjects,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, TEnumerateObjectsProcA EnumerateObjectsProc, int *lpNumOfObjects, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_EnumerateObjectsA");
    proc(ModelHandle, EnumerateObjectsProc, lpNumOfObjects, lpStatus);
}

void __stdcall C_EnumerateObjectsW(
    TOrcFxAPIHandle ModelHandle,
    TEnumerateObjectsProcW EnumerateObjectsProc,
    int *lpNumOfObjects,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, TEnumerateObjectsProcW EnumerateObjectsProc, int *lpNumOfObjects, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_EnumerateObjectsW");
    proc(ModelHandle, EnumerateObjectsProc, lpNumOfObjects, lpStatus);
}

void __stdcall C_ExchangeObjects(
    TOrcFxAPIHandle ObjectHandle1,
    TOrcFxAPIHandle ObjectHandle2,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle1, TOrcFxAPIHandle ObjectHandle2, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_ExchangeObjects");
    proc(ObjectHandle1, ObjectHandle2, lpStatus);
}

void __stdcall C_ExecutePostCalculationActionsA(
    TOrcFxAPIHandle ModelHandle,
    LPCSTR lpFileName,
    TStringProgressHandlerProcA ReportProgressProc,
    int ActionType,
    BOOL TreatExecutionErrorsAsWarnings,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, LPCSTR lpFileName, TStringProgressHandlerProcA ReportProgressProc, int ActionType, BOOL TreatExecutionErrorsAsWarnings, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_ExecutePostCalculationActionsA");
    proc(ModelHandle, lpFileName, ReportProgressProc, ActionType, TreatExecutionErrorsAsWarnings, lpStatus);
}

void __stdcall C_ExecutePostCalculationActionsW(
    TOrcFxAPIHandle ModelHandle,
    LPCWSTR lpFileName,
    TStringProgressHandlerProcW ReportProgressProc,
    int ActionType,
    BOOL TreatExecutionErrorsAsWarnings,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, LPCWSTR lpFileName, TStringProgressHandlerProcW ReportProgressProc, int ActionType, BOOL TreatExecutionErrorsAsWarnings, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_ExecutePostCalculationActionsW");
    proc(ModelHandle, lpFileName, ReportProgressProc, ActionType, TreatExecutionErrorsAsWarnings, lpStatus);
}

void __stdcall C_ExternalFunctionPrintA(
    LPCSTR lpText,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(LPCSTR lpText, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_ExternalFunctionPrintA");
    proc(lpText, lpStatus);
}

void __stdcall C_ExternalFunctionPrintW(
    LPCWSTR lpText,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(LPCWSTR lpText, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_ExternalFunctionPrintW");
    proc(lpText, lpStatus);
}

void __stdcall C_FreeBuffer(
    TOrcFxAPIHandle BufferHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle BufferHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_FreeBuffer");
    proc(BufferHandle, lpStatus);
}

void __stdcall C_GetBinaryFileTypeA(
    LPCSTR lpFileName,
    int *lpFileType,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(LPCSTR lpFileName, int *lpFileType, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetBinaryFileTypeA");
    proc(lpFileName, lpFileType, lpStatus);
}

void __stdcall C_GetBinaryFileTypeW(
    LPCWSTR lpFileName,
    int *lpFileType,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(LPCWSTR lpFileName, int *lpFileType, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetBinaryFileTypeW");
    proc(lpFileName, lpFileType, lpStatus);
}

INT_PTR __stdcall C_GetCallerLong(
    TOrcFxAPIHandle ObjectHandle,
    int *lpStatus
)
{
    typedef INT_PTR (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetCallerLong");
    return proc(ObjectHandle, lpStatus);
}

void __stdcall C_GetDLLVersionA(
    TDLLVersionA *lpRequiredDLLVersion,
    TDLLVersionA *lpDLLVersion,
    int *lpOK,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TDLLVersionA *lpRequiredDLLVersion, TDLLVersionA *lpDLLVersion, int *lpOK, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetDLLVersionA");
    proc(lpRequiredDLLVersion, lpDLLVersion, lpOK, lpStatus);
}

void __stdcall C_GetDLLVersionW(
    TDLLVersionW *lpRequiredDLLVersion,
    TDLLVersionW *lpDLLVersion,
    int *lpOK,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TDLLVersionW *lpRequiredDLLVersion, TDLLVersionW *lpDLLVersion, int *lpOK, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetDLLVersionW");
    proc(lpRequiredDLLVersion, lpDLLVersion, lpOK, lpStatus);
}

int __stdcall C_GetFileCreatorVersionA(
    LPCSTR lpFileName,
    LPSTR lpVersion,
    int *lpStatus
)
{
    typedef int (__stdcall *Proc)(LPCSTR lpFileName, LPSTR lpVersion, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFileCreatorVersionA");
    return proc(lpFileName, lpVersion, lpStatus);
}

int __stdcall C_GetFileCreatorVersionW(
    LPCWSTR lpFileName,
    LPWSTR lpVersion,
    int *lpStatus
)
{
    typedef int (__stdcall *Proc)(LPCWSTR lpFileName, LPWSTR lpVersion, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFileCreatorVersionW");
    return proc(lpFileName, lpVersion, lpStatus);
}

int __stdcall C_GetLastErrorStringA(
    LPSTR lpErrorString
)
{
    typedef int (__stdcall *Proc)(LPSTR lpErrorString);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetLastErrorStringA");
    return proc(lpErrorString);
}

int __stdcall C_GetLastErrorStringW(
    LPWSTR lpErrorString
)
{
    typedef int (__stdcall *Proc)(LPWSTR lpErrorString);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetLastErrorStringW");
    return proc(lpErrorString);
}

void __stdcall C_GetNodeArclengths(
    TOrcFxAPIHandle ObjectHandle,
    double *lpNodeArclengths,
    int *lpNodeCount,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, double *lpNodeArclengths, int *lpNodeCount, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetNodeArclengths");
    proc(ObjectHandle, lpNodeArclengths, lpNodeCount, lpStatus);
}

void __stdcall C_GetLineTypeHandles(
    TOrcFxAPIHandle ObjectHandle,
    int NodeNum,
    TOrcFxAPIHandle *lpInLineTypeHandle,
    TOrcFxAPIHandle *lpOutLineTypeHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, int NodeNum, TOrcFxAPIHandle *lpInLineTypeHandle, TOrcFxAPIHandle *lpOutLineTypeHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetLineTypeHandles");
    proc(ObjectHandle, NodeNum, lpInLineTypeHandle, lpOutLineTypeHandle, lpStatus);
}

void __stdcall C_GetModelHandle(
    TOrcFxAPIHandle ObjectHandle,
    TOrcFxAPIHandle *lpModelHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, TOrcFxAPIHandle *lpModelHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetModelHandle");
    proc(ObjectHandle, lpModelHandle, lpStatus);
}

int __stdcall C_GetModelThreadCount(
    TOrcFxAPIHandle ModelHandle,
    int *lpStatus
)
{
    typedef int (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetModelThreadCount");
    return proc(ModelHandle, lpStatus);
}

INT_PTR __stdcall C_GetNamedValueA(
    TOrcFxAPIHandle ObjectHandle,
    LPCSTR lpName,
    int *lpStatus
)
{
    typedef INT_PTR (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCSTR lpName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetNamedValueA");
    return proc(ObjectHandle, lpName, lpStatus);
}

INT_PTR __stdcall C_GetNamedValueW(
    TOrcFxAPIHandle ObjectHandle,
    LPCWSTR lpName,
    int *lpStatus
)
{
    typedef INT_PTR (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCWSTR lpName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetNamedValueW");
    return proc(ObjectHandle, lpName, lpStatus);
}

int __stdcall C_GetNumOfWarnings(
    TOrcFxAPIHandle ModelHandle,
    int *lpStatus
)
{
    typedef int (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetNumOfWarnings");
    return proc(ModelHandle, lpStatus);
}

int __stdcall C_GetObjectTypeA(
    TOrcFxAPIHandle ModelHandle,
    LPCSTR lpObjectTypeName,
    int *lpStatus
)
{
    typedef int (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, LPCSTR lpObjectTypeName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetObjectTypeA");
    return proc(ModelHandle, lpObjectTypeName, lpStatus);
}

int __stdcall C_GetObjectTypeW(
    TOrcFxAPIHandle ModelHandle,
    LPCWSTR lpObjectTypeName,
    int *lpStatus
)
{
    typedef int (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, LPCWSTR lpObjectTypeName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetObjectTypeW");
    return proc(ModelHandle, lpObjectTypeName, lpStatus);
}

void __stdcall C_GetObjectTypeFromHandle(
    TOrcFxAPIHandle ObjectHandle,
    int *lpObjectType,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, int *lpObjectType, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetObjectTypeFromHandle");
    proc(ObjectHandle, lpObjectType, lpStatus);
}

int __stdcall C_GetObjectTypeNameA(
    TOrcFxAPIHandle ModelHandle,
    int ObjectType,
    LPSTR lpObjectTypeName,
    int *lpStatus
)
{
    typedef int (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int ObjectType, LPSTR lpObjectTypeName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetObjectTypeNameA");
    return proc(ModelHandle, ObjectType, lpObjectTypeName, lpStatus);
}

int __stdcall C_GetObjectTypeNameW(
    TOrcFxAPIHandle ModelHandle,
    int ObjectType,
    LPWSTR lpObjectTypeName,
    int *lpStatus
)
{
    typedef int (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int ObjectType, LPWSTR lpObjectTypeName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetObjectTypeNameW");
    return proc(ModelHandle, ObjectType, lpObjectTypeName, lpStatus);
}

int __stdcall C_GetWarningTextA(
    TOrcFxAPIHandle ModelHandle,
    int Index,
    int *lpStage,
    LPCSTR lpWarningText,
    int *lpStatus
)
{
    typedef int (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int Index, int *lpStage, LPCSTR lpWarningText, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetWarningTextA");
    return proc(ModelHandle, Index, lpStage, lpWarningText, lpStatus);
}

int __stdcall C_GetWarningTextW(
    TOrcFxAPIHandle ModelHandle,
    int Index,
    int *lpStage,
    LPCWSTR lpWarningText,
    int *lpStatus
)
{
    typedef int (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int Index, int *lpStage, LPCWSTR lpWarningText, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetWarningTextW");
    return proc(ModelHandle, Index, lpStage, lpWarningText, lpStatus);
}

void __stdcall C_GroupGetFirstChild(
    TOrcFxAPIHandle ObjectHandle,
    TOrcFxAPIHandle *lpChildObjectHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, TOrcFxAPIHandle *lpChildObjectHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GroupGetFirstChild");
    proc(ObjectHandle, lpChildObjectHandle, lpStatus);
}

void __stdcall C_GroupGetNextSibling(
    TOrcFxAPIHandle ObjectHandle,
    TOrcFxAPIHandle *lpSiblingObjectHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, TOrcFxAPIHandle *lpSiblingObjectHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GroupGetNextSibling");
    proc(ObjectHandle, lpSiblingObjectHandle, lpStatus);
}

void __stdcall C_GroupGetParent(
    TOrcFxAPIHandle ObjectHandle,
    TOrcFxAPIHandle *lpParentObjectHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, TOrcFxAPIHandle *lpParentObjectHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GroupGetParent");
    proc(ObjectHandle, lpParentObjectHandle, lpStatus);
}

void __stdcall C_GroupGetPrevSibling(
    TOrcFxAPIHandle ObjectHandle,
    TOrcFxAPIHandle *lpSiblingObjectHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, TOrcFxAPIHandle *lpSiblingObjectHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GroupGetPrevSibling");
    proc(ObjectHandle, lpSiblingObjectHandle, lpStatus);
}

void __stdcall C_GroupMoveAfter(
    TOrcFxAPIHandle ObjectHandle,
    TOrcFxAPIHandle TargetObjectHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, TOrcFxAPIHandle TargetObjectHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GroupMoveAfter");
    proc(ObjectHandle, TargetObjectHandle, lpStatus);
}

void __stdcall C_GroupMoveBefore(
    TOrcFxAPIHandle ObjectHandle,
    TOrcFxAPIHandle TargetObjectHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, TOrcFxAPIHandle TargetObjectHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GroupMoveBefore");
    proc(ObjectHandle, TargetObjectHandle, lpStatus);
}

void __stdcall C_GroupSetParent(
    TOrcFxAPIHandle ObjectHandle,
    TOrcFxAPIHandle ParentObjectHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, TOrcFxAPIHandle ParentObjectHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GroupSetParent");
    proc(ObjectHandle, ParentObjectHandle, lpStatus);
}

void __stdcall C_LoadDataA(
    TOrcFxAPIHandle ModelHandle,
    LPCSTR lpDataFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, LPCSTR lpDataFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_LoadDataA");
    proc(ModelHandle, lpDataFileName, lpStatus);
}

void __stdcall C_LoadDataW(
    TOrcFxAPIHandle ModelHandle,
    LPCWSTR lpDataFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, LPCWSTR lpDataFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_LoadDataW");
    proc(ModelHandle, lpDataFileName, lpStatus);
}

void __stdcall C_LoadDataMem(
    TOrcFxAPIHandle ModelHandle,
    int DataFileType,
    const unsigned char *lpBuffer,
    int64_t BufferLen,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int DataFileType, const unsigned char *lpBuffer, int64_t BufferLen, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_LoadDataMem");
    proc(ModelHandle, DataFileType, lpBuffer, BufferLen, lpStatus);
}

void __stdcall C_LoadSimulationA(
    TOrcFxAPIHandle ModelHandle,
    LPCSTR lpSimFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, LPCSTR lpSimFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_LoadSimulationA");
    proc(ModelHandle, lpSimFileName, lpStatus);
}

void __stdcall C_LoadSimulationW(
    TOrcFxAPIHandle ModelHandle,
    LPCWSTR lpSimFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, LPCWSTR lpSimFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_LoadSimulationW");
    proc(ModelHandle, lpSimFileName, lpStatus);
}

void __stdcall C_LoadSimulationMem(
    TOrcFxAPIHandle ModelHandle,
    const unsigned char *lpBuffer,
    int64_t BufferLen,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, const unsigned char *lpBuffer, int64_t BufferLen, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_LoadSimulationMem");
    proc(ModelHandle, lpBuffer, BufferLen, lpStatus);
}

BOOL __stdcall C_ModuleEnabled(
    TOrcFxAPIHandle ModelHandle,
    int Module,
    int *lpStatus
)
{
    typedef BOOL (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int Module, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_ModuleEnabled");
    return proc(ModelHandle, Module, lpStatus);
}

void __stdcall C_MoveObjects(
    const TMoveObjectSpecification *lpSpecification,
    int PointCount,
    const TMoveObjectPoint *lpPoints,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(const TMoveObjectSpecification *lpSpecification, int PointCount, const TMoveObjectPoint *lpPoints, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_MoveObjects");
    proc(lpSpecification, PointCount, lpPoints, lpStatus);
}

void __stdcall C_ObjectCalledA(
    TOrcFxAPIHandle ModelHandle,
    LPCSTR lpObjectName,
    TObjectInfoA *lpObjectInfo,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, LPCSTR lpObjectName, TObjectInfoA *lpObjectInfo, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_ObjectCalledA");
    proc(ModelHandle, lpObjectName, lpObjectInfo, lpStatus);
}

void __stdcall C_ObjectCalledW(
    TOrcFxAPIHandle ModelHandle,
    LPCWSTR lpObjectName,
    TObjectInfoW *lpObjectInfo,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, LPCWSTR lpObjectName, TObjectInfoW *lpObjectInfo, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_ObjectCalledW");
    proc(ModelHandle, lpObjectName, lpObjectInfo, lpStatus);
}

void __stdcall C_RecordExternalFunctionErrorA(
    TExternalFunctionInfoA *lpExternalFunctionInfo,
    LPCSTR lpErrorString,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TExternalFunctionInfoA *lpExternalFunctionInfo, LPCSTR lpErrorString, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_RecordExternalFunctionErrorA");
    proc(lpExternalFunctionInfo, lpErrorString, lpStatus);
}

void __stdcall C_RecordExternalFunctionErrorW(
    TExternalFunctionInfoW *lpExternalFunctionInfo,
    LPCWSTR lpErrorString,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TExternalFunctionInfoW *lpExternalFunctionInfo, LPCWSTR lpErrorString, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_RecordExternalFunctionErrorW");
    proc(lpExternalFunctionInfo, lpErrorString, lpStatus);
}

void __stdcall C_RegisterLicenceNotFoundHandler(
    TLicenceNotFoundHandlerProc Handler,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TLicenceNotFoundHandlerProc Handler, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_RegisterLicenceNotFoundHandler");
    proc(Handler, lpStatus);
}

void __stdcall C_SaveDataA(
    TOrcFxAPIHandle ModelHandle,
    LPCSTR lpDataFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, LPCSTR lpDataFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveDataA");
    proc(ModelHandle, lpDataFileName, lpStatus);
}

void __stdcall C_SaveDataW(
    TOrcFxAPIHandle ModelHandle,
    LPCWSTR lpDataFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, LPCWSTR lpDataFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveDataW");
    proc(ModelHandle, lpDataFileName, lpStatus);
}

void __stdcall C_SaveDataMem(
    TOrcFxAPIHandle ModelHandle,
    int DataFileType,
    TOrcFxAPIHandle *lpBufferHandle,
    int64_t *lpBufferLen,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int DataFileType, TOrcFxAPIHandle *lpBufferHandle, int64_t *lpBufferLen, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveDataMem");
    proc(ModelHandle, DataFileType, lpBufferHandle, lpBufferLen, lpStatus);
}

void __stdcall C_SaveExternalProgramFileA(
    TOrcFxAPIHandle ObjectHandle,
    int FileType,
    void *lpParameters,
    LPCSTR lpFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, int FileType, void *lpParameters, LPCSTR lpFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveExternalProgramFileA");
    proc(ObjectHandle, FileType, lpParameters, lpFileName, lpStatus);
}

void __stdcall C_SaveExternalProgramFileW(
    TOrcFxAPIHandle ObjectHandle,
    int FileType,
    void *lpParameters,
    LPCWSTR lpFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, int FileType, void *lpParameters, LPCWSTR lpFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveExternalProgramFileW");
    proc(ObjectHandle, FileType, lpParameters, lpFileName, lpStatus);
}

void __stdcall C_SaveSimulationA(
    TOrcFxAPIHandle ModelHandle,
    LPCSTR lpSimFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, LPCSTR lpSimFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveSimulationA");
    proc(ModelHandle, lpSimFileName, lpStatus);
}

void __stdcall C_SaveSimulationW(
    TOrcFxAPIHandle ModelHandle,
    LPCWSTR lpSimFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, LPCWSTR lpSimFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveSimulationW");
    proc(ModelHandle, lpSimFileName, lpStatus);
}

void __stdcall C_SaveSimulationMem(
    TOrcFxAPIHandle ModelHandle,
    TOrcFxAPIHandle *lpBufferHandle,
    int64_t *lpBufferLen,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, TOrcFxAPIHandle *lpBufferHandle, int64_t *lpBufferLen, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveSimulationMem");
    proc(ModelHandle, lpBufferHandle, lpBufferLen, lpStatus);
}

void __stdcall C_SaveSpreadsheetA(
    TOrcFxAPIHandle ObjectHandle,
    int SpreadsheetType,
    void *lpParameters,
    LPCSTR lpFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, int SpreadsheetType, void *lpParameters, LPCSTR lpFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveSpreadsheetA");
    proc(ObjectHandle, SpreadsheetType, lpParameters, lpFileName, lpStatus);
}

void __stdcall C_SaveSpreadsheetW(
    TOrcFxAPIHandle ObjectHandle,
    int SpreadsheetType,
    void *lpParameters,
    LPCWSTR lpFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, int SpreadsheetType, void *lpParameters, LPCWSTR lpFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveSpreadsheetW");
    proc(ObjectHandle, SpreadsheetType, lpParameters, lpFileName, lpStatus);
}

void __stdcall C_SetCallerLong(
    TOrcFxAPIHandle ObjectHandle,
    INT_PTR CallerLong,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, INT_PTR CallerLong, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SetCallerLong");
    proc(ObjectHandle, CallerLong, lpStatus);
}

void __stdcall C_SetCorrectExternalFileReferencesHandler(
    TOrcFxAPIHandle ModelHandle,
    TCorrectExternalFileReferencesProc CorrectExternalFileReferencesProc,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, TCorrectExternalFileReferencesProc CorrectExternalFileReferencesProc, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SetCorrectExternalFileReferencesHandler");
    proc(ModelHandle, CorrectExternalFileReferencesProc, lpStatus);
}

void __stdcall C_SetModelThreadCount(
    TOrcFxAPIHandle ModelHandle,
    int ThreadCount,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int ThreadCount, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SetModelThreadCount");
    proc(ModelHandle, ThreadCount, lpStatus);
}

void __stdcall C_SetNamedValueA(
    TOrcFxAPIHandle ObjectHandle,
    LPCSTR lpName,
    INT_PTR Value,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCSTR lpName, INT_PTR Value, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SetNamedValueA");
    proc(ObjectHandle, lpName, Value, lpStatus);
}

void __stdcall C_SetNamedValueW(
    TOrcFxAPIHandle ObjectHandle,
    LPCWSTR lpName,
    INT_PTR Value,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCWSTR lpName, INT_PTR Value, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SetNamedValueW");
    proc(ObjectHandle, lpName, Value, lpStatus);
}

void __stdcall C_SetProgressHandler(
    TOrcFxAPIHandle ModelHandle,
    TProgressHandlerProc ProgressHandlerProc,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, TProgressHandlerProc ProgressHandlerProc, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SetProgressHandler");
    proc(ModelHandle, ProgressHandlerProc, lpStatus);
}

void __stdcall C_UseVirtualLogging(
    TOrcFxAPIHandle ModelHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_UseVirtualLogging");
    proc(ModelHandle, lpStatus);
}

double __stdcall OrcinaDefaultReal(
    void
)
{
    typedef double (__stdcall *Proc)(void);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "OrcinaDefaultReal");
    return proc();
}

double __stdcall OrcinaInfinity(
    void
)
{
    typedef double (__stdcall *Proc)(void);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "OrcinaInfinity");
    return proc();
}

double __stdcall OrcinaUndefinedReal(
    void
)
{
    typedef double (__stdcall *Proc)(void);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "OrcinaUndefinedReal");
    return proc();
}

double __stdcall OrcinaNullReal(
    void
)
{
    typedef double (__stdcall *Proc)(void);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "OrcinaNullReal");
    return proc();
}

void __stdcall C_BeginDataChange(
    TOrcFxAPIHandle ObjectHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_BeginDataChange");
    proc(ObjectHandle, lpStatus);
}

void __stdcall C_DeleteDataRowA(
    TOrcFxAPIHandle ObjectHandle,
    LPCSTR lpDataName,
    int Index,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCSTR lpDataName, int Index, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_DeleteDataRowA");
    proc(ObjectHandle, lpDataName, Index, lpStatus);
}

void __stdcall C_DeleteDataRowW(
    TOrcFxAPIHandle ObjectHandle,
    LPCWSTR lpDataName,
    int Index,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCWSTR lpDataName, int Index, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_DeleteDataRowW");
    proc(ObjectHandle, lpDataName, Index, lpStatus);
}

void __stdcall C_EndDataChange(
    TOrcFxAPIHandle ObjectHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_EndDataChange");
    proc(ObjectHandle, lpStatus);
}

void __stdcall C_GetDataDoubleA(
    TOrcFxAPIHandle ObjectHandle,
    LPCSTR lpDataName,
    int Index,
    double *lpData,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCSTR lpDataName, int Index, double *lpData, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetDataDoubleA");
    proc(ObjectHandle, lpDataName, Index, lpData, lpStatus);
}

void __stdcall C_GetDataDoubleW(
    TOrcFxAPIHandle ObjectHandle,
    LPCWSTR lpDataName,
    int Index,
    double *lpData,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCWSTR lpDataName, int Index, double *lpData, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetDataDoubleW");
    proc(ObjectHandle, lpDataName, Index, lpData, lpStatus);
}

void __stdcall C_GetDataIntegerA(
    TOrcFxAPIHandle ObjectHandle,
    LPCSTR lpDataName,
    int Index,
    int *lpData,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCSTR lpDataName, int Index, int *lpData, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetDataIntegerA");
    proc(ObjectHandle, lpDataName, Index, lpData, lpStatus);
}

void __stdcall C_GetDataIntegerW(
    TOrcFxAPIHandle ObjectHandle,
    LPCWSTR lpDataName,
    int Index,
    int *lpData,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCWSTR lpDataName, int Index, int *lpData, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetDataIntegerW");
    proc(ObjectHandle, lpDataName, Index, lpData, lpStatus);
}

void __stdcall C_GetDataRowCountA(
    TOrcFxAPIHandle ObjectHandle,
    LPCSTR lpDataName,
    int *lpRowCount,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCSTR lpDataName, int *lpRowCount, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetDataRowCountA");
    proc(ObjectHandle, lpDataName, lpRowCount, lpStatus);
}

void __stdcall C_GetDataRowCountW(
    TOrcFxAPIHandle ObjectHandle,
    LPCWSTR lpDataName,
    int *lpRowCount,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCWSTR lpDataName, int *lpRowCount, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetDataRowCountW");
    proc(ObjectHandle, lpDataName, lpRowCount, lpStatus);
}

int __stdcall C_GetDataStringA(
    TOrcFxAPIHandle ObjectHandle,
    LPCSTR lpDataName,
    int Index,
    LPSTR lpData,
    int *lpStatus
)
{
    typedef int (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCSTR lpDataName, int Index, LPSTR lpData, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetDataStringA");
    return proc(ObjectHandle, lpDataName, Index, lpData, lpStatus);
}

int __stdcall C_GetDataStringW(
    TOrcFxAPIHandle ObjectHandle,
    LPCWSTR lpDataName,
    int Index,
    LPWSTR lpData,
    int *lpStatus
)
{
    typedef int (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCWSTR lpDataName, int Index, LPWSTR lpData, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetDataStringW");
    return proc(ObjectHandle, lpDataName, Index, lpData, lpStatus);
}

void __stdcall C_GetDataTypeA(
    TOrcFxAPIHandle ObjectHandle,
    LPCSTR lpDataName,
    int *lpDataType,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCSTR lpDataName, int *lpDataType, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetDataTypeA");
    proc(ObjectHandle, lpDataName, lpDataType, lpStatus);
}

void __stdcall C_GetDataTypeW(
    TOrcFxAPIHandle ObjectHandle,
    LPCWSTR lpDataName,
    int *lpDataType,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCWSTR lpDataName, int *lpDataType, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetDataTypeW");
    proc(ObjectHandle, lpDataName, lpDataType, lpStatus);
}

void __stdcall C_GetVariableDataTypeA(
    TOrcFxAPIHandle ObjectHandle,
    LPCSTR lpDataName,
    int Index,
    int *lpDataType,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCSTR lpDataName, int Index, int *lpDataType, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetVariableDataTypeA");
    proc(ObjectHandle, lpDataName, Index, lpDataType, lpStatus);
}

void __stdcall C_GetVariableDataTypeW(
    TOrcFxAPIHandle ObjectHandle,
    LPCWSTR lpDataName,
    int Index,
    int *lpDataType,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCWSTR lpDataName, int Index, int *lpDataType, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetVariableDataTypeW");
    proc(ObjectHandle, lpDataName, Index, lpDataType, lpStatus);
}

void __stdcall C_InsertDataRowA(
    TOrcFxAPIHandle ObjectHandle,
    LPCSTR lpDataName,
    int Index,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCSTR lpDataName, int Index, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_InsertDataRowA");
    proc(ObjectHandle, lpDataName, Index, lpStatus);
}

void __stdcall C_InsertDataRowW(
    TOrcFxAPIHandle ObjectHandle,
    LPCWSTR lpDataName,
    int Index,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCWSTR lpDataName, int Index, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_InsertDataRowW");
    proc(ObjectHandle, lpDataName, Index, lpStatus);
}

void __stdcall C_InvokeLineSetupWizardA(
    TOrcFxAPIHandle ModelHandle,
    TStaticsProgressHandlerProcA StaticsProgressHandlerProc,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, TStaticsProgressHandlerProcA StaticsProgressHandlerProc, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_InvokeLineSetupWizardA");
    proc(ModelHandle, StaticsProgressHandlerProc, lpStatus);
}

void __stdcall C_InvokeLineSetupWizardW(
    TOrcFxAPIHandle ModelHandle,
    TStaticsProgressHandlerProcW StaticsProgressHandlerProc,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, TStaticsProgressHandlerProcW StaticsProgressHandlerProc, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_InvokeLineSetupWizardW");
    proc(ModelHandle, StaticsProgressHandlerProc, lpStatus);
}

void __stdcall C_InvokeWizard(
    TOrcFxAPIHandle ObjectHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_InvokeWizard");
    proc(ObjectHandle, lpStatus);
}

void __stdcall C_SetDataDoubleA(
    TOrcFxAPIHandle ObjectHandle,
    LPCSTR lpDataName,
    int Index,
    double Data,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCSTR lpDataName, int Index, double Data, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SetDataDoubleA");
    proc(ObjectHandle, lpDataName, Index, Data, lpStatus);
}

void __stdcall C_SetDataDoubleW(
    TOrcFxAPIHandle ObjectHandle,
    LPCWSTR lpDataName,
    int Index,
    double Data,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCWSTR lpDataName, int Index, double Data, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SetDataDoubleW");
    proc(ObjectHandle, lpDataName, Index, Data, lpStatus);
}

void __stdcall C_SetDataIntegerA(
    TOrcFxAPIHandle ObjectHandle,
    LPCSTR lpDataName,
    int Index,
    int Data,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCSTR lpDataName, int Index, int Data, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SetDataIntegerA");
    proc(ObjectHandle, lpDataName, Index, Data, lpStatus);
}

void __stdcall C_SetDataIntegerW(
    TOrcFxAPIHandle ObjectHandle,
    LPCWSTR lpDataName,
    int Index,
    int Data,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCWSTR lpDataName, int Index, int Data, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SetDataIntegerW");
    proc(ObjectHandle, lpDataName, Index, Data, lpStatus);
}

void __stdcall C_SetDataRowCountA(
    TOrcFxAPIHandle ObjectHandle,
    LPCSTR lpDataName,
    int RowCount,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCSTR lpDataName, int RowCount, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SetDataRowCountA");
    proc(ObjectHandle, lpDataName, RowCount, lpStatus);
}

void __stdcall C_SetDataRowCountW(
    TOrcFxAPIHandle ObjectHandle,
    LPCWSTR lpDataName,
    int RowCount,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCWSTR lpDataName, int RowCount, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SetDataRowCountW");
    proc(ObjectHandle, lpDataName, RowCount, lpStatus);
}

void __stdcall C_SetDataStringA(
    TOrcFxAPIHandle ObjectHandle,
    LPCSTR lpDataName,
    int Index,
    LPCSTR lpData,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCSTR lpDataName, int Index, LPCSTR lpData, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SetDataStringA");
    proc(ObjectHandle, lpDataName, Index, lpData, lpStatus);
}

void __stdcall C_SetDataStringW(
    TOrcFxAPIHandle ObjectHandle,
    LPCWSTR lpDataName,
    int Index,
    LPCWSTR lpData,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCWSTR lpDataName, int Index, LPCWSTR lpData, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SetDataStringW");
    proc(ObjectHandle, lpDataName, Index, lpData, lpStatus);
}

void __stdcall C_SetLineUserSpecifiedStartingShape(
    TOrcFxAPIHandle ObjectHandle,
    TVector *lpStartingShape,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, TVector *lpStartingShape, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SetLineUserSpecifiedStartingShape");
    proc(ObjectHandle, lpStartingShape, lpStatus);
}

void __stdcall C_AVIFileAddBitmap(
    TOrcFxAPIHandle AVIFileHandle,
    HBITMAP Bitmap,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle AVIFileHandle, HBITMAP Bitmap, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_AVIFileAddBitmap");
    proc(AVIFileHandle, Bitmap, lpStatus);
}

void __stdcall C_AVIFileFinalise(
    TOrcFxAPIHandle AVIFileHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle AVIFileHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_AVIFileFinalise");
    proc(AVIFileHandle, lpStatus);
}

void __stdcall C_AVIFileInitialiseA(
    TOrcFxAPIHandle *lpAVIFileHandle,
    LPCSTR lpAVIFileName,
    const TAVIFileParameters *lpAVIFileParameters,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle *lpAVIFileHandle, LPCSTR lpAVIFileName, const TAVIFileParameters *lpAVIFileParameters, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_AVIFileInitialiseA");
    proc(lpAVIFileHandle, lpAVIFileName, lpAVIFileParameters, lpStatus);
}

void __stdcall C_AVIFileInitialiseW(
    TOrcFxAPIHandle *lpAVIFileHandle,
    LPCWSTR lpAVIFileName,
    const TAVIFileParameters *lpAVIFileParameters,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle *lpAVIFileHandle, LPCWSTR lpAVIFileName, const TAVIFileParameters *lpAVIFileParameters, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_AVIFileInitialiseW");
    proc(lpAVIFileHandle, lpAVIFileName, lpAVIFileParameters, lpStatus);
}

void __stdcall C_CreateModel3DViewBitmap(
    TOrcFxAPIHandle ModelHandle,
    const TViewParameters *lpViewParameters,
    HBITMAP *lpBitmap,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, const TViewParameters *lpViewParameters, HBITMAP *lpBitmap, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CreateModel3DViewBitmap");
    proc(ModelHandle, lpViewParameters, lpBitmap, lpStatus);
}

void __stdcall C_GetDefaultViewParameters(
    TOrcFxAPIHandle ModelHandle,
    TViewParameters *lpViewParameters,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, TViewParameters *lpViewParameters, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetDefaultViewParameters");
    proc(ModelHandle, lpViewParameters, lpStatus);
}

double __stdcall C_GetSimulationDrawTime(
    TOrcFxAPIHandle ModelHandle,
    int *lpStatus
)
{
    typedef double (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetSimulationDrawTime");
    return proc(ModelHandle, lpStatus);
}

void __stdcall C_SaveModel3DViewBitmapToFileA(
    TOrcFxAPIHandle ModelHandle,
    const TViewParameters *lpViewParameters,
    LPCSTR lpFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, const TViewParameters *lpViewParameters, LPCSTR lpFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveModel3DViewBitmapToFileA");
    proc(ModelHandle, lpViewParameters, lpFileName, lpStatus);
}

void __stdcall C_SaveModel3DViewBitmapToFileW(
    TOrcFxAPIHandle ModelHandle,
    const TViewParameters *lpViewParameters,
    LPCWSTR lpFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, const TViewParameters *lpViewParameters, LPCWSTR lpFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveModel3DViewBitmapToFileW");
    proc(ModelHandle, lpViewParameters, lpFileName, lpStatus);
}

void __stdcall C_SetSimulationDrawTime(
    TOrcFxAPIHandle ModelHandle,
    double SimulationDrawTime,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, double SimulationDrawTime, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SetSimulationDrawTime");
    proc(ModelHandle, SimulationDrawTime, lpStatus);
}

void __stdcall C_CalculateMooringStiffness(
    int VesselCount,
    const TOrcFxAPIHandle *lpVessels,
    double *lpStiffness,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(int VesselCount, const TOrcFxAPIHandle *lpVessels, double *lpStiffness, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CalculateMooringStiffness");
    proc(VesselCount, lpVessels, lpStiffness, lpStatus);
}

void __stdcall C_CalculateStaticsA(
    TOrcFxAPIHandle ModelHandle,
    TStaticsProgressHandlerProcA StaticsProgressHandlerProc,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, TStaticsProgressHandlerProcA StaticsProgressHandlerProc, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CalculateStaticsA");
    proc(ModelHandle, StaticsProgressHandlerProc, lpStatus);
}

void __stdcall C_CalculateStaticsW(
    TOrcFxAPIHandle ModelHandle,
    TStaticsProgressHandlerProcW StaticsProgressHandlerProc,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, TStaticsProgressHandlerProcW StaticsProgressHandlerProc, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CalculateStaticsW");
    proc(ModelHandle, StaticsProgressHandlerProc, lpStatus);
}

void __stdcall C_CreateModes(
    TOrcFxAPIHandle ObjectHandle,
    const TModalAnalysisSpecification *lpSpecification,
    TOrcFxAPIHandle *lpModesHandle,
    int *lpDegreeOfFreedomCount,
    int *lpModeCount,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TModalAnalysisSpecification *lpSpecification, TOrcFxAPIHandle *lpModesHandle, int *lpDegreeOfFreedomCount, int *lpModeCount, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CreateModes");
    proc(ObjectHandle, lpSpecification, lpModesHandle, lpDegreeOfFreedomCount, lpModeCount, lpStatus);
}

void __stdcall C_DestroyModes(
    TOrcFxAPIHandle ModesHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModesHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_DestroyModes");
    proc(ModesHandle, lpStatus);
}

void __stdcall C_ExtendSimulation(
    TOrcFxAPIHandle ModelHandle,
    double Time,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, double Time, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_ExtendSimulation");
    proc(ModelHandle, Time, lpStatus);
}

void __stdcall C_GetDefaultSolveEquationParameters(
    TSolveEquationParameters *lpSolveEquationParameters,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TSolveEquationParameters *lpSolveEquationParameters, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetDefaultSolveEquationParameters");
    proc(lpSolveEquationParameters, lpStatus);
}

void __stdcall C_GetDefaultUseCalculatedPositionsForStaticsParameters(
    TUseCalculatedPositionsForStaticsParameters *lpUseCalculatedPositionsForStaticsParameters,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TUseCalculatedPositionsForStaticsParameters *lpUseCalculatedPositionsForStaticsParameters, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetDefaultUseCalculatedPositionsForStaticsParameters");
    proc(lpUseCalculatedPositionsForStaticsParameters, lpStatus);
}

void __stdcall C_GetModeDegreeOfFreedomDetails(
    TOrcFxAPIHandle ModesHandle,
    int *lpNodeNumbers,
    int *lpDOFs,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModesHandle, int *lpNodeNumbers, int *lpDOFs, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetModeDegreeOfFreedomDetails");
    proc(ModesHandle, lpNodeNumbers, lpDOFs, lpStatus);
}

void __stdcall C_GetModeDegreeOfFreedomOwners(
    TOrcFxAPIHandle ModesHandle,
    TOrcFxAPIHandle *lpOwners,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModesHandle, TOrcFxAPIHandle *lpOwners, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetModeDegreeOfFreedomOwners");
    proc(ModesHandle, lpOwners, lpStatus);
}

void __stdcall C_GetModeDetails(
    TOrcFxAPIHandle ModesHandle,
    int Index,
    TModeDetails *lpDetails,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModesHandle, int Index, TModeDetails *lpDetails, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetModeDetails");
    proc(ModesHandle, Index, lpDetails, lpStatus);
}

void __stdcall C_GetModeLoad(
    TOrcFxAPIHandle ModesHandle,
    int Index,
    TModeLoad *lpLoad,
    int *lpStatus
    )
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModesHandle, int Index, TModeLoad *lpLoad, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetModeLoad");
    proc(ModesHandle, Index, lpLoad, lpStatus);
}

void __stdcall C_GetModeLoadOutputPoints(
    TOrcFxAPIHandle ModesHandle,
    int *lpOutputPointCount,
    TModeLoadOutputPoint *lpLoadOutputPoints,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModesHandle, int *lpOutputPointCount, TModeLoadOutputPoint *lpLoadOutputPoints, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetModeLoadOutputPoints");
    proc(ModesHandle, lpOutputPointCount, lpLoadOutputPoints, lpStatus);
}

void __stdcall C_GetModelProperty(
    TOrcFxAPIHandle ObjectHandle,
    int PropertyId,
    void *lpValue,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, int PropertyId, void *lpValue, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetModelProperty");
    proc(ObjectHandle, PropertyId, lpValue, lpStatus);
}

void __stdcall C_GetModelState(
    TOrcFxAPIHandle ModelHandle,
    int *lpModelState,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int *lpModelState, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetModelState");
    proc(ModelHandle, lpModelState, lpStatus);
}

void __stdcall C_GetModeSummary(
    TOrcFxAPIHandle ModesHandle,
    int *lpNumbers,
    double *lpPeriods,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModesHandle, int *lpNumbers, double *lpPeriods, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetModeSummary");
    proc(ModesHandle, lpNumbers, lpPeriods, lpStatus);
}

void __stdcall C_GetRecommendedTimeSteps(
    TOrcFxAPIHandle ModelHandle,
    TTimeSteps *lpTimeSteps,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, TTimeSteps *lpTimeSteps, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetRecommendedTimeSteps");
    proc(ModelHandle, lpTimeSteps, lpStatus);
}

void __stdcall C_GetSimulationComplete(
    TOrcFxAPIHandle ModelHandle,
    BOOL *lpSimulationComplete,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, BOOL *lpSimulationComplete, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetSimulationComplete");
    proc(ModelHandle, lpSimulationComplete, lpStatus);
}

void __stdcall C_GetSimulationTimeStatus(
    TOrcFxAPIHandle ModelHandle,
    TSimulationTimeStatus *lpSimulationTimeStatus,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, TSimulationTimeStatus *lpSimulationTimeStatus, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetSimulationTimeStatus");
    proc(ModelHandle, lpSimulationTimeStatus, lpStatus);
}

double __stdcall C_GetSimulationTimeToGo(
    TOrcFxAPIHandle ModelHandle,
    int *lpStatus
)
{
    typedef double (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetSimulationTimeToGo");
    return proc(ModelHandle, lpStatus);
}

void __stdcall C_PauseSimulation(
    TOrcFxAPIHandle ModelHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_PauseSimulation");
    proc(ModelHandle, lpStatus);
}

void __stdcall C_ProcessBatchScriptA(
    TOrcFxAPIHandle ModelHandle,
    LPCSTR lpBatchScriptFileName,
    TStringProgressHandlerProcA BatchScriptProgressHandlerProc,
    TStaticsProgressHandlerProcA StaticsProgressHandlerProc,
    TDynamicsProgressHandlerProc DynamicsProgressHandlerProc,
    const TRunSimulationParametersA *lpRunSimulationParameters,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, LPCSTR lpBatchScriptFileName, TStringProgressHandlerProcA BatchScriptProgressHandlerProc, TStaticsProgressHandlerProcA StaticsProgressHandlerProc, TDynamicsProgressHandlerProc DynamicsProgressHandlerProc, const TRunSimulationParametersA *lpRunSimulationParameters, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_ProcessBatchScriptA");
    proc(ModelHandle, lpBatchScriptFileName, BatchScriptProgressHandlerProc, StaticsProgressHandlerProc, DynamicsProgressHandlerProc, lpRunSimulationParameters, lpStatus);
}

void __stdcall C_ProcessBatchScriptW(
    TOrcFxAPIHandle ModelHandle,
    LPCWSTR lpBatchScriptFileName,
    TStringProgressHandlerProcW BatchScriptProgressHandlerProc,
    TStaticsProgressHandlerProcW StaticsProgressHandlerProc,
    TDynamicsProgressHandlerProc DynamicsProgressHandlerProc,
    const TRunSimulationParametersW *lpRunSimulationParameters,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, LPCWSTR lpBatchScriptFileName, TStringProgressHandlerProcW BatchScriptProgressHandlerProc, TStaticsProgressHandlerProcW StaticsProgressHandlerProc, TDynamicsProgressHandlerProc DynamicsProgressHandlerProc, const TRunSimulationParametersW *lpRunSimulationParameters, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_ProcessBatchScriptW");
    proc(ModelHandle, lpBatchScriptFileName, BatchScriptProgressHandlerProc, StaticsProgressHandlerProc, DynamicsProgressHandlerProc, lpRunSimulationParameters, lpStatus);
}

void __stdcall C_ResetModel(
    TOrcFxAPIHandle ModelHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_ResetModel");
    proc(ModelHandle, lpStatus);
}

void __stdcall C_RunSimulation(
    TOrcFxAPIHandle ModelHandle,
    TDynamicsProgressHandlerProc DynamicsProgressHandlerProc,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, TDynamicsProgressHandlerProc DynamicsProgressHandlerProc, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_RunSimulation");
    proc(ModelHandle, DynamicsProgressHandlerProc, lpStatus);
}

void __stdcall C_RunSimulation2A(
    TOrcFxAPIHandle ModelHandle,
    TDynamicsProgressHandlerProc DynamicsProgressHandlerProc,
    const TRunSimulationParametersA *lpRunSimulationParameters,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, TDynamicsProgressHandlerProc DynamicsProgressHandlerProc, const TRunSimulationParametersA *lpRunSimulationParameters, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_RunSimulation2A");
    proc(ModelHandle, DynamicsProgressHandlerProc, lpRunSimulationParameters, lpStatus);
}

void __stdcall C_RunSimulation2W(
    TOrcFxAPIHandle ModelHandle,
    TDynamicsProgressHandlerProc DynamicsProgressHandlerProc,
    const TRunSimulationParametersW *lpRunSimulationParameters,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, TDynamicsProgressHandlerProc DynamicsProgressHandlerProc, const TRunSimulationParametersW *lpRunSimulationParameters, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_RunSimulation2W");
    proc(ModelHandle, DynamicsProgressHandlerProc, lpRunSimulationParameters, lpStatus);
}

void __stdcall C_SolveEquation(
    INT_PTR Data,
    TSolveEquationCalcYProc SolveEquationCalcYProc,
    double *lpX,
    double TargetY,
    const TSolveEquationParameters *lpSolveEquationParameters,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(INT_PTR Data, TSolveEquationCalcYProc SolveEquationCalcYProc, double *lpX, double TargetY, const TSolveEquationParameters *lpSolveEquationParameters, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SolveEquation");
    proc(Data, SolveEquationCalcYProc, lpX, TargetY, lpSolveEquationParameters, lpStatus);
}

void __stdcall C_UseCalculatedPositionsForStatics(
    TOrcFxAPIHandle ModelHandle,
    const TUseCalculatedPositionsForStaticsParameters *lpUseCalculatedPositionsForStaticsParameters,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, const TUseCalculatedPositionsForStaticsParameters *lpUseCalculatedPositionsForStaticsParameters, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_UseCalculatedPositionsForStatics");
    proc(ModelHandle, lpUseCalculatedPositionsForStaticsParameters, lpStatus);
}

void __stdcall C_AnalyseExtrema(
    double *lpValues,
    int Count,
    double *lpMaximum,
    double *lpMinimum,
    int *lpIndexOfMaximum,
    int *lpIndexOfMinimum,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(double *lpValues, int Count, double *lpMaximum, double *lpMinimum, int *lpIndexOfMaximum, int *lpIndexOfMinimum, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_AnalyseExtrema");
    proc(lpValues, Count, lpMaximum, lpMinimum, lpIndexOfMaximum, lpIndexOfMinimum, lpStatus);
}

int __stdcall C_CalculateExtremeStatisticsExcessesOverThreshold(
    TOrcFxAPIHandle ExtremeStatisticsHandle,
    const TExtremeStatisticsSpecification *lpSpecification,
    double *lpExcesses,
    int *lpStatus
)
{
    typedef int (__stdcall *Proc)(TOrcFxAPIHandle ExtremeStatisticsHandle, const TExtremeStatisticsSpecification *lpSpecification, double *lpExcesses, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CalculateExtremeStatisticsExcessesOverThreshold");
    return proc(ExtremeStatisticsHandle, lpSpecification, lpExcesses, lpStatus);
}

void __stdcall C_CalculateFatigueA(
    TOrcFxAPIHandle FatigueHandle,
    LPCSTR lpResultsFileName,
    TStringProgressHandlerProc FatigueProgressHandlerProc,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle FatigueHandle, LPCSTR lpResultsFileName, TStringProgressHandlerProc FatigueProgressHandlerProc, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CalculateFatigueA");
    proc(FatigueHandle, lpResultsFileName, FatigueProgressHandlerProc, lpStatus);
}

void __stdcall C_CalculateFatigueW(
    TOrcFxAPIHandle FatigueHandle,
    LPCWSTR lpResultsFileName,
    TStringProgressHandlerProc FatigueProgressHandlerProc,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle FatigueHandle, LPCWSTR lpResultsFileName, TStringProgressHandlerProc FatigueProgressHandlerProc, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CalculateFatigueW");
    proc(FatigueHandle, lpResultsFileName, FatigueProgressHandlerProc, lpStatus);
}

void __stdcall C_CalculateRratio(
    int CycleCount,
    const double *lpRange,
    const double *lpAssociatedMean,
    double *lpRratio,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(int CycleCount, const double *lpRange, const double *lpAssociatedMean, double *lpRratio, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CalculateRratio");
    proc(CycleCount, lpRange, lpAssociatedMean, lpRratio, lpStatus);
}

void __stdcall C_CalculateLinkedStatisticsTimeSeriesStatistics(
    TOrcFxAPIHandle StatisticsHandle,
    int VarID,
    TTimeSeriesStatistics *lpStatistics,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle StatisticsHandle, int VarID, TTimeSeriesStatistics *lpStatistics, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CalculateLinkedStatisticsTimeSeriesStatistics");
    proc(StatisticsHandle, VarID, lpStatistics, lpStatus);
}

void __stdcall C_CalculateTimeSeriesStatistics(
    double *lpValues,
    int Count,
    double SampleInterval,
    TTimeSeriesStatistics *lpStatistics,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(double *lpValues, int Count, double SampleInterval, TTimeSeriesStatistics *lpStatistics, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CalculateTimeSeriesStatistics");
    proc(lpValues, Count, SampleInterval, lpStatistics, lpStatus);
}

void __stdcall C_CloseExtremeStatistics(
    TOrcFxAPIHandle ExtremeStatisticsHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ExtremeStatisticsHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CloseExtremeStatistics");
    proc(ExtremeStatisticsHandle, lpStatus);
}

void __stdcall C_CloseLinkedStatistics(
    TOrcFxAPIHandle StatisticsHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle StatisticsHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CloseLinkedStatistics");
    proc(StatisticsHandle, lpStatus);
}

void __stdcall C_CreateCycleHistogramBins(
    int HalfCycleCount,
    double *lpHalfCycleRanges,
    double BinSize,
    int *lpBinCount,
    TCycleBin **lpBins,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(int HalfCycleCount, double *lpHalfCycleRanges, double BinSize, int *lpBinCount, TCycleBin **lpBins, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CreateCycleHistogramBins");
    proc(HalfCycleCount, lpHalfCycleRanges, BinSize, lpBinCount, lpBins, lpStatus);
}

void __stdcall C_CreateFatigue(
    TOrcFxAPIHandle *lpFatigueHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle *lpFatigueHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CreateFatigue");
    proc(lpFatigueHandle, lpStatus);
}

void __stdcall C_CreateTimeHistorySummary(
    int TimeHistorySummaryType,
    int NumOfSamples,
    double *lpTimes,
    double *lpValues,
    TOrcFxAPIHandle *lpTimeHistorySummaryHandle,
    int *lpNumOfSummaryValues,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(int TimeHistorySummaryType, int NumOfSamples, double *lpTimes, double *lpValues, TOrcFxAPIHandle *lpTimeHistorySummaryHandle, int *lpNumOfSummaryValues, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CreateTimeHistorySummary");
    proc(TimeHistorySummaryType, NumOfSamples, lpTimes, lpValues, lpTimeHistorySummaryHandle, lpNumOfSummaryValues, lpStatus);
}

void __stdcall C_CreateTimeHistorySummary2(
    int TimeHistorySummaryType,
    int NumOfSamples,
    const TTimeHistorySummarySpecification *lpSpecification,
    double *lpTimes,
    double *lpValues,
    TOrcFxAPIHandle *lpTimeHistorySummaryHandle,
    int *lpNumOfSummaryValues,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(int TimeHistorySummaryType, int NumOfSamples, const TTimeHistorySummarySpecification *lpSpecification, double *lpTimes, double *lpValues, TOrcFxAPIHandle *lpTimeHistorySummaryHandle, int *lpNumOfSummaryValues, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CreateTimeHistorySummary2");
    proc(TimeHistorySummaryType, NumOfSamples, lpSpecification, lpTimes, lpValues, lpTimeHistorySummaryHandle, lpNumOfSummaryValues, lpStatus);
}

void __stdcall C_CreateWaveScatter(
    TOrcFxAPIHandle *lpWaveScatterHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle *lpWaveScatterHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_CreateWaveScatter");
    proc(lpWaveScatterHandle, lpStatus);
}

void __stdcall C_DestroyCycleHistogramBins(
    TCycleBin *lpBins,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TCycleBin *lpBins, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_DestroyCycleHistogramBins");
    proc(lpBins, lpStatus);
}

void __stdcall C_DestroyFatigue(
    TOrcFxAPIHandle FatigueHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle FatigueHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_DestroyFatigue");
    proc(FatigueHandle, lpStatus);
}

void __stdcall C_DestroyTimeHistorySummary(
    TOrcFxAPIHandle TimeHistorySummaryHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle TimeHistorySummaryHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_DestroyTimeHistorySummary");
    proc(TimeHistorySummaryHandle, lpStatus);
}

void __stdcall C_DestroyWaveScatter(
    TOrcFxAPIHandle WaveScatterHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle WaveScatterHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_DestroyWaveScatter");
    proc(WaveScatterHandle, lpStatus);
}

void __stdcall C_EnumerateVarsA(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra *lpObjectExtra,
    int ResultType,
    TEnumerateVarsProcA EnumerateVarsProc,
    int *lpNumberOfVars,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra *lpObjectExtra, int ResultType, TEnumerateVarsProcA EnumerateVarsProc, int *lpNumberOfVars, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_EnumerateVarsA");
    proc(ObjectHandle, lpObjectExtra, ResultType, EnumerateVarsProc, lpNumberOfVars, lpStatus);
}

void __stdcall C_EnumerateVarsW(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra *lpObjectExtra,
    int ResultType,
    TEnumerateVarsProcW EnumerateVarsProc,
    int *lpNumberOfVars,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra *lpObjectExtra, int ResultType, TEnumerateVarsProcW EnumerateVarsProc, int *lpNumberOfVars, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_EnumerateVarsW");
    proc(ObjectHandle, lpObjectExtra, ResultType, EnumerateVarsProc, lpNumberOfVars, lpStatus);
}

void __stdcall C_EnumerateVars2A(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2A *lpObjectExtra,
    int ResultType,
    TEnumerateVarsProcA EnumerateVarsProc,
    int *lpNumberOfVars,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2A *lpObjectExtra, int ResultType, TEnumerateVarsProcA EnumerateVarsProc, int *lpNumberOfVars, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_EnumerateVars2A");
    proc(ObjectHandle, lpObjectExtra, ResultType, EnumerateVarsProc, lpNumberOfVars, lpStatus);
}

void __stdcall C_EnumerateVars2W(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2W *lpObjectExtra,
    int ResultType,
    TEnumerateVarsProcW EnumerateVarsProc,
    int *lpNumberOfVars,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2W *lpObjectExtra, int ResultType, TEnumerateVarsProcW EnumerateVarsProc, int *lpNumberOfVars, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_EnumerateVars2W");
    proc(ObjectHandle, lpObjectExtra, ResultType, EnumerateVarsProc, lpNumberOfVars, lpStatus);
}

void __stdcall C_FitExtremeStatistics(
    TOrcFxAPIHandle ExtremeStatisticsHandle,
    const TExtremeStatisticsSpecification *lpSpecification,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ExtremeStatisticsHandle, const TExtremeStatisticsSpecification *lpSpecification, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_FitExtremeStatistics");
    proc(ExtremeStatisticsHandle, lpSpecification, lpStatus);
}

void __stdcall C_GetFrequencyDomainMPM(
    const double StormDuration,
    const double StdDev,
    const double Tz,
    double *lpValue,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(const double StormDuration, const double StdDev, const double Tz, double *lpValue, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFrequencyDomainMPM");
    proc(StormDuration, StdDev, Tz, lpValue, lpStatus);
}

void __stdcall C_GetFrequencyDomainProcessComponents(
    TOrcFxAPIHandle ModelHandle,
    int *lpCount,
    TFrequencyDomainProcessComponent *lpFrequencyDomainProcessComponents,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int *lpCount, TFrequencyDomainProcessComponent *lpFrequencyDomainProcessComponents, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFrequencyDomainProcessComponents");
    proc(ModelHandle, lpCount, lpFrequencyDomainProcessComponents, lpStatus);
}

void __stdcall C_GetFrequencyDomainProcessComponents2(
    TOrcFxAPIHandle ModelHandle,
    int *lpCount,
    TFrequencyDomainProcessComponent2 *lpFrequencyDomainProcessComponents,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int *lpCount, TFrequencyDomainProcessComponent2 *lpFrequencyDomainProcessComponents, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFrequencyDomainProcessComponents2");
    proc(ModelHandle, lpCount, lpFrequencyDomainProcessComponents, lpStatus);
}

void __stdcall C_GetFrequencyDomainResultsA(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2A *lpObjectExtra,
    int VarID,
    TFrequencyDomainResults *lpValue,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2A *lpObjectExtra, int VarID, TFrequencyDomainResults *lpValue, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFrequencyDomainResultsA");
    proc(ObjectHandle, lpObjectExtra, VarID, lpValue, lpStatus);
}

void __stdcall C_GetFrequencyDomainResultsW(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2W *lpObjectExtra,
    int VarID,
    TFrequencyDomainResults *lpValue,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2W *lpObjectExtra, int VarID, TFrequencyDomainResults *lpValue, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFrequencyDomainResultsW");
    proc(ObjectHandle, lpObjectExtra, VarID, lpValue, lpStatus);
}

void __stdcall C_GetFrequencyDomainResultsProcessA(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2A *lpObjectExtra,
    int VarID,
    int *lpComponentCount,
    TComplex *lpProcess,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2A *lpObjectExtra, int VarID, int *lpComponentCount, TComplex *lpProcess, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFrequencyDomainResultsProcessA");
    proc(ObjectHandle, lpObjectExtra, VarID, lpComponentCount, lpProcess, lpStatus);
}

void __stdcall C_GetFrequencyDomainResultsProcessW(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2W *lpObjectExtra,
    int VarID,
    int *lpComponentCount,
    TComplex *lpProcess,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2W *lpObjectExtra, int VarID, int *lpComponentCount, TComplex *lpProcess, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFrequencyDomainResultsProcessW");
    proc(ObjectHandle, lpObjectExtra, VarID, lpComponentCount, lpProcess, lpStatus);
}

void __stdcall C_GetFrequencyDomainSpectralDensityGraphA(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2A *lpObjectExtra,
    int VarID,
    int *lpNumOfGraphPoints,
    TGraphCurve *lpGraph,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2A *lpObjectExtra, int VarID, int *lpNumOfGraphPoints, TGraphCurve *lpGraph, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFrequencyDomainSpectralDensityGraphA");
    proc(ObjectHandle, lpObjectExtra, VarID, lpNumOfGraphPoints, lpGraph, lpStatus);
}

void __stdcall C_GetFrequencyDomainSpectralDensityGraphW(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2W *lpObjectExtra,
    int VarID,
    int *lpNumOfGraphPoints,
    TGraphCurve *lpGraph,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2W *lpObjectExtra, int VarID, int *lpNumOfGraphPoints, TGraphCurve *lpGraph, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFrequencyDomainSpectralDensityGraphW");
    proc(ObjectHandle, lpObjectExtra, VarID, lpNumOfGraphPoints, lpGraph, lpStatus);
}

void __stdcall C_GetFrequencyDomainResultsFromProcess(
    TOrcFxAPIHandle ModelHandle,
    int ComponentCount,
    const TComplex *lpProcess,
    TFrequencyDomainResults *lpValue,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int ComponentCount, const TComplex *lpProcess, TFrequencyDomainResults *lpValue, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFrequencyDomainResultsFromProcess");
    proc(ModelHandle, ComponentCount, lpProcess, lpValue, lpStatus);
}

void __stdcall C_GetFrequencyDomainSpectralDensityGraphFromProcess(
    TOrcFxAPIHandle ModelHandle,
    int ComponentCount,
    const TComplex *lpProcess,
    int *lpNumOfGraphPoints,
    TGraphCurve *lpGraph,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int ComponentCount, const TComplex *lpProcess, int *lpNumOfGraphPoints, TGraphCurve *lpGraph, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFrequencyDomainSpectralDensityGraphFromProcess");
    proc(ModelHandle, ComponentCount, lpProcess, lpNumOfGraphPoints, lpGraph, lpStatus);
}

void __stdcall C_GetFrequencyDomainSpectralResponseGraphFromProcess(
    TOrcFxAPIHandle ModelHandle,
    int ComponentCount,
    const TComplex *lpProcess,
    int *lpNumOfGraphPoints,
    TGraphCurve *lpGraph,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int ComponentCount, const TComplex *lpProcess, int *lpNumOfGraphPoints, TGraphCurve *lpGraph, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFrequencyDomainSpectralResponseGraphFromProcess");
    proc(ModelHandle, ComponentCount, lpProcess, lpNumOfGraphPoints, lpGraph, lpStatus);
}

void __stdcall C_GetFrequencyDomainTimeHistoryFromProcess(
    TOrcFxAPIHandle ModelHandle,
    int ComponentCount,
    const TComplex *lpProcess,
    double FromTime,
    double SampleInterval,
    int SampleCount,
    double *lpValues,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int ComponentCount, const TComplex *lpProcess, double FromTime, double SampleInterval, int SampleCount, double *lpValues, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFrequencyDomainTimeHistoryFromProcess");
    proc(ModelHandle, ComponentCount, lpProcess, FromTime, SampleInterval, SampleCount, lpValues, lpStatus);
}

void __stdcall C_GetFrequencyDomainTimeHistorySampleCount(
    double FromTime,
    double ToTime,
    double SampleInterval,
    int *lpSampleCount,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(double FromTime, double ToTime, double SampleInterval, int *lpSampleCount, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFrequencyDomainTimeHistorySampleCount");
    proc(FromTime, ToTime, SampleInterval, lpSampleCount, lpStatus);
}

void __stdcall C_GetFrequencyDomainTimeHistorySampleTimes(
    double FromTime,
    double SampleInterval,
    int SampleCount,
    double *lpTimes,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(double FromTime, double SampleInterval, int SampleCount, double *lpTimes, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetFrequencyDomainTimeHistorySampleTimes");
    proc(FromTime, SampleInterval, SampleCount, lpTimes, lpStatus);
}

int __stdcall C_GetNumOfSamples(
    TOrcFxAPIHandle ModelHandle,
    const TPeriod *lpPeriod,
    int *lpStatus
)
{
    typedef int (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, const TPeriod *lpPeriod, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetNumOfSamples");
    return proc(ModelHandle, lpPeriod, lpStatus);
}

void __stdcall C_GetRangeGraph(
    TOrcFxAPIHandle ObjectHandle,
    int VarID,
    const TPeriod *lpPeriod,
    double *lpXValues,
    double *lpMinValues,
    double *lpMaxValues,
    double *lpMeanValues,
    double *lpUpperValues,
    double *lpLowerValues,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, int VarID, const TPeriod *lpPeriod, double *lpXValues, double *lpMinValues, double *lpMaxValues, double *lpMeanValues, double *lpUpperValues, double *lpLowerValues, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetRangeGraph");
    proc(ObjectHandle, VarID, lpPeriod, lpXValues, lpMinValues, lpMaxValues, lpMeanValues, lpUpperValues, lpLowerValues, lpStatus);
}

void __stdcall C_GetRangeGraph2(
    TOrcFxAPIHandle ObjectHandle,
    int VarID,
    const TPeriod *lpPeriod,
    double *lpXValues,
    double *lpMinValues,
    double *lpMaxValues,
    double *lpMeanValues,
    double *lpStdDevValues,
    double *lpUpperValues,
    double *lpLowerValues,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, int VarID, const TPeriod *lpPeriod, double *lpXValues, double *lpMinValues, double *lpMaxValues, double *lpMeanValues, double *lpStdDevValues, double *lpUpperValues, double *lpLowerValues, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetRangeGraph2");
    proc(ObjectHandle, VarID, lpPeriod, lpXValues, lpMinValues, lpMaxValues, lpMeanValues, lpStdDevValues, lpUpperValues, lpLowerValues, lpStatus);
}

void __stdcall C_GetRangeGraph3A(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2A *lpObjectExtra,
    const TPeriod *lpPeriod,
    int VarID,
    double *lpXValues,
    double *lpMinValues,
    double *lpMaxValues,
    double *lpMeanValues,
    double *lpStdDevValues,
    double *lpUpperValues,
    double *lpLowerValues,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2A *lpObjectExtra, const TPeriod *lpPeriod, int VarID, double *lpXValues, double *lpMinValues, double *lpMaxValues, double *lpMeanValues, double *lpStdDevValues, double *lpUpperValues, double *lpLowerValues, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetRangeGraph3A");
    proc(ObjectHandle, lpObjectExtra, lpPeriod, VarID, lpXValues, lpMinValues, lpMaxValues, lpMeanValues, lpStdDevValues, lpUpperValues, lpLowerValues, lpStatus);
}

void __stdcall C_GetRangeGraph3W(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2W *lpObjectExtra,
    const TPeriod *lpPeriod,
    int VarID,
    double *lpXValues,
    double *lpMinValues,
    double *lpMaxValues,
    double *lpMeanValues,
    double *lpStdDevValues,
    double *lpUpperValues,
    double *lpLowerValues,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2W *lpObjectExtra, const TPeriod *lpPeriod, int VarID, double *lpXValues, double *lpMinValues, double *lpMaxValues, double *lpMeanValues, double *lpStdDevValues, double *lpUpperValues, double *lpLowerValues, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetRangeGraph3W");
    proc(ObjectHandle, lpObjectExtra, lpPeriod, VarID, lpXValues, lpMinValues, lpMaxValues, lpMeanValues, lpStdDevValues, lpUpperValues, lpLowerValues, lpStatus);
}

void __stdcall C_GetRangeGraph4A(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2A *lpObjectExtra,
    const TPeriod *lpPeriod,
    const TArclengthRange *lpArclengthRange,
    int VarID,
    double *lpXValues,
    double *lpMinValues,
    double *lpMaxValues,
    double *lpMeanValues,
    double *lpStdDevValues,
    double *lpUpperValues,
    double *lpLowerValues,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2A *lpObjectExtra, const TPeriod *lpPeriod, const TArclengthRange *lpArclengthRange, int VarID, double *lpXValues, double *lpMinValues, double *lpMaxValues, double *lpMeanValues, double *lpStdDevValues, double *lpUpperValues, double *lpLowerValues, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetRangeGraph4A");
    proc(ObjectHandle, lpObjectExtra, lpPeriod, lpArclengthRange, VarID, lpXValues, lpMinValues, lpMaxValues, lpMeanValues, lpStdDevValues, lpUpperValues, lpLowerValues, lpStatus);
}

void __stdcall C_GetRangeGraph4W(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2W *lpObjectExtra,
    const TPeriod *lpPeriod,
    const TArclengthRange *lpArclengthRange,
    int VarID,
    double *lpXValues,
    double *lpMinValues,
    double *lpMaxValues,
    double *lpMeanValues,
    double *lpStdDevValues,
    double *lpUpperValues,
    double *lpLowerValues,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2W *lpObjectExtra, const TPeriod *lpPeriod, const TArclengthRange *lpArclengthRange, int VarID, double *lpXValues, double *lpMinValues, double *lpMaxValues, double *lpMeanValues, double *lpStdDevValues, double *lpUpperValues, double *lpLowerValues, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetRangeGraph4W");
    proc(ObjectHandle, lpObjectExtra, lpPeriod, lpArclengthRange, VarID, lpXValues, lpMinValues, lpMaxValues, lpMeanValues, lpStdDevValues, lpUpperValues, lpLowerValues, lpStatus);
}

void __stdcall C_GetRangeGraphCurveNamesA(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2A *lpObjectExtra,
    const TPeriod *lpPeriod,
    int VarID,
    TRangeGraphCurveNamesA *lpCurveNames,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2A *lpObjectExtra, const TPeriod *lpPeriod, int VarID, TRangeGraphCurveNamesA *lpCurveNames, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetRangeGraphCurveNamesA");
    proc(ObjectHandle, lpObjectExtra, lpPeriod, VarID, lpCurveNames, lpStatus);
}

void __stdcall C_GetRangeGraphCurveNamesW(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2W *lpObjectExtra,
    const TPeriod *lpPeriod,
    int VarID,
    TRangeGraphCurveNamesW *lpCurveNames,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2W *lpObjectExtra, const TPeriod *lpPeriod, int VarID, TRangeGraphCurveNamesW *lpCurveNames, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetRangeGraphCurveNamesW");
    proc(ObjectHandle, lpObjectExtra, lpPeriod, VarID, lpCurveNames, lpStatus);
}

int __stdcall C_GetRangeGraphNumOfPoints(
    TOrcFxAPIHandle ObjectHandle,
    int VarID,
    int *lpStatus
)
{
    typedef int (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, int VarID, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetRangeGraphNumOfPoints");
    return proc(ObjectHandle, VarID, lpStatus);
}

int __stdcall C_GetRangeGraphNumOfPoints2(
    TOrcFxAPIHandle ObjectHandle,
    const TArclengthRange *lpArclengthRange,
    int VarID,
    int *lpStatus
)
{
    typedef int (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TArclengthRange *lpArclengthRange, int VarID, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetRangeGraphNumOfPoints2");
    return proc(ObjectHandle, lpArclengthRange, VarID, lpStatus);
}

void __stdcall C_GetSampleTimes(
    TOrcFxAPIHandle ModelHandle,
    const TPeriod *lpPeriod,
    double *lpTimes,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, const TPeriod *lpPeriod, double *lpTimes, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetSampleTimes");
    proc(ModelHandle, lpPeriod, lpTimes, lpStatus);
}

void __stdcall C_GetSpectralResponseGraphA(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2A *lpObjectExtra,
    int VarID,
    int *lpNumOfGraphPoints,
    TGraphCurve *lpGraph,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2A *lpObjectExtra, int VarID, int *lpNumOfGraphPoints, TGraphCurve *lpGraph, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetSpectralResponseGraphA");
    proc(ObjectHandle, lpObjectExtra, VarID, lpNumOfGraphPoints, lpGraph, lpStatus);
}

void __stdcall C_GetSpectralResponseGraphW(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2W *lpObjectExtra,
    int VarID,
    int *lpNumOfGraphPoints,
    TGraphCurve *lpGraph,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2W *lpObjectExtra, int VarID, int *lpNumOfGraphPoints, TGraphCurve *lpGraph, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetSpectralResponseGraphW");
    proc(ObjectHandle, lpObjectExtra, VarID, lpNumOfGraphPoints, lpGraph, lpStatus);
}

void __stdcall C_GetStaticResult(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra *lpObjectExtra,
    int VarID,
    double *lpValue,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra *lpObjectExtra, int VarID, double *lpValue, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetStaticResult");
    proc(ObjectHandle, lpObjectExtra, VarID, lpValue, lpStatus);
}

void __stdcall C_GetStaticResult2A(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2A *lpObjectExtra,
    int VarID,
    double *lpValue,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2A *lpObjectExtra, int VarID, double *lpValue, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetStaticResult2A");
    proc(ObjectHandle, lpObjectExtra, VarID, lpValue, lpStatus);
}

void __stdcall C_GetStaticResult2W(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2W *lpObjectExtra,
    int VarID,
    double *lpValue,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2W *lpObjectExtra, int VarID, double *lpValue, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetStaticResult2W");
    proc(ObjectHandle, lpObjectExtra, VarID, lpValue, lpStatus);
}

void __stdcall C_GetTimeHistory(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra *lpObjectExtra,
    const TPeriod *lpPeriod,
    int VarID,
    double *lpValues,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra *lpObjectExtra, const TPeriod *lpPeriod, int VarID, double *lpValues, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetTimeHistory");
    proc(ObjectHandle, lpObjectExtra, lpPeriod, VarID, lpValues, lpStatus);
}

void __stdcall C_GetTimeHistory2A(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2A *lpObjectExtra,
    const TPeriod *lpPeriod,
    int VarID,
    double *lpValues,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2A *lpObjectExtra, const TPeriod *lpPeriod, int VarID, double *lpValues, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetTimeHistory2A");
    proc(ObjectHandle, lpObjectExtra, lpPeriod, VarID, lpValues, lpStatus);
}

void __stdcall C_GetTimeHistory2W(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2W *lpObjectExtra,
    const TPeriod *lpPeriod,
    int VarID,
    double *lpValues,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2W *lpObjectExtra, const TPeriod *lpPeriod, int VarID, double *lpValues, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetTimeHistory2W");
    proc(ObjectHandle, lpObjectExtra, lpPeriod, VarID, lpValues, lpStatus);
}

void __stdcall C_GetTimeHistorySummaryValues(
    TOrcFxAPIHandle TimeHistorySummaryHandle,
    double *lpX,
    double *lpY,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle TimeHistorySummaryHandle, double *lpX, double *lpY, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetTimeHistorySummaryValues");
    proc(TimeHistorySummaryHandle, lpX, lpY, lpStatus);
}

void __stdcall C_GetVarIDA(
    TOrcFxAPIHandle ObjectHandle,
    LPCSTR lpVarName,
    int *lpVarID,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCSTR lpVarName, int *lpVarID, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetVarIDA");
    proc(ObjectHandle, lpVarName, lpVarID, lpStatus);
}

void __stdcall C_GetVarIDW(
    TOrcFxAPIHandle ObjectHandle,
    LPCWSTR lpVarName,
    int *lpVarID,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, LPCWSTR lpVarName, int *lpVarID, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetVarIDW");
    proc(ObjectHandle, lpVarName, lpVarID, lpStatus);
}

void __stdcall C_GetWaveComponents(
    TOrcFxAPIHandle ModelHandle,
    int *lpCount,
    TWaveComponent *lpWaveComponents,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int *lpCount, TWaveComponent *lpWaveComponents, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetWaveComponents");
    proc(ModelHandle, lpCount, lpWaveComponents, lpStatus);
}

void __stdcall C_GetWaveComponents2(
    TOrcFxAPIHandle ModelHandle,
    int *lpCount,
    TWaveComponent2 *lpWaveComponents,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int *lpCount, TWaveComponent2 *lpWaveComponents, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetWaveComponents2");
    proc(ModelHandle, lpCount, lpWaveComponents, lpStatus);
}

void __stdcall C_GetWaveScatterTable(
    TOrcFxAPIHandle WaveScatterHandle,
    TWaveScatterBin *lpTbins,
    TWaveScatterBin *lpHbins,
    double *lpOccurrences,
    double *lpTotalProbability,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle WaveScatterHandle, TWaveScatterBin *lpTbins, TWaveScatterBin *lpHbins, double *lpOccurrences, double *lpTotalProbability, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetWaveScatterTable");
    proc(WaveScatterHandle, lpTbins, lpHbins, lpOccurrences, lpTotalProbability, lpStatus);
}

void __stdcall C_GetWindComponents(
    TOrcFxAPIHandle ModelHandle,
    int *lpCount,
    TWindComponent *lpWindComponents,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ModelHandle, int *lpCount, TWindComponent *lpWindComponents, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_GetWindComponents");
    proc(ModelHandle, lpCount, lpWindComponents, lpStatus);
}

void __stdcall C_LoadFatigueA(
    TOrcFxAPIHandle FatigueHandle,
    LPCSTR lpFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle FatigueHandle, LPCSTR lpFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_LoadFatigueA");
    proc(FatigueHandle, lpFileName, lpStatus);
}

void __stdcall C_LoadFatigueW(
    TOrcFxAPIHandle FatigueHandle,
    LPCWSTR lpFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle FatigueHandle, LPCWSTR lpFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_LoadFatigueW");
    proc(FatigueHandle, lpFileName, lpStatus);
}

void __stdcall C_LoadFatigueMem(
    TOrcFxAPIHandle FatigueHandle,
    int DataFileType,
    const unsigned char *lpBuffer,
    int64_t BufferLen,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle FatigueHandle, int DataFileType, const unsigned char *lpBuffer, int64_t BufferLen, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_LoadFatigueMem");
    proc(FatigueHandle, DataFileType, lpBuffer, BufferLen, lpStatus);
}

void __stdcall C_LoadWaveScatterA(
    TOrcFxAPIHandle WaveScatterHandle,
    LPCSTR lpFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle WaveScatterHandle, LPCSTR lpFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_LoadWaveScatterA");
    proc(WaveScatterHandle, lpFileName, lpStatus);
}

void __stdcall C_LoadWaveScatterW(
    TOrcFxAPIHandle WaveScatterHandle,
    LPCWSTR lpFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle WaveScatterHandle, LPCWSTR lpFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_LoadWaveScatterW");
    proc(WaveScatterHandle, lpFileName, lpStatus);
}

void __stdcall C_LoadWaveScatterMem(
    TOrcFxAPIHandle WaveScatterHandle,
    int DataFileType,
    const unsigned char *lpBuffer,
    int64_t BufferLen,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle WaveScatterHandle, int DataFileType, const unsigned char *lpBuffer, int64_t BufferLen, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_LoadWaveScatterMem");
    proc(WaveScatterHandle, DataFileType, lpBuffer, BufferLen, lpStatus);
}

void __stdcall C_OpenExtremeStatistics(
    int NumberOfValues,
    double *lpValues,
    double SampleInterval,
    TOrcFxAPIHandle *lpExtremeStatisticsHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(int NumberOfValues, double *lpValues, double SampleInterval, TOrcFxAPIHandle *lpExtremeStatisticsHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_OpenExtremeStatistics");
    proc(NumberOfValues, lpValues, SampleInterval, lpExtremeStatisticsHandle, lpStatus);
}

void __stdcall C_OpenLinkedStatistics(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra *lpObjectExtra,
    const TPeriod *lpPeriod,
    int NumOfVars,
    int *lpVars,
    TOrcFxAPIHandle *lpStatisticsHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra *lpObjectExtra, const TPeriod *lpPeriod, int NumOfVars, int *lpVars, TOrcFxAPIHandle *lpStatisticsHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_OpenLinkedStatistics");
    proc(ObjectHandle, lpObjectExtra, lpPeriod, NumOfVars, lpVars, lpStatisticsHandle, lpStatus);
}

void __stdcall C_OpenLinkedStatistics2A(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2A *lpObjectExtra,
    const TPeriod *lpPeriod,
    int NumOfVars,
    int *lpVars,
    TOrcFxAPIHandle *lpStatisticsHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2A *lpObjectExtra, const TPeriod *lpPeriod, int NumOfVars, int *lpVars, TOrcFxAPIHandle *lpStatisticsHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_OpenLinkedStatistics2A");
    proc(ObjectHandle, lpObjectExtra, lpPeriod, NumOfVars, lpVars, lpStatisticsHandle, lpStatus);
}

void __stdcall C_OpenLinkedStatistics2W(
    TOrcFxAPIHandle ObjectHandle,
    const TObjectExtra2W *lpObjectExtra,
    const TPeriod *lpPeriod,
    int NumOfVars,
    int *lpVars,
    TOrcFxAPIHandle *lpStatisticsHandle,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ObjectHandle, const TObjectExtra2W *lpObjectExtra, const TPeriod *lpPeriod, int NumOfVars, int *lpVars, TOrcFxAPIHandle *lpStatisticsHandle, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_OpenLinkedStatistics2W");
    proc(ObjectHandle, lpObjectExtra, lpPeriod, NumOfVars, lpVars, lpStatisticsHandle, lpStatus);
}

void __stdcall C_QueryExtremeStatistics(
    TOrcFxAPIHandle ExtremeStatisticsHandle,
    const TExtremeStatisticsQuery *lpQuery,
    TExtremeStatisticsOutput *lpOutput,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ExtremeStatisticsHandle, const TExtremeStatisticsQuery *lpQuery, TExtremeStatisticsOutput *lpOutput, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_QueryExtremeStatistics");
    proc(ExtremeStatisticsHandle, lpQuery, lpOutput, lpStatus);
}

void __stdcall C_QueryLinkedStatistics(
    TOrcFxAPIHandle StatisticsHandle,
    int VarID,
    int LinkedVarID,
    TStatisticsQuery *lpStatisticsQuery,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle StatisticsHandle, int VarID, int LinkedVarID, TStatisticsQuery *lpStatisticsQuery, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_QueryLinkedStatistics");
    proc(StatisticsHandle, VarID, LinkedVarID, lpStatisticsQuery, lpStatus);
}

void __stdcall C_RegisterExternalFunctionResultA(
    TExtFnInfoA *lpExtFnInfo,
    TExtFnResultInfoA *lpResultInfo,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TExtFnInfoA *lpExtFnInfo, TExtFnResultInfoA *lpResultInfo, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_RegisterExternalFunctionResultA");
    proc(lpExtFnInfo, lpResultInfo, lpStatus);
}

void __stdcall C_RegisterExternalFunctionResultW(
    TExtFnInfoW *lpExtFnInfo,
    TExtFnResultInfoW *lpResultInfo,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TExtFnInfoW *lpExtFnInfo, TExtFnResultInfoW *lpResultInfo, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_RegisterExternalFunctionResultW");
    proc(lpExtFnInfo, lpResultInfo, lpStatus);
}

void __stdcall C_SaveFatigueA(
    TOrcFxAPIHandle FatigueHandle,
    LPCSTR lpFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle FatigueHandle, LPCSTR lpFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveFatigueA");
    proc(FatigueHandle, lpFileName, lpStatus);
}

void __stdcall C_SaveFatigueW(
    TOrcFxAPIHandle FatigueHandle,
    LPCWSTR lpFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle FatigueHandle, LPCWSTR lpFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveFatigueW");
    proc(FatigueHandle, lpFileName, lpStatus);
}

void __stdcall C_SaveFatigueMem(
    TOrcFxAPIHandle FatigueHandle,
    int DataFileType,
    TOrcFxAPIHandle *lpBufferHandle,
    int64_t *lpBufferLen,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle FatigueHandle, int DataFileType, TOrcFxAPIHandle *lpBufferHandle, int64_t *lpBufferLen, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveFatigueMem");
    proc(FatigueHandle, DataFileType, lpBufferHandle, lpBufferLen, lpStatus);
}

void __stdcall C_SaveWaveScatterA(
    TOrcFxAPIHandle WaveScatterHandle,
    LPCSTR lpFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle WaveScatterHandle, LPCSTR lpFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveWaveScatterA");
    proc(WaveScatterHandle, lpFileName, lpStatus);
}

void __stdcall C_SaveWaveScatterW(
    TOrcFxAPIHandle WaveScatterHandle,
    LPCWSTR lpFileName,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle WaveScatterHandle, LPCWSTR lpFileName, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveWaveScatterW");
    proc(WaveScatterHandle, lpFileName, lpStatus);
}

void __stdcall C_SaveWaveScatterMem(
    TOrcFxAPIHandle WaveScatterHandle,
    int DataFileType,
    TOrcFxAPIHandle *lpBufferHandle,
    int64_t *lpBufferLen,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle WaveScatterHandle, int DataFileType, TOrcFxAPIHandle *lpBufferHandle, int64_t *lpBufferLen, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveWaveScatterMem");
    proc(WaveScatterHandle, DataFileType, lpBufferHandle, lpBufferLen, lpStatus);
}

void __stdcall C_SaveWaveScatterAutomationFilesA(
    TOrcFxAPIHandle WaveScatterHandle,
    const TWaveScatterAutomationSpecificationA *lpSpecification,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle WaveScatterHandle, const TWaveScatterAutomationSpecificationA *lpSpecification, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveWaveScatterAutomationFilesA");
    proc(WaveScatterHandle, lpSpecification, lpStatus);
}

void __stdcall C_SaveWaveScatterAutomationFilesW(
    TOrcFxAPIHandle WaveScatterHandle,
    const TWaveScatterAutomationSpecificationW *lpSpecification,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle WaveScatterHandle, const TWaveScatterAutomationSpecificationW *lpSpecification, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SaveWaveScatterAutomationFilesW");
    proc(WaveScatterHandle, lpSpecification, lpStatus);
}

void __stdcall C_SimulateToleranceIntervals(
    TOrcFxAPIHandle ExtremeStatisticsHandle,
    int SimulatedDataSetCount,
    TInterval *lpToleranceIntervals,
    int *lpStatus
)
{
    typedef void (__stdcall *Proc)(TOrcFxAPIHandle ExtremeStatisticsHandle, int SimulatedDataSetCount, TInterval *lpToleranceIntervals, int *lpStatus);
    static Proc proc = NULL;
    if (proc == NULL)
        proc = (Proc)GetProcAddress(_Module, "C_SimulateToleranceIntervals");
    proc(ExtremeStatisticsHandle, SimulatedDataSetCount, lpToleranceIntervals, lpStatus);
}

