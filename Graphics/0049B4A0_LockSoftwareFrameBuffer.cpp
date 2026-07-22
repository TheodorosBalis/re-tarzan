#include "tarzan_ghidra_types.hpp"

// Address: 0x0049B4A0
// Label: LockSoftwareFrameBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 LockSoftwareFrameBuffer(uint graphicsObject,int *source2,int *dest)

{
  uint value2;
  int value;
  uint *bufferCursor;
  
  if ((((isGraphicsInitialized != 0) && (g_SoftwareFrameBufferLocked == 0)) &&
      (source2 != (int *)0x0)) && (dest != (int *)0x0)) {
    *dest = 0x280;
    *source2 = (int)lpvBitsColorDataPTR;
    g_SoftwareFrameBufferLocked = 1;
    if ((graphicsObject != 0xffffffff) && (lpvBitsColorDataPTR != (uint *)0x0)) {
      value2 = graphicsObject >> 3 & 0x1f0000 | graphicsObject & 0xf800;
      _g_SoftwareFrameBufferLockState = (value2 >> 3 | graphicsObject & 0xf8) >> 3;
      value2 = (value2 >> 3 | graphicsObject & 0xf8) >> 3;
      bufferCursor = lpvBitsColorDataPTR;
      for (value = *dest * 0xf0 >> 2; value != 0; value = value + -1) {
        *bufferCursor = value2 | value2 << 0x10;
        bufferCursor = bufferCursor + 1;
      }
    }
    return 1;
  }
  return 0;
}

