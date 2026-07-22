#include "tarzan_ghidra_types.hpp"

// Address: 0x0047ECA0
// Label: FindLevelTransitionEntryIndex
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int FindLevelTransitionEntryIndex(int arg1,int arg2)

{
  int foundIndex;
  int foundIndex2;
  undefined4 *dataCursor;
  
  foundIndex2 = 0;
  dataCursor = &g_LevelTransitionEntries;
  foundIndex = g_LevelTransitionEntries;
  while( true ) {
    if (foundIndex == -1) {
      return -1;
    }
    if ((foundIndex == arg1) && (dataCursor[1] == arg2)) break;
    foundIndex = dataCursor[0xf];
    dataCursor = dataCursor + 0xf;
    foundIndex2 = foundIndex2 + 1;
  }
  return foundIndex2;
}

