#include "tarzan_ghidra_types.hpp"

// Address: 0x00487DA0
// Label: TrashingTheCamp::InitCivetCub
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitCivetCub(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    if (entity->descriptor != 0) {
      *(undefined4 *)(value + 0x6c) = *(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 8)
      ;
    }
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0xb60;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_TrashingTheCampCivetCubScriptDesc);
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

