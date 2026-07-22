#include "tarzan_ghidra_types.hpp"

// Address: 0x00421040
// Label: CEntities::InitSurfaceEnemyVariantD
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitSurfaceEnemyVariantD(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x1004;
  if ((*(byte *)(entry + 0x43) & 0x80) == 0) {
    LoadEncodedResourceId(0x1015);
    value = entity->sceneObjects;
    if (value != 0) {
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x9c0;
      ((EntitySceneObject *)value)->roll = 1;
      *(undefined2 *)(value + 0x140) = 0x100;
      CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004c6500);
      *(undefined2 *)(entry + 0x48) = 0;
      *(undefined2 *)(entry + 0x4a) = 0;
    }
    value2 = entity->descriptor;
    if (value2 != 0) {
      *(undefined2 *)(entry + 0x3e) = *(undefined2 *)(*(int *)(value2 + 0x10) + 4);
      *(undefined2 *)(entry + 0x4a) = *(undefined2 *)(*(int *)(value2 + 0x10) + 8);
      if (*(int *)(value2 + 0x10) != 0) {
        CEntities::ApplyAnimalRenderVariant
                  (entry,value,*(undefined4 *)(*(int *)(value2 + 0x10) + 0x10));
      }
    }
    if (*(short *)(entry + 0x3e) == 0) {
      *(undefined2 *)(entry + 0x3e) = 0x200;
    }
    if (*(short *)(entry + 0x4a) == 0) {
      *(undefined2 *)(entry + 0x4a) = 0x32;
    }
    CEntities::LinkEntityIntoProcessingList(&g_LevelEnemyEntityListHead,entry);
  }
  else {
    value = CEntities::CountEntitiesOfTypeInList
                      (g_LevelEnemyEntityListHead,*(undefined2 *)(entry + 0x46));
    value2 = CEntities::CountEntitiesOfTypeInList(g_ActiveEntityListHead,0x1b9);
    if (value + value2 < 2) {
      UnloadEncodedResourceId(0x1015);
      return;
    }
  }
  return;
}

