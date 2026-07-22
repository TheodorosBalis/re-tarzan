#include "tarzan_ghidra_types.hpp"

// Address: 0x004AD600
// Label: BuildBitmapCellGridEntities
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BuildBitmapCellGridEntities(undefined4 arg1,int arg2)

{
  Entity *entity2 = (Entity *)arg2;
  int value;
  int value2;
  
  if ((arg2 != 0) && (value2 = 0, 0 < *(int *)(arg2 + 0x30))) {
    value = arg2 + 0x34;
    do {
      BuildBitmapCellEntityList
                (arg1,value,*(int *)(arg2 + 0x14) + 0x14 + arg2,
                 *(int *)(arg2 + 0x18) + 0x18 + arg2);
      value2 = value2 + 1;
      value = value + 0x30;
    } while (value2 < *(int *)(arg2 + 0x30));
  }
  return;
}

