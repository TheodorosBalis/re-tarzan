#include "tarzan_ghidra_types.hpp"

// Address: 0x00426040
// Label: ElephantHairDare::InitSideHoppingEnemy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::InitSideHoppingEnemy(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x5b0;
    ((EntitySceneObject *)value)->roll = 2;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0x140) = 0;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    *(undefined2 *)(value + 0xa0) = 0x400;
    CEntities::SetEntitySceneObjectScriptAttachment
              (entry,&g_ElephantHairDareSideHoppingEnemyScriptDesc);
    *(undefined2 *)(entry + 0x48) = 0;
    *(undefined2 *)(entry + 0x4a) = 0;
    *(undefined4 *)(entry + 0x50) = *(undefined4 *)(((EntitySceneObject *)value)->surface + 0xc);
    CEntities::AdvanceEntityAlongJungleSurface(entry,value,0,0x40);
  }
  CEntities::LinkEntityIntoProcessingList(&g_LevelEnemyEntityListHead,entry);
  return;
}

