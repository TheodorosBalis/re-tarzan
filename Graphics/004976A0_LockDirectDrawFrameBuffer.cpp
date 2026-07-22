#include "tarzan_ghidra_types.hpp"

// Address: 0x004976A0
// Label: LockDirectDrawFrameBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
LockDirectDrawFrameBuffer
          (undefined4 graphicsObject,undefined4 *source2,undefined4 *dest,undefined4 *flags)

{
  undefined4 value;
  
  if ((((g_DirectDrawGraphicsModeInitialized != 0) && (g_DirectDrawPrimarySurfaceLocked == 0)) &&
      (source2 != (undefined4 *)0x0)) &&
     ((dest != (undefined4 *)0x0 && (flags != (undefined4 *)0x0)))) {
    *source2 = 0;
    *dest = 0;
    *flags = 0;
    *flags = g_DirectDrawBackBufferIsRgb565;
    value = LockDirectDrawPrimarySurface(0xffffffff,source2,dest);
    return value;
  }
  return 0;
}

