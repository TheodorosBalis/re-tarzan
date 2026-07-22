#include "tarzan_ghidra_types.hpp"

// Address: 0x0044FCA0
// Label: SaborAttacks::InitPerchedEagle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::InitPerchedEagle(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x958;
    ((EntitySceneObject *)value)->roll = 1;
    *(undefined2 *)(value + 0x140) = 0;
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_SaborAttacksEagleScriptDesc);
    *(undefined2 *)(entry + 0x4a) = 1;
    *(undefined4 *)(entry + 0x4c) = 0;
    *(undefined2 *)(entry + 0x48) = 4;
    return;
  }
  CEntities::ReleaseEntityToFreeList((byte *)entry);
  return;
}

