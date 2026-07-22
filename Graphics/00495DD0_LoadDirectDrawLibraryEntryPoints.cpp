#include "tarzan_ghidra_types.hpp"

// Address: 0x00495DD0
// Label: LoadDirectDrawLibraryEntryPoints
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool LoadDirectDrawLibraryEntryPoints(void)

{
  g_DirectDrawLibraryHandle = LoadLibraryA(s_ddraw_dll);
  if (g_DirectDrawLibraryHandle == (HMODULE)0x0) {
    return false;
  }
  g_DirectDrawCreateProc = GetProcAddress(g_DirectDrawLibraryHandle,s_DirectDrawCreate);
  if (g_DirectDrawCreateProc == (FARPROC)0x0) {
    return false;
  }
  g_DirectDrawEnumerateAProc =
       GetProcAddress(g_DirectDrawLibraryHandle,s_DirectDrawEnumerateA_005157f0);
  return g_DirectDrawEnumerateAProc != (FARPROC)0x0;
}

