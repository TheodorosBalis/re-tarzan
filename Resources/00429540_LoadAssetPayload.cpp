#include "tarzan_ghidra_types.hpp"

// Address: 0x00429540
// Label: LoadAssetPayload
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 LoadAssetPayload(undefined4 arg1)

{
  int value;
  undefined4 value2;
  
  value = GetAssetPayloadSizeByPath(arg1);
  if (value == -1) {
    return 0;
  }
  value2 = LoadAssetPayloadRange(arg1,0,value);
  return value2;
}

