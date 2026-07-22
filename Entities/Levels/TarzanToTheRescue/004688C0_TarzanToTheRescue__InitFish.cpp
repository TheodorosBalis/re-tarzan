#include "tarzan_ghidra_types.hpp"

// Address: 0x004688C0
// Label: TarzanToTheRescue::InitFish
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitFish(int entry)

{
  Entity *entity = (Entity *)entry;
  undefined2 value3;
  int value;
  int value2;
  undefined4 value4;
  
  value = CEntities::CreateEntityAttachment(entry,0x38,0x10000000);
  if (value == 0) {
    return;
  }
  *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2d18;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
  value3 = RandomModulo(0x1000);
  *(undefined2 *)(entity->sceneObjects + 0xa2) = value3;
  *(undefined4 *)(entity->sceneObjects + 0xa8) = 8000;
  *(undefined4 *)(entity->sceneObjects + 0xac) = 8000;
  *(undefined4 *)(entity->sceneObjects + 0xb0) = 8000;
  ((EntitySceneObject *)value)->worldObject = 0;
  value2 = entity->sceneObjects;
  ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value2)->x;
  ((EntitySceneObject *)value)->z = ((EntitySceneObject *)value2)->y;
  *(undefined4 *)(value + 0x20) = ((EntitySceneObject *)value2)->z;
  value2 = CEntities::SetEntitySceneObjectScriptAttachment
                    (entry,&g_TarzanToTheRescueScriptedRescueEffectScriptDesc);
  ((EntitySceneObject *)value)->worldObject = value2;
  if (value2 == 0) goto LAB_004689e0;
  value2 = RandomModulo(3);
  if (value2 == 0) {
    value4 = ((EntitySceneObject *)value)->worldObject;
LAB_0046899f:
    CEntities::SelectScriptAttachmentSequence(value4,0);
  }
  else {
    if (value2 == 1) {
      value4 = ((EntitySceneObject *)value)->worldObject;
      goto LAB_0046899f;
    }
    if (value2 == 2) {
      value4 = ((EntitySceneObject *)value)->worldObject;
      goto LAB_0046899f;
    }
  }
  value = entity->sceneObjects;
  CEntities::SpawnEntityByTypeAtPosition
            (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
             ((EntitySceneObject *)value)->z,0x193,0x11);
  value = entity->sceneObjects;
  CEntities::SpawnEntityByTypeAtPosition
            (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
             ((EntitySceneObject *)value)->z,0x195,0x11);
LAB_004689e0:
  *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  return;
}

