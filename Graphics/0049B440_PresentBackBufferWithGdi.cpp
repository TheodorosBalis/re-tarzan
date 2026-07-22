#include "tarzan_ghidra_types.hpp"

// Address: 0x0049B440
// Label: PresentBackBufferWithGdi
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void PresentBackBufferWithGdi(void)

{
  if (isGraphicsInitialized != 0) {
    UnlockSoftwareFrameBuffer();
    SetDIBitsToDevice(BitMapInfo_Struct,0,0,0x140,0xf0,0,0,0,0xf0,lpvBitsColorDataPTR,
                      (BITMAPINFO *)&g_SoftwareBackBufferBitmapInfo_Field0000,0);
                    /* WARNING: Could not recover jumptable at 0x0049b481. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    GdiFlush();
    return;
  }
  return;
}

