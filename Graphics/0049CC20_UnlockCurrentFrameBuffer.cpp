#include "tarzan_ghidra_types.hpp"

// Address: 0x0049CC20
// Label: UnlockCurrentFrameBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UnlockCurrentFrameBuffer(void)

{
  undefined4 value;
  
  value = CurrentGraphicsMode();
  switch(value) {
  case 1:
    UnlockGlideFrameBuffer();
    return;
  case 2:
    UnlockDirect3DFrameBuffer();
    return;
  case 3:
  case 4:
    UnlockDirectDrawPrimarySurface_Thunk();
    return;
  case 5:
    UnlockSoftwareFrameBuffer_Thunk();
    return;
  default:
    return;
  }
}

