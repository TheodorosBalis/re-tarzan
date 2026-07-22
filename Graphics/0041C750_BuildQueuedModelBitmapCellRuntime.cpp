#include "tarzan_ghidra_types.hpp"

// Address: 0x0041C750
// Label: BuildQueuedModelBitmapCellRuntime
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BuildQueuedModelBitmapCellRuntime(undefined4 arg1,int arg2)

{
  BindModelHeapBlockHandle(arg1,(undefined4 *)(arg2 + 0xc));
  BuildBitmapCellGridEntities(arg2 + 0x10,*(undefined4 *)(arg2 + 0xc));
  return;
}

