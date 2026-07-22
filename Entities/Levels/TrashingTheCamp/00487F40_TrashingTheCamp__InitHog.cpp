#include "tarzan_ghidra_types.hpp"

// Address: 0x00487F40
// Label: TrashingTheCamp::InitHog
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitHog(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x410;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_TrashingTheCampHogScriptDesc);
    *(undefined4 *)(entry + 0x50) = 0;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

