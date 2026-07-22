#include "tarzan_ghidra_types.hpp"

// Address: 0x00498C30
// Label: CopyPackedAssetPayloadOverlapSafe
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CopyPackedAssetPayloadOverlapSafe(undefined4 *arg1)

{
  undefined1 *scratchBuffer;
  undefined1 *scratchBuffer3;
  int scratchBuffer2;
  
  scratchBuffer3 = (undefined1 *)*arg1;
  scratchBuffer = (undefined1 *)(arg1[1] + 0xc);
  scratchBuffer2 = arg1[3];
  if ((scratchBuffer < scratchBuffer3) && (scratchBuffer3 < scratchBuffer + scratchBuffer2)) {
    scratchBuffer3 = scratchBuffer3 + scratchBuffer2 + -1;
    scratchBuffer = (undefined1 *)(arg1[1] + 0xb + scratchBuffer2);
    while (scratchBuffer2 != 0) {
      *scratchBuffer3 = *scratchBuffer;
      scratchBuffer3 = scratchBuffer3 + -1;
      scratchBuffer = scratchBuffer + -1;
      scratchBuffer2 = scratchBuffer2 + -1;
    }
  }
  else {
    while (scratchBuffer2 != 0) {
      *scratchBuffer3 = *scratchBuffer;
      scratchBuffer3 = scratchBuffer3 + 1;
      scratchBuffer = scratchBuffer + 1;
      scratchBuffer2 = scratchBuffer2 + -1;
    }
  }
  return;
}

