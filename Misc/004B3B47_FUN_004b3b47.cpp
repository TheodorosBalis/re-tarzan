#include "tarzan_ghidra_types.hpp"

// Address: 0x004B3B47
// Label: FUN_004b3b47
// Label origin: source
// Original labels and source files are tracked in manifest.csv.

float10 FUN_004b3b47(void)

{
  float10 value;
  int callerFrameBase;
  unkbyte10 fpuValue;
  float10 value2;
  float10 fpuValue2;
  
  *(unkbyte10 *)(callerFrameBase + -0x9e) = fpuValue;
  value = *(float10 *)(callerFrameBase + -0x9e);
  value2 = value;
  if ((*(byte *)(callerFrameBase + -0x97) & 0x40) != 0) {
    *(float10 *)(callerFrameBase + -0x9e) = fpuValue2;
    value2 = *(float10 *)(callerFrameBase + -0x9e);
    fpuValue2 = value;
    if ((*(byte *)(callerFrameBase + -0x97) & 0x40) != 0) {
      *(undefined1 *)(callerFrameBase + -0x90) = 7;
      goto LAB_004b3b83;
    }
  }
  *(undefined1 *)(callerFrameBase + -0x90) = 1;
LAB_004b3b83:
  return value2 + fpuValue2;
}

