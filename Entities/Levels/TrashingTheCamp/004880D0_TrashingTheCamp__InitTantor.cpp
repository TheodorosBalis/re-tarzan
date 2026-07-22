#include "tarzan_ghidra_types.hpp"

// Address: 0x004880D0
// Label: TrashingTheCamp::InitTantor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitTantor(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x34d0;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    ((EntitySceneObject *)value)->roll = 1;
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_TrashingTheCampTantorScriptDesc);
    CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
    *(undefined4 *)(entry + 0x4c) = 1;
    *(undefined4 *)(entry + 0x50) = 0;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

