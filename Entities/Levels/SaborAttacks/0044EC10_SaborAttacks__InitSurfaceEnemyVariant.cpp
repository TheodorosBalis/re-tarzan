#include "tarzan_ghidra_types.hpp"

// Address: 0x0044EC10
// Label: SaborAttacks::InitSurfaceEnemyVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::InitSurfaceEnemyVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0xd00;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0x140) = 0x100;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::SetEntitySceneObjectScriptAttachment
              (entry,&g_SaborAttacksSurfaceEnemyVariantScriptDesc);
    *(undefined2 *)(entry + 0x48) = 0;
    *(undefined2 *)(entry + 0x4a) = 0;
  }
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  return;
}

