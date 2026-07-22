#include "tarzan_ghidra_types.hpp"

// Address: 0x00487460
// Label: TrashingTheCamp::InitRunningCampProp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitRunningCampProp(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x3400;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw + 0x400;
    ((EntitySceneObject *)value)->roll = 1;
    *(undefined2 *)(entry + 0x48) = 0;
    CEntities::SetEntitySceneObjectScriptAttachment
              (entry,&g_TrashingTheCampRunningCampPropScriptDesc);
  }
  return;
}

