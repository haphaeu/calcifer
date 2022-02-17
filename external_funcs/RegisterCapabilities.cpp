#include <windows.h>
#include "OrcFxAPI.h"

extern "C"
{
// Added by Rafael
//void __stdcall RegisterCapabilities(LPDWORD lpCapabilities)
void __declspec(dllexport) RegisterCapabilities(LPDWORD lpCapabilities)
{
  *lpCapabilities = *lpCapabilities | efcUnicode | efcImplicitIntegration;
}
}