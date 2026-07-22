#include "tarzan_ghidra_types.hpp"

// Address: 0x00439430
// Label: CompactModelHeapFully
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CompactModelHeapFully(int arg1)

{
  int value;
  
  value = GetModelHeapCompactionCandidate_Stub(arg1);
  while (value != 0) {
    RelocateModelHeapBlockIntoFreeGap(*(undefined4 *)(arg1 + 8),arg1);
    value = GetModelHeapCompactionCandidate_Stub(arg1);
  }
  return;
}

