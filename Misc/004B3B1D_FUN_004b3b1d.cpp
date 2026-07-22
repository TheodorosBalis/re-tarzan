#include "tarzan_ghidra_types.hpp"

// Address: 0x004B3B1D
// Label: FUN_004b3b1d
// Label origin: source
// Original labels and source files are tracked in manifest.csv.

float10 FUN_004b3b1d(void)

{
  int callerFrameBase;
  float10 fpuValue;
  unkbyte10 fpuValue2;
  
  *(unkbyte10 *)(callerFrameBase + -0x9e) = fpuValue2;
  if ((*(byte *)(callerFrameBase + -0x97) & 0x40) == 0) {
    *(undefined1 *)(callerFrameBase + -0x90) = 1;
  }
  else {
    *(undefined1 *)(callerFrameBase + -0x90) = 7;
  }
  return *(float10 *)(callerFrameBase + -0x9e) + fpuValue;
}

