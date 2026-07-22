#include "tarzan_ghidra_types.hpp"

// Address: 0x0040D050
// Label: CampsiteCommotion::InitClayton
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitClayton(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x1728;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::MoveEntitySceneObjectAndSnapFacingAngles(entry,0);
    CEntities::SetEntitySceneObjectScriptAttachment
              (entry,&g_CampsiteCommotionScriptedCampPropEScriptDesc);
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

