#include "tarzan_ghidra_types.hpp"

// Address: 0x00448800
// Label: FindJungleSurfaceSegmentAtCoord
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int FindJungleSurfaceSegmentAtCoord(int arg1,int arg2)

{
  int foundIndex;
  int foundIndex2;
  
  foundIndex2 = arg1 + 0x4c;
  foundIndex = *(int *)(arg1 + 0x58);
  while( true ) {
    if (arg2 < foundIndex) {
      return foundIndex2 + -0x1c;
    }
    if ((*(uint *)(foundIndex2 + 0x14) & 0x2000) != 0) break;
    foundIndex = *(int *)(foundIndex2 + 0x28);
    foundIndex2 = foundIndex2 + 0x1c;
  }
  return foundIndex2;
}

