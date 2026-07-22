#include "tarzan_ghidra_types.hpp"

// Address: 0x0045D0E0
// Label: StorkRide::InitScriptedObstacleB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StorkRide::InitScriptedObstacleB(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  ((EntitySceneObject *)value)->roll = 0;
  value2 = CEntities::CreateEntityAttachment(entry,0x50,0x10000000);
  if (value2 != 0) {
    *(undefined4 *)(value2 + 0x34) = 0;
    *(undefined4 *)(value2 + 0x44) = 0x200;
    *(undefined4 *)(value2 + 0x38) = 0x20;
  }
  *(undefined2 *)(value + 0xc) = 0x2000;
  value2 = g_WorldEntitySceneObjectArrayBase + 0x2018;
  *(undefined2 *)(value + 0xa0) = 0x400;
  ((EntitySceneObject *)value)->worldObject = value2;
  *(undefined4 *)(value + 0xb4) = 1;
  *(undefined4 *)(value + 0xa8) = 0x1800;
  *(undefined4 *)(value + 0xac) = 0x1800;
  *(undefined4 *)(value + 0xb0) = 0x1800;
  return;
}

