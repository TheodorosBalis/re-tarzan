#include "tarzan_ghidra_types.hpp"

// Address: 0x00419670
// Label: ComingOfAge::InitBreakableRewardPropVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitBreakableRewardPropVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x1000;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0xb60;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0x140) = 0;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004c3bc8);
    *(undefined2 *)(entry + 0x48) = 0;
    *(undefined2 *)(entry + 0x4a) = 0;
    if ((entity->descriptor != 0) &&
       (*(int *)(*(int *)(entity->descriptor + 0x10) + 4) == 1)) {
      *(undefined2 *)(entry + 0x4a) = 0x400;
    }
  }
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  return;
}

