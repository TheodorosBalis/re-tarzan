#include "tarzan_ghidra_types.hpp"

// Address: 0x0049C7A0
// Label: ShowFrameOnScreen
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ShowFrameOnScreen(void)

{
  undefined4 value;
  
  value = CurrentGraphicsMode();
  switch(value) {
  case 1:
    FlushPendingGlideFrameBufferWrite();
    return;
  case 2:
    BeginDirect3DSceneOrHandleLostDevice();
    return;
  case 3:
  case 4:
    PresentDirectDrawFrameBuffer();
    return;
  case 5:
    PresentBackBufferWithGdi();
    return;
  default:
    return;
  }
}

