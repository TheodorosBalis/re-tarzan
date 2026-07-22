#include "tarzan_ghidra_types.hpp"

// Address: 0x0040AFD0
// Label: CampsiteCommotion::InitBarrelEnemy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitBarrelEnemy(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x1ba0;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    ((EntitySceneObject *)value)->roll = 0;
    CEntities::MoveEntitySceneObjectAndSnapFacingAngles(entry,0);
    CEntities::SetEntitySceneObjectScriptAttachment
              (entry,&g_CampsiteCommotionBarrelEnemyScriptDesc);
    *(undefined2 *)(entry + 0x48) = 0;
    *(undefined4 *)(entry + 0x4c) = 0;
    *(undefined2 *)(entry + 0x4a) = 0;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

