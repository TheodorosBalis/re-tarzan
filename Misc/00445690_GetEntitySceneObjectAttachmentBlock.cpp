#include "tarzan_ghidra_types.hpp"

// Address: 0x00445690
// Label: GetEntitySceneObjectAttachmentBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int GetEntitySceneObjectAttachmentBlock(int arg1)

{
  ushort value;
  int entry;
  uint value2;
  int entry2;
  uint value3;
  
  entry2 = *(int *)(arg1 + 0x10);
  if (entry2 == 0) {
    return 0;
  }
  entry = *(int *)(entry2 + 0xc);
  if (entry == 0) {
    return 0;
  }
  value = *(ushort *)(arg1 + 0xc);
  value2 = value & 0xfff;
  value3 = value & 0x7000;
  if ((value & 0x7000) == 0) {
    entry2 = ResolveSceneContextPackedRelativeBlock(*(int *)(entry + 8) + 0x10 + value2 * 4 + entry,entry2);
    return entry2;
  }
  if (value3 == 0x2000) {
    entry2 = *(int *)(value2 * 0x30 + 0x5c + entry);
    if (entry2 != 0) {
      return entry2 + value2 * 0x30 + 0x5c + entry;
    }
  }
  else if (value3 == 0x5000) {
    entry2 = ResolveSceneAssetRelativePointerEntry(*(int *)(*(int *)(entry2 + 0xc) + 0x10) + value2 * 8 + 0x14 + *(int *)(entry2 + 0xc));
    if (entry2 == 0) {
      return 0;
    }
    return *(int *)(entry2 + 0x28) + 0x28 + entry2;
  }
  return 0;
}

