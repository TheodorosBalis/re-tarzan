#include "tarzan_ghidra_types.hpp"

// Address: 0x004AD9D0
// Label: BuildBitmapCellResourceRuntime
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BuildBitmapCellResourceRuntime(undefined4 arg1,int arg2)

{
  int value;
  undefined4 value4;
  int value2;
  int value3;
  
  if (arg2 != 0) {
    value = *(int *)(arg2 + 0x10);
    if ((value != 0) && (value2 = 0, 0 < *(int *)(arg2 + 0x10 + value))) {
      value3 = arg2 + 0x14 + value;
      do {
        value4 = ResolveSceneAssetRelativePointerEntry(value3);
        BuildBitmapCellEntityList
                  (arg1,value4,*(int *)(arg2 + 0x14) + 0x14 + arg2,
                   *(int *)(arg2 + 0x18) + 0x18 + arg2);
        value2 = value2 + 1;
        value3 = value3 + 8;
      } while (value2 < *(int *)(arg2 + 0x10 + value));
    }
    BuildBitmapCellGridEntities(arg1,arg2);
  }
  return;
}

