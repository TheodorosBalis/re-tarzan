#include "tarzan_ghidra_types.hpp"

// Address: 0x00442BA0
// Label: CEntities::GetEntitySceneObjectCurrentLocalBounds
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::GetEntitySceneObjectCurrentLocalBounds(int entry2)

{
  short *value2;
  uint value;
  int entry;
  
  entry = *(int *)(*(int *)(entry2 + 0x10) + 0xc);
  value2 = (short *)(*(int *)(entry + 8) + 8 + entry);
  value = *(ushort *)(entry2 + 0xc) & 0xfff;
  if ((int)*value2 <= (int)value) {
    value = 0;
  }
  entry = ResolveModelDataIndexedRelativePointer(*(int *)(entry2 + 0x10),value2,value);
  if (entry != 0) {
    return entry + 8;
  }
  return 0;
}

