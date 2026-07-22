#include "tarzan_ghidra_types.hpp"

// Address: 0x00481F30
// Label: CEntities::InitLeafSwimmingTreeLogObstacleCollisionVolume
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitLeafSwimmingTreeLogObstacleCollisionVolume(int entry)

{
  Entity *entity = (Entity *)entry;
  undefined2 value3;
  int value;
  int value2;
  
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  value2 = CEntities::CreateEntityAttachment(entry,0x38,0x10000001);
  if (value2 != 0) {
    value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000001);
    if ((value2 != 0) && (entity->descriptor != 0)) {
      value = *(int *)(entity->descriptor + 0x10);
      *(undefined2 *)(value2 + 0xc) = 0;
      value3 = *(undefined2 *)(value + 4);
      *(undefined2 *)(value2 + 0x10) = 0;
      *(undefined2 *)(value2 + 0xe) = value3;
      *(undefined4 *)(value2 + 0x18) = 0;
      *(undefined4 *)(value2 + 0x14) = *(undefined4 *)(value + 8);
      *(undefined4 *)(value2 + 0x1c) = *(undefined4 *)(value + 0xc);
      *(int *)(value2 + 0x34) = *(int *)(value + 0x10) << 8;
    }
  }
  return;
}

