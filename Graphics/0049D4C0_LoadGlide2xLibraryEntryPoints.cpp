#include "tarzan_ghidra_types.hpp"

// Address: 0x0049D4C0
// Label: LoadGlide2xLibraryEntryPoints
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 LoadGlide2xLibraryEntryPoints(void)

{
  FARPROC value;
  undefined **dataCursor;
  
  if ((g_GlideTextureMemoryBase != (HMODULE)0x0) ||
     (g_GlideTextureMemoryBase = LoadLibraryA(s_glide2x_dll_0051620c),
     g_GlideTextureMemoryBase != (HMODULE)0x0)) {
    dataCursor = &PTR_g_GlideAlphaBlendFunctionProc_00515e38;
    while( true ) {
      value = GetProcAddress(g_GlideTextureMemoryBase,dataCursor[1]);
      *(FARPROC *)*dataCursor = value;
      if (*(int *)*dataCursor == 0) break;
      dataCursor = dataCursor + 2;
      if (0x515f47 < (int)dataCursor) {
        return 1;
      }
    }
  }
  return 0;
}

