#include "tarzan_ghidra_types.hpp"

// Address: 0x0040CB90
// Label: CampsiteCommotion::InitBoxPusherA
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitBoxPusherA(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x1c08;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->yaw = 0xfe72;
    *(int *)(value + 0x3c) = ((int)g_LevelEntityInitScratch_Field086C << 9) >> 0xc;
    *(int *)(value + 0x44) = ((int)g_LevelEntityInitScratch_Field006C << 9) >> 0xc;
    CEntities::SetEntitySceneObjectScriptAttachment
              (entry,&g_CampsiteCommotionBoxPusherAScriptDesc);
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

