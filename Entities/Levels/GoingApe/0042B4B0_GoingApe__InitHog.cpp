#include "tarzan_ghidra_types.hpp"

// Address: 0x0042B4B0
// Label: GoingApe::InitHog
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::InitHog(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x1000;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x410;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0x140) = 0;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_GoingApeHogScriptDesc);
    *(undefined2 *)(entry + 0x4a) = 0;
    *(undefined2 *)(entry + 0x48) = 0;
    *(undefined2 *)(entry + 0x3e) = 0x200;
    if (entity->descriptor != 0) {
      CEntities::ApplyConfiguredEntitySceneObjectScale
                (value,*(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 0x10));
    }
  }
  return;
}

