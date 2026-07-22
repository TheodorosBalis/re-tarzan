#include "tarzan_ghidra_types.hpp"

// Address: 0x00431330
// Label: CEntities::SelectEntityAnimationAttachmentState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::SelectEntityAnimationAttachmentState(undefined4 entry3,short sceneObject)

{
  int entry;
  int entry2;
  
  entry2 = CEntities::FindEntityAttachmentByFlags(entry3,0x400);
  if (entry2 == 0) {
    return 0;
  }
  *(short *)(entry2 + 0x18) = sceneObject;
  entry = *(int *)(*(int *)(entry2 + 0x10) + sceneObject * 4);
  if (entry == 0) {
    CEntities::SelectEntityAnimationAttachmentState(entry3,0);
    return 0;
  }
  *(int *)(entry2 + 0xc) = entry;
  *(undefined2 *)(entry2 + 0x14) = 0xffff;
  *(undefined2 *)(entry2 + 0x16) = 0;
  return 1;
}

