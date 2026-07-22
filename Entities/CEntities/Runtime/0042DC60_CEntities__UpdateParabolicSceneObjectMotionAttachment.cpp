#include "tarzan_ghidra_types.hpp"

// Address: 0x0042DC60
// Label: CEntities::UpdateParabolicSceneObjectMotionAttachment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::UpdateParabolicSceneObjectMotionAttachment(int entry)

{
  Entity *entity = (Entity *)entry;
  int entry2;
  int entry3;
  
  entry2 = CEntities::FindEntityAttachmentByFlags(entry,0x20000000);
  if (entry2 != 0) {
    if (*(int *)(entry2 + 0x10) == 0) {
      *(undefined4 *)(entry2 + 0x24) = *(undefined4 *)(entity->sceneObjects + 0x18);
      entry3 = SqrtToInt(*(int *)(entry2 + 0x14) * *(int *)(entry2 + 0xc) * 2 >> 4 & 0xfffffff0);
      *(int *)(entry2 + 0x18) = entry3 >> 4;
      if (entry3 >> 4 == 0) {
        *(undefined4 *)(entry2 + 0x18) = 4;
      }
      *(undefined4 *)(entry2 + 0x10) = 1;
      *(int *)(entry2 + 0x20) = *(int *)(entry2 + 0x18);
      *(int *)(entry2 + 0x1c) = ((*(int *)(entry2 + 0x18) << 8) / *(int *)(entry2 + 0xc) >> 7) + 2;
    }
    *(undefined4 *)(entry2 + 0x48) = 0;
    *(int *)(entity->sceneObjects + 0x18) =
         *(int *)(entity->sceneObjects + 0x18) - *(int *)(entry2 + 0x20);
    entry3 = *(int *)(entry2 + 0x28) + 1;
    *(int *)(entry2 + 0x20) = *(int *)(entry2 + 0x20) - *(int *)(entry2 + 0xc);
    *(int *)(entry2 + 0x28) = entry3;
    if (*(int *)(entry2 + 0x1c) <= entry3) {
      if (*(int *)(entry2 + 0x2c) == 0) {
        *(undefined4 *)(entry2 + 0x20) = *(undefined4 *)(entry2 + 0x18);
      }
      else {
        entry3 = *(int *)(entry2 + 0x18) >> 1;
        *(int *)(entry2 + 0x18) = entry3;
        *(int *)(entry2 + 0x20) = entry3;
        *(int *)(entry2 + 0x1c) = *(int *)(entry2 + 0x1c) >> 1;
      }
      *(undefined4 *)(entry2 + 0x28) = 0;
      *(undefined4 *)(entity->sceneObjects + 0x18) = *(undefined4 *)(entry2 + 0x24);
      *(undefined4 *)(entry2 + 0x48) = 1;
    }
  }
  return *(undefined4 *)(entry2 + 0x48);
}

