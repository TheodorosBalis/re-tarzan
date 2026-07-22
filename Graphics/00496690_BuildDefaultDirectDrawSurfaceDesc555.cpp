#include "tarzan_ghidra_types.hpp"

// Address: 0x00496690
// Label: BuildDefaultDirectDrawSurfaceDesc555
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int BuildDefaultDirectDrawSurfaceDesc555(void)

{
  int value;
  undefined4 *dataCursor;
  
  dataCursor = &g_DefaultDirectDrawSurfaceDesc555_Field0000;
  for (value = 0x1b; value != 0; value = value + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  g_DefaultDirectDrawSurfaceDesc555_Field0000 = 0x6c;
  _g_DefaultDirectDrawSurfaceDesc555_Field000C = 0x100;
  _g_DefaultDirectDrawSurfaceDesc555_Field0008 = 0x100;
  g_DefaultDirectDrawSurfaceDesc555_Field0004 = 0x1007;
  _g_DefaultDirectDrawSurfaceDesc555_Field0068 = 0x4005000;
  _g_DefaultDirectDrawSurfaceDesc555_Field0018 = 1;
  _g_DefaultDirectDrawSurfaceDesc555_Field0048 = 0x20;
  _g_DefaultDirectDrawSurfaceDesc555_Field004C = 0x41;
  _g_DefaultDirectDrawSurfaceDesc555_Field0054 = 0x10;
  _g_DefaultDirectDrawSurfaceDesc555_Field0064 = 0x8000;
  _g_DefaultDirectDrawSurfaceDesc555_Field0058 = 0x7c00;
  _g_DefaultDirectDrawSurfaceDesc555_Field005C = 0x3e0;
  _g_DefaultDirectDrawSurfaceDesc555_Field0060 = 0x1f;
  return 0;
}

