#include "tarzan_ghidra_types.hpp"

// Address: 0x00415460
// Label: ComingOfAge::InitMonkey
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitMonkey(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  int value3;
  
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x1004;
  if ((*(byte *)(entry + 0x43) & 0x80) == 0) {
    LoadEncodedResourceId(0x47);
    value = entity->sceneObjects;
    if (value != 0) {
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x1cd8;
      ((EntitySceneObject *)value)->roll = 1;
      *(undefined2 *)(value + 0x140) = 0x100;
      CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004c2a50);
      value2 = entity->descriptor;
      *(undefined2 *)(entry + 0x48) = 0;
      *(undefined2 *)(entry + 0x4a) = 0;
      if (value2 != 0) {
        if ((*(ushort *)(*(int *)(value2 + 0x10) + 2) & 0x100) != 0) {
          *(undefined2 *)(entry + 0x4a) = 0x80;
        }
        if ((*(ushort *)(*(int *)(value2 + 0x10) + 2) & 0x200) != 0) {
          *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) | 0x100;
        }
        if ((*(ushort *)(*(int *)(value2 + 0x10) + 2) & 0x400) != 0) {
          *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) | 0x200;
        }
        if ((*(byte *)(*(int *)(value2 + 0x10) + 3) & 8) != 0) {
          *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) | 0x400;
        }
        if (*(int *)(value2 + 0x10) != 0) {
          CEntities::ApplyAnimalRenderVariant
                    (entry,value,*(undefined4 *)(*(int *)(value2 + 0x10) + 0x10));
        }
      }
    }
    CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  }
  else {
    value = CEntities::CountEntitiesOfTypeInList
                      (g_ActiveEntityListHead,*(undefined2 *)(entry + 0x46));
    value2 = CEntities::CountEntitiesOfTypeInList(g_LevelEnemyEntityListHead,0xae);
    value3 = CEntities::CountEntitiesOfTypeInList(g_LevelEnemyEntityListHead,0xac);
    if (value + value2 + value3 < 2) {
      UnloadEncodedResourceId(0x47);
      return;
    }
  }
  return;
}

