#include "tarzan_ghidra_types.hpp"

// Address: 0x0044DBA0
// Label: ConfigureSaborBattleVictoryEntity
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ConfigureSaborBattleVictoryEntity(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int entry;
  undefined4 value;
  int entry2;
  
  entry2 = g_WorldEntitySceneObjectArrayBase;
  entry = entity->sceneObjects;
  if (entry == 0) {
    CEntities::ReleaseEntityToFreeList((byte *)arg1);
    return;
  }
  *(undefined2 *)(entry + 0xc) = 0x186;
  ((EntitySceneObject *)entry)->worldObject = entry2 + 0x11e0;
  value = *(undefined4 *)(g_PlayerEntitySceneObject + 0x6c);
  ((EntitySceneObject *)entry)->roll = 0;
  *(undefined4 *)(entry + 0x6c) = value;
  ((EntitySceneObject *)entry)->yaw = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2);
  return;
}

