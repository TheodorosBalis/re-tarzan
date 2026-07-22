#include "tarzan_ghidra_types.hpp"

// Address: 0x0049A160
// Label: DecodeEdlCompressedPayload
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void __thiscall DecodeEdlCompressedPayload(undefined4 arg1,int arg2)

{
  ParseEdlCompressionHeader(arg2,arg1);
  if (*(int *)(arg2 + 0x1c) == 0) {
    if (*(int *)(arg2 + 0x10) == 0) {
      CopyPackedAssetPayloadOverlapSafe(arg2);
    }
    else if (*(int *)(arg2 + 0x10) == 1) {
      DecompressFsdCompressedPayload(arg2);
    }
  }
  return;
}

