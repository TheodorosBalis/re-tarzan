#include "tarzan_ghidra_types.hpp"

// Address: 0x0044F8E0
// Label: SaborAttacks::InitProjectileSurfaceEnemy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::InitProjectileSurfaceEnemy(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x1318;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0x140) = 0x100;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_SaborAttacksSurfaceEnemyScriptDesc);
    *(undefined2 *)(entry + 0x48) = 0;
    *(undefined2 *)(entry + 0x4a) = 0;
  }
  value = entity->descriptor;
  if (value != 0) {
    *(undefined2 *)(entry + 0x3e) = *(undefined2 *)(((EntitySceneObject *)value)->worldObject + 4);
    *(undefined2 *)(entry + 0x4a) = *(undefined2 *)(((EntitySceneObject *)value)->worldObject + 8);
  }
  if (*(short *)(entry + 0x3e) == 0) {
    *(undefined2 *)(entry + 0x3e) = 0x200;
  }
  if (*(short *)(entry + 0x4a) == 0) {
    *(undefined2 *)(entry + 0x4a) = 0x32;
  }
  CEntities::LinkEntityIntoProcessingList(&g_LevelEnemyEntityListHead,entry);
  return;
}

