#include "tarzan_ghidra_types.hpp"

// Address: 0x00429600
// Label: LoadAssetPayloadIntoBoundHandle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 LoadAssetPayloadIntoBoundHandle(undefined4 arg1,undefined4 arg2)

{
  undefined4 value;
  
  value = GetAssetPayloadSizeByPath(arg1);
  LoadAssetPayloadRangeIntoBoundHandle(arg1,0,arg2,value);
  return value;
}

