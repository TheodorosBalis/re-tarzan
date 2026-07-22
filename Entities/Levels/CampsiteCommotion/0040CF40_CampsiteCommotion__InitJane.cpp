#include "tarzan_ghidra_types.hpp"

// Address: 0x0040CF40
// Label: CampsiteCommotion::InitJane
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitJane(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x16c0;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::SetEntitySceneObjectScriptAttachment
              (entry,&g_CampsiteCommotionScriptedCampPropCScriptDesc);
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

