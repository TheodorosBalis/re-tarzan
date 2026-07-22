#include "tarzan_ghidra_types.hpp"

// Address: 0x004B79A3
// Label: __crtMessageBoxA
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int __crtMessageBoxA(undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  HMODULE hModule;
  int value;
  
  value = 0;
  if (g_CrtMessageBoxAProc == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      g_CrtMessageBoxAProc = GetProcAddress(hModule,"MessageBoxA");
      if (g_CrtMessageBoxAProc != (FARPROC)0x0) {
        g_CrtGetActiveWindowProc = GetProcAddress(hModule,"GetActiveWindow");
        g_CrtGetLastActivePopupProc = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_004b79f2;
      }
    }
    value = 0;
  }
  else {
LAB_004b79f2:
    if (g_CrtGetActiveWindowProc != (FARPROC)0x0) {
      value = (*g_CrtGetActiveWindowProc)();
      if ((value != 0) && (g_CrtGetLastActivePopupProc != (FARPROC)0x0)) {
        value = (*g_CrtGetLastActivePopupProc)(value);
      }
    }
    value = (*g_CrtMessageBoxAProc)(value,arg1,arg2,arg3);
  }
  return value;
}

