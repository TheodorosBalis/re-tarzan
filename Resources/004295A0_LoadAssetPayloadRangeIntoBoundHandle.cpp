#include "tarzan_ghidra_types.hpp"

// Address: 0x004295A0
// Label: LoadAssetPayloadRangeIntoBoundHandle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
LoadAssetPayloadRangeIntoBoundHandle
          (undefined4 arg1,undefined4 arg2,undefined4 arg3,undefined4 arg4)

{
  int value;
  
  g_BoundAssetPayloadLoadResultBlock = 0;
  EnqueueModelLoadRequest(arg1,arg2,arg4,0,&g_BoundAssetPayloadLoadResultBlock,1);
  value = ProcessModelLoadQueue();
  while (value != 0) {
    CompactModelHeapFully(&g_ModelLoadHeapState);
    value = ProcessModelLoadQueue();
  }
  BindModelHeapBlockHandle(g_BoundAssetPayloadLoadResultBlock,arg3);
  return 0;
}

