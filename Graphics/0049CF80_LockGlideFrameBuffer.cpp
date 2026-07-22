#include "tarzan_ghidra_types.hpp"

// Address: 0x0049CF80
// Label: LockGlideFrameBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 LockGlideFrameBuffer(int graphicsObject,int *source2,uint *dest,undefined4 *width)

{
  int value;
  uint savedEsi;
  undefined4 scratchBuffer2;
  undefined4 scratchBuffer;
  undefined4 scratchBuffer5;
  undefined4 scratchBuffer4;
  undefined4 scratchBuffer3;
  
  scratchBuffer2 = 0x14;
  scratchBuffer = 0;
  scratchBuffer5 = 0;
  scratchBuffer4 = 0;
  scratchBuffer3 = 0;
  if ((((g_GlideFrameBufferPtr != 0) && (source2 != (int *)0x0)) && (dest != (uint *)0x0)) &&
     ((g_GlideFrameBufferLockActive == 0 && (width != (undefined4 *)0x0)))) {
    *source2 = 0;
    *dest = 0;
    *width = 0;
    value = (*g_GlideLfbLockProc)(graphicsObject != 0,1,(-(uint)(graphicsObject != 0) & 0xffffff01) + 0xff,0,0);
    g_GlideLfbLockWriteFlag = 1;
    g_GlideFrameBufferLockActive = (graphicsObject != 0) + 1;
    if ((value != 0) && ((&scratchBuffer2 != (undefined4 *)0x0 && (0x27f < savedEsi)))) {
      *source2 = (int)&scratchBuffer2;
      *dest = savedEsi;
      *width = 1;
      return 1;
    }
    UnlockGlideFrameBuffer();
  }
  return 0;
}

