#include "tarzan_ghidra_types.hpp"

// Address: 0x0049B570
// Label: LockSoftwareFrameBufferForReadback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
LockSoftwareFrameBufferForReadback
          (undefined4 graphicsObject,undefined4 *source2,undefined4 *dest,undefined4 *flags)

{
  undefined4 value;
  
  if ((((isGraphicsInitialized != 0) && (g_SoftwareFrameBufferLocked == 0)) &&
      (source2 != (undefined4 *)0x0)) &&
     ((dest != (undefined4 *)0x0 && (flags != (undefined4 *)0x0)))) {
    *source2 = 0;
    *dest = 0;
    *flags = 0;
    value = LockSoftwareFrameBuffer(0xffffffff,source2,dest);
    return value;
  }
  return 0;
}

