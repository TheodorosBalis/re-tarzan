#include "tarzan_ghidra_types.hpp"

// Address: 0x00421860
// Label: CEntities::InitSmallGroundAnimalVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitSmallGroundAnimalVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0xa28;
    ((EntitySceneObject *)value)->roll = 2;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0x140) = 0;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004c6588);
    *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 1;
  }
  CEntities::LinkEntityIntoProcessingList(&g_LevelEnemyEntityListHead,entry);
  return;
}

