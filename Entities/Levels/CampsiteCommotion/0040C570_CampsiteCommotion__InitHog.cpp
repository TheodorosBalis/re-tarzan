#include "tarzan_ghidra_types.hpp"

// Address: 0x0040C570
// Label: CampsiteCommotion::InitHog
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitHog(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  undefined **dataCursor;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x410;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    if (entity->descriptor != 0) {
      if (*(int *)(*(int *)(entity->descriptor + 0x10) + 4) == 0) {
        dataCursor = &g_CampsiteCommotionHogScriptDescB;
      }
      else {
        dataCursor = &g_CampsiteCommotionHogScriptDescA;
      }
      CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)dataCursor);
    }
  }
  *(undefined4 *)(entry + 0x50) = 0;
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

