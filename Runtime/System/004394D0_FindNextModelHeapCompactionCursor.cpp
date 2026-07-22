#include "tarzan_ghidra_types.hpp"

// Address: 0x004394D0
// Label: FindNextModelHeapCompactionCursor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int FindNextModelHeapCompactionCursor(int arg1)

{
  int foundIndex;
  
  foundIndex = *(int *)(arg1 + 8);
  while( true ) {
    if (foundIndex == 0) {
      return 0;
    }
    arg1 = arg1 + 0x18 + foundIndex * 4;
    if (*(int *)(arg1 + 4) == 0) break;
    foundIndex = *(int *)(arg1 + 8);
  }
  return arg1;
}

