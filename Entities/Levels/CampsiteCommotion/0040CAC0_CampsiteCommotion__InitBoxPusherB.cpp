#include "tarzan_ghidra_types.hpp"

// Address: 0x0040CAC0
// Label: CampsiteCommotion::InitBoxPusherB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitBoxPusherB(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x1c08;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->yaw = 0xf672;
    *(int *)(value + 0x3c) = g_LevelEntityInitScratch_Field186C * 0x230 >> 0xc;
    value2 = (int)g_LevelEntityInitScratch_Field106C;
    *(undefined4 *)(value + 0x6c) = 0xfffffed4;
    *(int *)(value + 0x44) = value2 * 0x230 >> 0xc;
    CEntities::SetEntitySceneObjectScriptAttachment
              (entry,&g_CampsiteCommotionBoxPusherBScriptDesc);
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

