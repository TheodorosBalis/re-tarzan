#include "tarzan_ghidra_types.hpp"

// Address: 0x0049CCF0
// Label: BeginFrameBufferWriteForCurrentGraphicsMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BeginFrameBufferWriteForCurrentGraphicsMode
               (undefined4 graphicsObject,undefined4 *source2,undefined4 *dest)

{
  undefined4 value;
  undefined4 *bufferCursor;
  undefined4 *bufferCursor2;
  
  bufferCursor2 = source2;
  if (source2 == (undefined4 *)0x0) {
    bufferCursor2 = &source2;
  }
  bufferCursor = dest;
  if (dest == (undefined4 *)0x0) {
    bufferCursor = &dest;
  }
  *bufferCursor2 = 0;
  *bufferCursor = 0;
  value = CurrentGraphicsMode();
  switch(value) {
  case 1:
    BeginGlideFrameBufferWrite(graphicsObject);
    return;
  case 2:
    BeginDirect3DFrameAndClearBackBuffer(graphicsObject);
    return;
  case 3:
  case 4:
    LockDirectDrawPrimarySurface(graphicsObject,bufferCursor2,bufferCursor);
    return;
  case 5:
    LockSoftwareFrameBuffer(graphicsObject,bufferCursor2,bufferCursor);
  }
  return;
}

