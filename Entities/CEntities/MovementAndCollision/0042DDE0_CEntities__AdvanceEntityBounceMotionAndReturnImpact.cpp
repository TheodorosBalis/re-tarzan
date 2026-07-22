#include "tarzan_ghidra_types.hpp"

// Address: 0x0042DDE0
// Label: CEntities::AdvanceEntityBounceMotionAndReturnImpact
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::AdvanceEntityBounceMotionAndReturnImpact(int entry)

{
  Entity *entity = (Entity *)entry;
  int entry2;
  uint value;
  int entry3;
  uint value2;
  
  entry2 = CEntities::FindEntityAttachmentByFlags(entry,0x20000000);
  if (entry2 != 0) {
    if (*(int *)(entry2 + 0x10) == 0) {
      *(undefined4 *)(entry2 + 0x5c) = 0;
      *(undefined4 *)(entry2 + 0x20) = *(undefined4 *)(entry2 + 0x18);
      *(undefined4 *)(entry2 + 0x10) = 1;
    }
    *(undefined4 *)(entry2 + 0x48) = 0;
    *(int *)(entity->sceneObjects + 0x18) =
         *(int *)(entity->sceneObjects + 0x18) - *(int *)(entry2 + 0x20);
    *(int *)(entry2 + 0x20) = *(int *)(entry2 + 0x20) - *(int *)(entry2 + 0xc);
    *(int *)(entity->sceneObjects + 0x14) =
         *(int *)(entity->sceneObjects + 0x14) + *(int *)(entry2 + 0x40);
    *(int *)(entity->sceneObjects + 0x1c) =
         *(int *)(entity->sceneObjects + 0x1c) + *(int *)(entry2 + 0x44);
    *(int *)(entry2 + 0x5c) = *(int *)(entry2 + 0x5c) + 1;
    entry3 = *(int *)(entity->sceneObjects + 0x18);
    if (*(int *)(entry2 + 0x24) <= entry3) {
      value = entry3 - *(int *)(entry2 + 0x24);
      value2 = (int)value >> 0x1f;
      *(uint *)(entity->sceneObjects + 0x18) = entry3 - ((value ^ value2) - value2);
      entry3 = *(int *)(entry2 + 0x18);
      if (*(int *)(entry2 + 0x2c) != 0) {
        entry3 = entry3 >> 1;
        *(int *)(entry2 + 0x18) = entry3;
      }
      *(int *)(entry2 + 0x20) = entry3;
      *(undefined4 *)(entry2 + 0x48) = 1;
    }
    return *(undefined4 *)(entry2 + 0x48);
  }
  return 0;
}

