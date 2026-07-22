#include "tarzan_ghidra_types.hpp"

// Address: 0x0040B790
// Label: CampsiteCommotion::InitWorkerEnemy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitWorkerEnemy(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  undefined *dataCursor;
  
  value = entity->sceneObjects;
  if (value != 0) {
    if (entity->descriptor == 0) {
      value2 = 0;
    }
    else {
      value2 = *(int *)(*(int *)(entity->descriptor + 0x10) + 4);
    }
    *(int *)(entry + 0x50) = value2;
    if (value2 == 1) {
      dataCursor = &g_CampsiteCommotionWorkerEnemyScriptDescB;
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x1a68;
      *(undefined4 *)(entry + 0x4c) = 0x10;
      *(undefined4 *)(value + 0x70) = 2;
    }
    else if (value2 == 2) {
      dataCursor = &g_CampsiteCommotionWorkerEnemyScriptDescC;
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x1a68;
      *(undefined4 *)(entry + 0x4c) = 0x20;
      *(undefined4 *)(value + 0x70) = 1;
    }
    else if (value2 == 3) {
      dataCursor = &g_CampsiteCommotionWorkerEnemyScriptDescD;
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x1b38;
      *(undefined4 *)(entry + 0x4c) = 0x20;
      *(undefined4 *)(value + 0x70) = 1;
    }
    else {
      dataCursor = &g_CampsiteCommotionWorkerEnemyScriptDescA;
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x1a68;
      *(undefined4 *)(entry + 0x4c) = 0x1b;
      *(undefined4 *)(value + 0x70) = 0;
    }
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)dataCursor);
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 2;
    ((EntitySceneObject *)value)->roll = 0;
    *(undefined2 *)(entry + 0x48) = 0;
    CEntities::MoveEntitySceneObjectAndSnapFacingAngles(entry,0);
    CEntities::LinkEntityIntoProcessingList(&g_CampsiteCommotionWorkerEnemyListHead,entry);
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

