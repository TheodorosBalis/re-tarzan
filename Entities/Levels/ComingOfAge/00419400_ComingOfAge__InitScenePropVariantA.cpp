#include "tarzan_ghidra_types.hpp"

// Address: 0x00419400
// Label: ComingOfAge::InitScenePropVariantA
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitScenePropVariantA(int entry3)

{
  Entity *entity = (Entity *)entry3;
  int entry;
  int entry2;
  
  entry = entity->sceneObjects;
  if (entry != 0) {
    entry2 = g_WorldEntitySceneObjectArrayBase + 0xa28;
    ((EntitySceneObject *)entry)->roll = 2;
    ((EntitySceneObject *)entry)->worldObject = entry2;
    *(undefined2 *)(entry + 0x140) = 0;
    CEntities::AcquireEntitySceneObjectResourceSet(entry);
    CEntities::SetEntitySceneObjectScriptAttachment(entry3,(uint *)&DAT_004c3a80);
    *(byte *)(entry3 + 0x4a) = *(byte *)(entry3 + 0x4a) | 1;
  }
  CEntities::LinkEntityIntoProcessingList(&g_LevelEnemyEntityListHead,entry3);
  return;
}

