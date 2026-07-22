#include "tarzan_ghidra_types.hpp"

// Address: 0x00440600
// Label: CreateEntityEntitySceneObjectFromSourceRef
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CreateEntityEntitySceneObjectFromSourceRef(int arg1)

{
  int entry;
  undefined4 value;
  undefined2 value2;
  int entry2;
  
  entry2 = 0;
  entry = *(int *)(arg1 + 0x18);
  if ((entry != 0) &&
     (entry2 = CreateEntityEntitySceneObject(*(undefined4 *)(arg1 + -4),1), entry2 != 0)) {
    *(undefined4 *)(entry2 + 0x14) = *(undefined4 *)(arg1 + 0xc);
    *(undefined4 *)(entry2 + 0x18) = *(undefined4 *)(arg1 + 0x10);
    value = *(undefined4 *)(arg1 + 0x14);
    *(undefined2 *)(entry2 + 0xe) = 0;
    *(undefined4 *)(entry2 + 0x1c) = value;
    *(undefined4 *)(entry2 + 0x10) = g_CurrentWorldSceneContext;
    value2 = GetEncodedEntitySceneObjectIdFromSourceRef(entry);
    *(undefined2 *)(entry2 + 0xc) = value2;
  }
  return entry2;
}

