#include "tarzan_ghidra_types.hpp"

// Address: 0x00401F50
// Label: TheBaboonChase::InitJaneSurfingTransition
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::InitJaneSurfingTransition(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  undefined4 value4;
  int value3;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x2d8;
    *(undefined2 *)(value + 0xc) = 0;
    ((EntitySceneObject *)value)->worldObject = value2;
    value4 = FindCollisionSurfaceIndexByCoordRef(99);
    ((EntitySceneObject *)value)->surfacePathIndex = value4;
    ((EntitySceneObject *)value)->surfaceIndex = 0;
    ((EntitySceneObject *)value)->pad108 = 1;
    UpdateEntityEntitySceneObjectTransformFromPlacement(value);
    *(undefined4 *)(value + 0xb4) = 1;
    ((EntitySceneObject *)value)->roll = 1;
    if (((EntitySceneObject *)value)->surfacePathIndex != -1) {
      ComputeEntitySceneObjectCollisionMoveDelta(0,0,value);
      ((EntitySceneObject *)value)->x = ((EntitySceneObject *)value)->x + *(int *)(value + 0x54);
      ((EntitySceneObject *)value)->z = ((EntitySceneObject *)value)->z + *(int *)(value + 0x5c);
      ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + *(int *)(value + 0x58) + -0x600;
      ((EntitySceneObject *)value)->yaw = *(undefined2 *)(value + 0x132);
    }
    value3 = CreateEntityEntitySceneObject((uint *)entry,2);
    value2 = g_WorldEntitySceneObjectArrayBase;
    if (value3 != 0) {
      *(undefined2 *)(value3 + 0xc) = 0x1ed;
      *(undefined4 *)(value3 + 0xb4) = 1;
      *(int *)(value3 + 0x10) = value2 + 0xd0;
      *(undefined2 *)(value3 + 0xa6) = 1;
      *(undefined2 *)(value3 + 0xa2) = ((EntitySceneObject *)value)->yaw;
    }
    PlayAudioById(0x226,(int *)&((EntitySceneObject *)value)->soundPosition,(undefined4 *)&((EntitySceneObject *)value)->x);
  }
  CEntities::AppendEntityToChildChain(g_PlayerEntity,entry);
  LoadEncodedResourceId(6);
  *(undefined2 *)(entry + 0x48) = 1;
  return;
}

