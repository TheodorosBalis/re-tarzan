#include "tarzan_ghidra_types.hpp"

// Address: 0x004172F0
// Label: ComingOfAge::InitSurfaceEnemyVariantD
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitSurfaceEnemyVariantD(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x1004;
  if ((*(byte *)(entry + 0x43) & 0x80) == 0) {
    LoadEncodedResourceId(0x1012);
    value = entity->sceneObjects;
    if (value != 0) {
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x8f0;
      ((EntitySceneObject *)value)->roll = 1;
      CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004c3680);
      value = ComingOfAge::InitSurfaceEnemyVariantState(entry);
      if (value != 0) {
        *(code **)(&((EntitySceneObject *)value)->worldObject) = ComingOfAge::SurfaceEnemyVariantDBehaviorCallback;
      }
    }
    CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  }
  else {
    value = CEntities::CountEntitiesOfTypeInList
                      (g_ActiveEntityListHead,*(undefined2 *)(entry + 0x46));
    if (value < 2) {
      UnloadEncodedResourceId(0x1012);
      return;
    }
  }
  return;
}

