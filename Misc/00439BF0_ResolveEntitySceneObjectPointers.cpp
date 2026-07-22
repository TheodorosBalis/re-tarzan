#include "tarzan_ghidra_types.hpp"

// Address: 0x00439BF0
// Label: ResolveEntitySceneObjectPointers
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResolveEntitySceneObjectPointers(int *arg1)

{
  int entry;
  int entry2;
  int entry3;
  
  entry2 = *arg1;
  entry3 = *(int *)(*(int *)(entry2 + 0xc) + 0xc) + 0xc + *(int *)(entry2 + 0xc);
  arg1[7] = entry3;
  entry = arg1[6] * 4 + 4;
  entry3 = *(int *)(entry + entry3) + entry + entry3;
  arg1[8] = entry3;
  arg1[9] = *(int *)(entry3 + 0x34) + 0x34 + entry3;
  arg1[10] = *(int *)(entry3 + 0xc) + 0xc + entry3;
  arg1[0xf] = *(int *)(entry3 + 0x10) + 0x10 + entry3;
  arg1[0xb] = *(int *)(entry3 + 0x18) + 0x18 + entry3;
  arg1[0xc] = *(int *)(*(int *)(entry2 + 0xc) + 0x10) + 0x10 + *(int *)(entry2 + 0xc);
  arg1[0xd] = *(int *)(*(int *)(entry2 + 0xc) + 8) + 0x10 + *(int *)(entry2 + 0xc);
  entry = *(int *)(*(int *)(entry2 + 0xc) + 0x24) + 0x28 + *(int *)(entry2 + 0xc);
  arg1[0xe] = entry;
  *(undefined4 *)(entry + 8) = *(undefined4 *)(entry2 + 0xc);
  return;
}

