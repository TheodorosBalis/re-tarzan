#include "tarzan_ghidra_types.hpp"

// Address: 0x004455F0
// Label: ResolveSceneContextPackedRelativeBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ResolveSceneContextPackedRelativeBlock(int *arg1,int arg2)

{
  int entry;
  char resultFlag;
  int entry2;
  
  resultFlag = (char)*arg1;
  if (resultFlag == '\0') {
    entry2 = *(int *)(arg2 + 0xc);
  }
  else {
    entry2 = *(int *)(arg2 + 0x28 + resultFlag * 8);
    if (entry2 == 0) {
      return 0;
    }
  }
  entry2 = (*arg1 >> 8) + entry2;
  entry = *(int *)(entry2 + 4);
  if (entry != 0) {
    return entry + 4 + entry2;
  }
  return 0;
}

