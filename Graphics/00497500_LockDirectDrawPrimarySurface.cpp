#include "tarzan_ghidra_types.hpp"

// Address: 0x00497500
// Label: LockDirectDrawPrimarySurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 LockDirectDrawPrimarySurface(uint arg1,undefined4 *arg2,undefined4 *arg3)

{
  uint value2;
  int value;
  undefined4 *dataCursor;
  undefined4 scratchRect3 [4];
  undefined4 scratchRect5;
  undefined4 scratchRect4;
  undefined4 scratchRect2 [20];
  uint scratchRect;
  
  if ((((g_DirectDrawGraphicsModeInitialized != 0) && (g_DirectDrawPrimarySurfaceLocked == 0)) &&
      (arg2 != (undefined4 *)0x0)) && (arg3 != (undefined4 *)0x0)) {
    *arg3 = 0;
    *arg2 = 0;
    if (arg1 != 0xffffffff) {
      dataCursor = scratchRect2;
      for (value = 0x19; value != 0; value = value + -1) {
        *dataCursor = 0;
        dataCursor = dataCursor + 1;
      }
      scratchRect2[0] = 100;
      if (g_DirectDrawBackBufferIsRgb565 == 0) {
        value2 = (arg1 >> 3 & 0x1f0000 | arg1 & 0xf800) >> 3;
      }
      else {
        value2 = (arg1 >> 3 & 0x1f0000 | arg1 & 0xfc00) >> 2;
      }
      _g_DirectDrawColorFillValue = (value2 | arg1 & 0xf8) >> 3;
      scratchRect = (value2 | arg1 & 0xf8) >> 3;
      if (g_DirectDrawBackBufferSurface != (int *)0x0) {
        g_DirectDrawLastResult =
             (**(code **)(*g_DirectDrawBackBufferSurface + 0x14))
                       (g_DirectDrawBackBufferSurface,0,0,0,0x1000400,scratchRect2);
      }
    }
    dataCursor = scratchRect3;
    for (value = 0x1b; value != 0; value = value + -1) {
      *dataCursor = 0;
      dataCursor = dataCursor + 1;
    }
    scratchRect3[0] = 0x6c;
    if (g_DirectDrawBackBufferSurface != (int *)0x0) {
      g_DirectDrawLastResult =
           (**(code **)(*g_DirectDrawBackBufferSurface + 100))
                     (g_DirectDrawBackBufferSurface,0,scratchRect3,1,0);
    }
    if (g_DirectDrawLastResult == 0) {
      g_DirectDrawPrimarySurfaceLocked = 1;
      *arg3 = scratchRect5;
      *arg2 = scratchRect4;
      return 1;
    }
  }
  return 0;
}

