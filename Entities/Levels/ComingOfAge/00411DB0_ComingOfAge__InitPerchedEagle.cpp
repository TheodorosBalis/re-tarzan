#include "tarzan_ghidra_types.hpp"

// Address: 0x00411DB0
// Label: ComingOfAge::InitPerchedEagle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitPerchedEagle(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x958;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0x140) = 0;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004c12a0);
    *(undefined2 *)(entry + 0x4a) = 1;
    *(undefined4 *)(entry + 0x4c) = 0;
    *(undefined2 *)(entry + 0x48) = 4;
    return;
  }
  CEntities::ReleaseEntityToFreeList((byte *)entry);
  return;
}

