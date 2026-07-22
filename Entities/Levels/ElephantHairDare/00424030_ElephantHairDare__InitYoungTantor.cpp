#include "tarzan_ghidra_types.hpp"

// Address: 0x00424030
// Label: ElephantHairDare::InitYoungTantor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::InitYoungTantor(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0xc98;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0x140) = 0x100;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
    CEntities::SetEntitySceneObjectScriptAttachment
              (entry,&g_ElephantHairDareYoungTantorScriptDesc);
    *(undefined2 *)(entry + 0x48) = 0;
    *(undefined2 *)(entry + 0x4a) = 0;
    if (entity->descriptor != 0) {
      CEntities::ApplyConfiguredEntitySceneObjectScale
                (value,*(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 0x10));
    }
  }
  return;
}

