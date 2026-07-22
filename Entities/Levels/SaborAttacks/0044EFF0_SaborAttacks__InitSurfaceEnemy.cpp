#include "tarzan_ghidra_types.hpp"

// Address: 0x0044EFF0
// Label: SaborAttacks::InitSurfaceEnemy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::InitSurfaceEnemy(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x1000;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x1318;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0x140) = 0x100;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_SaborAttacksSurfaceEnemyScriptDesc);
    value = entity->descriptor;
    *(undefined2 *)(entry + 0x48) = 0;
    *(undefined2 *)(entry + 0x4a) = 0;
    if (value != 0) {
      if ((*(byte *)(((EntitySceneObject *)value)->worldObject + 3) & 1) != 0) {
        *(undefined2 *)(entry + 0x4a) = 0x80;
      }
      if ((*(ushort *)(((EntitySceneObject *)value)->worldObject + 2) & 0x200) != 0) {
        *(byte *)(entry + 0x4b) = *(byte *)(entry + 0x4b) | 1;
      }
      if ((*(ushort *)(((EntitySceneObject *)value)->worldObject + 2) & 0x400) != 0) {
        *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) | 0x200;
      }
      if ((*(byte *)(((EntitySceneObject *)value)->worldObject + 3) & 8) != 0) {
        *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) | 0x400;
      }
    }
  }
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  return;
}

