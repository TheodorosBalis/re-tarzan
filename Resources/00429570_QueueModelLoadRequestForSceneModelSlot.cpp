#include "tarzan_ghidra_types.hpp"

// Address: 0x00429570
// Label: QueueModelLoadRequestForSceneModelSlot
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int QueueModelLoadRequestForSceneModelSlot(undefined4 arg1,undefined4 arg2,undefined4 arg3,undefined4 arg4)

{
  EnqueueModelLoadRequest(arg1,arg2,arg4,0,arg3,1);
  return 0;
}

