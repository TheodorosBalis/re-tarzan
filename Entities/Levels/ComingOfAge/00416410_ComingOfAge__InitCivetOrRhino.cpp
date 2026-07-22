#include "tarzan_ghidra_types.hpp"

// Address: 0x00416410
// Label: ComingOfAge::InitCivetOrRhino
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitCivetOrRhino(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x1d40;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    ((EntitySceneObject *)value)->roll = 1;
    *(undefined2 *)(value + 0x140) = 0x130;
    *(undefined1 *)(value + 0x75) = 0xff;
    CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004c2c98);
    *(undefined2 *)(entry + 0x48) = 0;
    value = RandomModulo(0x32);
    *(int *)(entry + 0x4c) = &((EntitySceneObject *)value)->x;
    *(undefined4 *)(entry + 0x50) = 0;
  }
  return;
}

