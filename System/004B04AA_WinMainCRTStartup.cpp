#include "tarzan_ghidra_types.hpp"

// Address: 0x004B04AA
// Label: WinMainCRTStartup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WinMainCRTStartup(void)

{
  DWORD apiResult;
  int value;
  undefined4 value2;
  uint value3;
  HMODULE value5;
  undefined4 value4;
  _STARTUPINFOA localState3;
  undefined1 *localState2;
  undefined4 *localState;
  void *localState7;
  code *localState5;
  undefined *localState6;
  undefined4 localState4;
  
  localState4 = 0xffffffff;
  localState6 = &DAT_004ba4e8;
  localState5 = (code *)(undefined4 (__cdecl *)(...))_except_handler3;
  localState7 = ExceptionList;
  localState2 = &stack0xffffff88;
  ExceptionList = &localState7;
  apiResult = GetVersion();
  dwMinorVersion = apiResult >> 8 & 0xff;
  dwMajorVersion = apiResult & 0xff;
  dwMajor__8_minor = dwMajorVersion * 0x100 + dwMinorVersion;
  dwbuild = apiResult >> 0x10;
  value = _heap_init(1);
  if (value == 0) {
    FastRuntimeErrorExit(0x1c);
  }
  value = _mtinit();
  if (value == 0) {
    FastRuntimeErrorExit(0x10);
  }
  localState4 = 0;
  _ioinit();
  EXEfilePath = GetCommandLineA();
  g_CrtRawEnvironmentStrings = __crtGetEnvironmentStringsA();
  _setargv();
  _setenvp();
  _cinit();
  localState3.dwFlags = 0;
  GetStartupInfoA(&localState3);
  value2 = _wincmdln();
  if ((localState3.dwFlags & 1) == 0) {
    value3 = 10;
  }
  else {
    value3 = (uint)localState3.wShowWindow;
  }
  value4 = 0;
  value5 = GetModuleHandleA((LPCSTR)0x0);
  value2 = Main(value5,(HANDLE)value4,(LPSTR)value2,(int)value3);
  exit(value2);
  _XcptFilter(*(undefined4 *)*localState,localState);
  return;
}

