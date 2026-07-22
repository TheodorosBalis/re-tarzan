#include "tarzan_ghidra_types.hpp"

// Address: 0x004214A0
// Label: CEntities::InitSurfaceEnemyVariantE
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitSurfaceEnemyVariantE(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x1004;
  if ((*(byte *)(entry + 0x43) & 0x80) == 0) {
    LoadEncodedResourceId(0x1016);
    value = entity->sceneObjects;
    if (value != 0) {
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x9c0;
      ((EntitySceneObject *)value)->roll = 1;
      *(undefined2 *)(value + 0x140) = 0x100;
      value2 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004c6520);
      if (value2 != 0) {
        CEntities::SelectScriptAttachmentSequence(value2,0);
      }
      value2 = entity->descriptor;
      *(undefined2 *)(entry + 0x48) = 0;
      *(undefined2 *)(entry + 0x4a) = 0;
      if (value2 != 0) {
        if ((*(byte *)(*(int *)(value2 + 0x10) + 3) & 1) != 0) {
          *(undefined2 *)(entry + 0x4a) = 0x80;
        }
        if (*(int *)(value2 + 0x10) != 0) {
          CEntities::ApplyAnimalRenderVariant
                    (entry,value,*(undefined4 *)(*(int *)(value2 + 0x10) + 0x10));
        }
      }
    }
    CEntities::LinkEntityIntoProcessingList(&g_LevelEnemyEntityListHead,entry);
  }
  else {
    value = CEntities::CountEntitiesOfTypeInList
                      (g_LevelEnemyEntityListHead,*(undefined2 *)(entry + 0x46));
    if (value < 2) {
      UnloadEncodedResourceId(0x1016);
      return;
    }
  }
  return;
}

