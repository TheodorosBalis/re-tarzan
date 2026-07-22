#include "tarzan_ghidra_types.hpp"

// Address: 0x0044F430
// Label: SaborAttacks::InitSurfaceEnemyVariantB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::InitSurfaceEnemyVariantB(int entry)

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
    value2 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_SaborAttacksSurfaceEnemyVariantBScriptDesc);
    if (value2 != 0) {
      CEntities::SelectScriptAttachmentSequence(value2,0);
    }
    *(undefined2 *)(entry + 0x48) = 0;
    *(undefined2 *)(entry + 0x4a) = 0;
    if (((EntitySceneObject *)value)->pad108 == 1) {
      *(undefined2 *)(entry + 0x4a) = 0x80;
      CEntities::OrientEntitySceneObjectToAdjacentJungleSurfaceSegment(entry,value);
    }
    *(undefined4 *)(entry + 0x50) = 0;
    if (entity->descriptor != 0) {
      *(undefined4 *)(entry + 0x50) =
           *(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 8);
    }
    if (*(int *)(entry + 0x50) == 0) {
      *(undefined4 *)(entry + 0x50) = 3000;
    }
  }
  CEntities::LinkEntityIntoProcessingList(&g_LevelEnemyEntityListHead,entry);
  return;
}

