#include "tarzan_ghidra_types.hpp"

// Address: 0x00487B80
// Label: TrashingTheCamp::InitScriptedCampPropB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitScriptedCampPropB(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x3330;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    ((EntitySceneObject *)value)->roll = 1;
    CEntities::SetEntitySceneObjectScriptAttachment
              (entry,&g_TrashingTheCampRunningGorillaBScriptDesc);
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

