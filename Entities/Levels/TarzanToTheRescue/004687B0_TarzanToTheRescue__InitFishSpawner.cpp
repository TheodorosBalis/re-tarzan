#include "tarzan_ghidra_types.hpp"

// Address: 0x004687B0
// Label: TarzanToTheRescue::InitFishSpawner
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitFishSpawner(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  undefined4 value3;
  
  value2 = CEntities::CreateEntityAttachment(entry,0x38,0x10000000);
  if (value2 != 0) {
    value3 = RandomModulo(0x20);
    *(undefined4 *)(value2 + 0x14) = value3;
    value = entity->sceneObjects;
    *(undefined4 *)(value2 + 0x18) = ((EntitySceneObject *)value)->x;
    *(undefined4 *)(value2 + 0x1c) = ((EntitySceneObject *)value)->y;
    *(undefined4 *)(value2 + 0x20) = ((EntitySceneObject *)value)->z;
  }
  return;
}

