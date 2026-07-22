#include "tarzan_ghidra_types.hpp"

// Address: 0x004399C0
// Label: FindNatureTerrainCellIndexAtGridCoords
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int FindNatureTerrainCellIndexAtGridCoords(int *arg1,uint *arg2)

{
  uint value;
  uint value2;
  int foundIndex;
  
  value = *arg2;
  do {
    value2 = value & 3;
    if (value2 == 0) {
      return (int)*arg2 >> 2;
    }
    foundIndex = (int)value >> 2;
    if (value2 == 1) {
      if (*arg1 < foundIndex) {
LAB_00439a0f:
        arg2 = (uint *)((int)arg2 + arg2[2] + 8);
      }
      else {
        arg2 = (uint *)((int)arg2 + arg2[1] + 4);
      }
    }
    else if (value2 == 2) {
      if (arg1[1] < foundIndex) goto LAB_00439a0f;
      arg2 = (uint *)((int)arg2 + arg2[1] + 4);
    }
    else if (value2 == 3) {
      if (arg1[2] < foundIndex) goto LAB_00439a0f;
      arg2 = (uint *)((int)arg2 + arg2[1] + 4);
    }
    value = *arg2;
  } while( true );
}

