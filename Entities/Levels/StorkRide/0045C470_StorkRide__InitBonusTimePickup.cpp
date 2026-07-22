#include "tarzan_ghidra_types.hpp"

// Address: 0x0045C470
// Label: StorkRide::InitBonusTimePickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StorkRide::InitBonusTimePickup(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  int value3;
  
  value = entity->sceneObjects;
  ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x3a8;
  *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2029;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  value2 = CEntities::CreateEntityAttachment(entry,0x60,0x20000000);
  if (value2 != 0) {
    *(undefined4 *)(value2 + 0xc) = 2;
    value3 = RandomModulo(0x40);
    *(int *)(value2 + 0x14) = value3 + 0x80;
    *(undefined4 *)(value2 + 0x10) = 0;
    *(undefined4 *)(value2 + 0x28) = 0;
    *(undefined4 *)(value2 + 0x2c) = 0;
    *(undefined4 *)(value2 + 0x30) = 0;
    *(undefined4 *)(value2 + 0x34) = 0;
  }
  *(undefined4 *)(value + 0xb4) = 1;
  *(undefined4 *)(value + 0xa8) = 0x1000;
  *(undefined4 *)(value + 0xac) = 0x1000;
  *(undefined4 *)(value + 0xb0) = 0x1000;
  ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + -0x20;
  return;
}

