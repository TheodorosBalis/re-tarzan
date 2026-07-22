#include "tarzan_ghidra_types.hpp"

// Address: 0x004294C0
// Label: EnqueueAssetPayloadLoadRequest
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int EnqueueAssetPayloadLoadRequest(undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined4 value;
  
  value = GetAssetPayloadSizeByPath(arg1,arg2,arg3,1);
  EnqueueModelLoadRequest(arg1,0,value);
  return 0;
}

