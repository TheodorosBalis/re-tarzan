#include "tarzan_ghidra_types.hpp"

// Address: 0x00487C20
// Label: TrashingTheCamp::InitRunningGorillaB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitRunningGorillaB(int entry)

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
    PlayAudioById(0x2aa,(int *)&((EntitySceneObject *)value)->soundPosition,(undefined4 *)&((EntitySceneObject *)value)->x);
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

