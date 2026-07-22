#include "tarzan_ghidra_types.hpp"

// Address: 0x004AE330
// Label: InternalError
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InternalError(LPCSTR arg1)

{
  int value2;
  BOOL value;
  tagMSG localState;
  
  if (g_InternalErrorActive != 0) {
    ExitIfFailed2();
  }
  g_InternalErrorActive = 1;
  ForceSoftwareGraphicsMode();
  if (arg1 != (LPCSTR)0x0) {
    value2 = VerifyGraphicsMode();
    if (value2 == 0) {
      value2 = 0;
      do {
        value = PeekMessageA(&localState,(HWND)0x0,0,0,1);
        if (value == 0) break;
        value2 = value2 + 1;
      } while (value2 < 1000);
      MessageBoxA(mainWindowHandle,arg1,s_Tarzan_Action_Game___Internal_Er_00518e24,0x10);
    }
  }
  ExitIfFailed2();
  return;
}

