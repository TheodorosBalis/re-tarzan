#include "tarzan_ghidra_types.hpp"

// Address: 0x0049A270
// Label: DecodeStreamedEdlPayloadToBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int DecodeStreamedEdlPayloadToBuffer(int arg1,int arg2)

{
  int value;
  int *intCursor;
  int scratchBuffer2 [5];
  undefined4 scratchBuffer;
  int scratchBuffer3;
  
  if ((arg1 == 0) || (arg2 == 0)) {
    scratchBuffer2[3] = 0;
  }
  else {
    intCursor = scratchBuffer2;
    for (value = 8; value != 0; value = value + -1) {
      *intCursor = 0;
      intCursor = intCursor + 1;
    }
    scratchBuffer2[1] = arg1;
    scratchBuffer2[0] = arg2;
    scratchBuffer = 0;
    DecodeEdlCompressedPayload(scratchBuffer2);
    if (scratchBuffer3 != 0) {
      scratchBuffer2[3] = 0;
    }
  }
  return scratchBuffer2[3];
}

