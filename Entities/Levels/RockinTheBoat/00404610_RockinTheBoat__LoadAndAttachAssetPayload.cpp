#include "tarzan_ghidra_types.hpp"

// Address: 0x00404610
// Label: RockinTheBoat::LoadAndAttachAssetPayload
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::LoadAndAttachAssetPayload(undefined4 arg1,undefined4 arg2)

{
  undefined4 value;
  
  value = LoadAssetPayload(arg1);
  InitializePalettedTextureBlockFromAsset(arg2,value);
  LoadAttachedResourcePayloadNoOp(arg2);
  return;
}

