#include "tarzan_ghidra_types.hpp"

// Address: 0x004294F0
// Label: LoadAssetPayloadRange
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 LoadAssetPayloadRange(undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  int value;
  
  g_AssetPayloadLoadResultBlock = 0;
  EnqueueModelLoadRequest(arg1,arg2,arg3,0,&g_AssetPayloadLoadResultBlock,0);
  value = ProcessModelLoadQueue();
  while (value != 0) {
    CompactModelHeapFully(&g_ModelLoadHeapState);
    value = ProcessModelLoadQueue();
  }
  return g_AssetPayloadLoadResultBlock;
}

