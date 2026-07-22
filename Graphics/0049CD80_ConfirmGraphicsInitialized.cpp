#include "tarzan_ghidra_types.hpp"

// Address: 0x0049CD80
// Label: ConfirmGraphicsInitialized
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ConfirmGraphicsInitialized(void)

{
  undefined4 value;
  
  value = CurrentGraphicsMode();
  switch(value) {
  case 1:
    ZeroGlobal723738();
    return;
  case 2:
    FlushPendingDirect3DFrame();
    return;
  case 3:
  case 4:
    UnlockDirectDrawPrimarySurface();
    return;
  case 5:
    UnlockSoftwareFrameBuffer();
    return;
  default:
    return;
  }
}

