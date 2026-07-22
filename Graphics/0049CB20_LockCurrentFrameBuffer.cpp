#include "tarzan_ghidra_types.hpp"

// Address: 0x0049CB20
// Label: LockCurrentFrameBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
LockCurrentFrameBuffer
          (undefined4 graphicsObject,undefined4 source2,undefined4 dest,undefined4 width,uint *height
          )

{
  undefined4 value2;
  int value;
  
  if (height != (uint *)0x0) {
    value2 = CurrentGraphicsMode();
    switch(value2) {
    case 1:
      value = GetGlideFrameBufferWidth();
      *height = (uint)(0x27f < value);
      value2 = LockGlideFrameBuffer(graphicsObject,source2,dest,width);
      return value2;
    case 2:
      value = GetDirect3DFrameBufferWidth();
      *height = (uint)(0x27f < value);
      value2 = LockDirect3DFrameBuffer(graphicsObject,source2,dest,width);
      return value2;
    case 3:
    case 4:
      value = GetDirectDrawFrameBufferWidth();
      *height = (uint)(0x27f < value);
      value2 = LockDirectDrawFrameBuffer(graphicsObject,source2,dest,width);
      return value2;
    case 5:
      value = GetSoftwareFrameBufferWidth();
      *height = (uint)(0x27f < value);
      value2 = LockSoftwareFrameBufferForReadback(graphicsObject,source2,dest,width);
      return value2;
    }
  }
  return 0;
}

