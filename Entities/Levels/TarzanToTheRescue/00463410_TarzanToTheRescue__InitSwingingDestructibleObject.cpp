#include "tarzan_ghidra_types.hpp"

// Address: 0x00463410
// Label: TarzanToTheRescue::InitSwingingDestructibleObject
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitSwingingDestructibleObject(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  value = CEntities::CreateEntityAttachment(entry,0x20,0x10000000);
  if (value != 0) {
    if (entity->descriptor != 0) {
      *(undefined4 *)(entry + 0x50) =
           *(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 4);
    }
    *(undefined4 *)(value + 0x10) = 0x100;
    *(undefined4 *)(value + 0x14) = 0x40;
    value2 = RandomModulo(0x1000);
    *(undefined4 *)(value + 0x18) = value2;
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2006;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
    *(undefined4 *)(value + 0xc) = 0;
  }
  return;
}

