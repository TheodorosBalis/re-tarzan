#include "tarzan_ghidra_types.hpp"

// Address: 0x00439360
// Label: FreeDeferredModelHeapBlocks
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void FreeDeferredModelHeapBlocks(int arg1)

{
  int value;
  int value2;
  
  value2 = 0;
  value = *(int *)(arg1 + 0xc);
  while (value != 0) {
    *(short *)(value + 2) = *(short *)(value + 2) + -1;
    if (*(short *)(value + 2) < 1) {
      if (value2 == 0) {
        *(undefined4 *)(arg1 + 0xc) = *(undefined4 *)(value + 0x14);
      }
      else {
        *(undefined4 *)(value2 + 0x14) = *(undefined4 *)(value + 0x14);
      }
      FreeModelHeapBlock(value + 0x18,&g_ModelLoadHeapState);
      if (value2 == 0) break;
      value = *(int *)(value2 + 0x14);
    }
    else {
      value2 = value;
      value = *(int *)(value + 0x14);
    }
  }
  value = GetModelHeapCompactionCandidate_FrameFiltered(arg1);
  value2 = 0x70;
  while( true ) {
    if (value == 0) {
      return;
    }
    value2 = value2 - *(int *)(value + 8);
    if (value2 < 1) break;
    g_ModelHeapCompactedWordsThisTick = g_ModelHeapCompactedWordsThisTick + *(int *)(value + 8);
    RelocateModelHeapBlockIntoFreeGap(*(undefined4 *)(arg1 + 8),arg1);
    value = GetModelHeapCompactionCandidate_FrameFiltered(arg1);
  }
  return;
}

