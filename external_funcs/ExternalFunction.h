#include <string>
#include <sstream>
#include <vector>
#include "OrcFxAPI.h"

using namespace std;
using namespace Orcina;

// See ExternalFunction.cpp for documentation for these functions and classes.
class CExternalFunctionException : private wstring
{
public:
  CExternalFunctionException(const wstring &Message) : wstring(Message){
  };
  wstring Message() const {
    return *this;
  };
};

void ThrowError(const wstring &Message);
void ThrowError(LPCWSTR Message);
bool StatusOK(int Status);
int GetResultVarID(TOrcFxAPIHandle ObjectHandle, LPCWSTR ResultName);
void ReportError(TExtFnInfo &ExtFnInfo, LPCWSTR Message);
bool SameText(LPCWSTR pString1, LPCWSTR pString2);
bool SameText(LPCWSTR pString1, LPCWSTR pString2, size_t count);
bool operator ==(TVector2 V1, TVector2 V2);
bool operator !=(TVector2 V1, TVector2 V2);
void RegisterResult(TExtFnInfo *lpExtFnInfo, int ResultID, LPCTSTR Name, LPCTSTR Units);

class CParams : private wstring
{
public:
  CParams(LPCWSTR Params);
  wstring GetValueOf(LPCWSTR Name, LPCWSTR Default=L"") const;
  template <typename T> T GetValueOf(LPCWSTR Name, T DefaultValue) const
  {
    T Result=DefaultValue;
    wstring Value=GetValueOf(Name);
    if(!Value.empty()) {
      if((wistringstream(Value)>>Result).fail())
        ThrowError(wstring(L"Unable to interpret the value for ")+Name+L".");
    }
    return Result;
  };
private:
  wstring Trim(const wstring &s) const;
};

// See ExternalFunction.cpp for documentation of this class.
class CTable
{
public:
  CTable(LPCWSTR Parameters, LPCWSTR XName, LPCWSTR YName);
  int Count() const {
    return (int)m_data.size();
  };
  double X(int Index) const {
    return m_data[Index].X;
  };
  double Y(int Index) const {
    return m_data[Index].Y;
  };
  double YAtX(double X) const;
  TVector2 operator[](int Index) const {
    return m_data[Index];
  };
  bool MonotoneIncreasing() const;
private:
  vector<TVector2> m_data;
  vector<double> Values(CParams Params, LPCWSTR Name);
};

// Used to ensure that an OrcFxAPI structure contains the required parameter. If the last
// item we require is pStructure->pLastParameterRequired then this macro will generate an
// error if the structure is not long enough to contain this item. The length required is
// calculated by subtracting the address of the start of the structure and the address of
// the member we require plus the length of that member.
#define StructureContains(Structure, pLastParameterRequired) \
  ((unsigned int)(Structure).Size>=(BYTE*)&(Structure).pLastParameterRequired- \
   (BYTE*)(&Structure)+ \
   sizeof((Structure).pLastParameterRequired))

#define CheckStructureContains(Structure, pLastParameterRequired) \
  { \
    if(!StructureContains(Structure, pLastParameterRequired))                                                                                                                                                                                                                                                                                                                                     \
      ThrowError(L"The structure is to small to contain the entry required - this external function a later version of OrcaFlex.");                                                                                                                                                                                                                                                                                     \
  }


// Macro used to handle exceptions in a generic way.  It also ensures that any errors generated
// during reporting of an error do not escape from the DLL. It is very important that exceptions
// do not "escape" as OrcaFlex is unlikely to understand the format of your exceptions, possibly
// causing fatal errors.
#define EXTERNAL_FUNCTIONS_TRY try

#define EXTERNAL_FUNCTIONS_CATCH(ExtFnInfo) \
  catch(CExternalFunctionException *pException) \
  {   \
    ReportError((ExtFnInfo), pException->Message().c_str()); \
    delete pException; \
  } \
  catch(...) \
  { \
    try \
    { \
      ReportError((ExtFnInfo), L"An unexpected error occured"); \
    } \
    catch(...) \
    { \
    } \
  }
