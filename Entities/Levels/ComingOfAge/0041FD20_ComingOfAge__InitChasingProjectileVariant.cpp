#include "tarzan_ghidra_types.hpp"

// Address: 0x0041FD20
// Label: ComingOfAge::InitChasingProjectileVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitChasingProjectileVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x1004;
  if ((*(byte *)(entry + 0x43) & 0x80) == 0) {
    LoadEncodedResourceId(0x1013);
    value = entity->sceneObjects;
    if (value != 0) {
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x8f0;
      ((EntitySceneObject *)value)->roll = 1;
      CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004c6028);
      *(undefined2 *)(entry + 0x48) = 0;
      *(undefined2 *)(entry + 0x4a) = 0;
      *(undefined4 *)(entry + 0x4c) = 0;
      *(undefined4 *)(entry + 0x50) = 0;
      if (((entity->descriptor != 0) &&
          (value2 = *(int *)(entity->descriptor + 0x10), value2 != 0)) &&
         (*(int *)(value2 + 0x10) != 0)) {
        *(undefined4 *)(value + 0xb4) = 1;
        value2 = *(int *)(value2 + 0x10) << 4;
        *(int *)(value + 0xb0) = value2;
        *(int *)(value + 0xac) = value2;
        *(int *)(value + 0xa8) = value2;
      }
      *(undefined2 *)(entry + 0x3e) = 0x200;
    }
    CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  }
  else {
    value = CEntities::CountEntitiesOfTypeInList
                      (g_ActiveEntityListHead,*(undefined2 *)(entry + 0x46));
    if (value < 2) {
      UnloadEncodedResourceId(0x1013);
      return;
    }
  }
  return;
}

