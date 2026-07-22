#include "tarzan_ghidra_types.hpp"

// Address: 0x0040CCF0
// Label: CampsiteCommotion::InitFallingCampDebris
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitFallingCampDebris(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  int value;
  undefined4 value4;
  int value2;
  int value3;
  
  value4 = g_CurrentWorldSceneContext;
  value = entity->sceneObjects;
  if (value != 0) {
    *(undefined2 *)(value + 0xc) = 0x2001;
    ((EntitySceneObject *)value)->worldObject = value4;
    ((EntitySceneObject *)value)->surfacePathIndex = *(undefined4 *)(g_PlayerEntitySceneObject + 0x110);
    value4 = *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
    ((EntitySceneObject *)value)->pad108 = 1;
    ((EntitySceneObject *)value)->surfaceIndex = value4;
    UpdateEntityEntitySceneObjectTransformFromPlacement(value);
    intCursor = (int *)(&((EntitySceneObject *)value)->x);
    *intCursor = ((EntitySceneObject *)value)->x + *(int *)(value + 0x54);
    ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + *(int *)(value + 0x58) + -0x600;
    ((EntitySceneObject *)value)->z = ((EntitySceneObject *)value)->z + *(int *)(value + 0x5c);
    value2 = CEntities::CreateRuntimeMotionStateAttachment(entry);
    if (value2 != 0) {
      *(undefined4 *)(value2 + 0x20) = 0;
      *(undefined4 *)(value2 + 0x24) = 8;
      *(undefined4 *)(value2 + 0x2c) = 0x60;
    }
    value3 = CreateEntityEntitySceneObject((uint *)entry,2);
    value2 = g_WorldEntitySceneObjectArrayBase;
    if (value3 != 0) {
      *(undefined2 *)(value3 + 0xc) = 0x2010;
      *(int *)(value3 + 0x10) = value2 + 0x3a8;
      *(int *)(value3 + 0x14) = *intCursor;
      *(undefined4 *)(value3 + 0x18) = ((EntitySceneObject *)value)->y;
      value4 = ((EntitySceneObject *)value)->z;
      *(ushort *)(value3 + 0xe) = *(ushort *)(value3 + 0xe) | 0x441;
      *(undefined4 *)(value3 + 0x1c) = value4;
      *(undefined4 *)(value3 + 0x6c) = 0xffffffe2;
      *(undefined4 *)(value3 + 0x30) = 0;
      *(undefined4 *)(value3 + 0xb4) = 1;
      *(undefined4 *)(value3 + 0xa8) = 0x3000;
      *(undefined4 *)(value3 + 0xac) = 0x3000;
      *(undefined4 *)(value3 + 0xb0) = 0x3000;
    }
    PlayAudioById(0x2d2,(int *)0,(undefined4 *)intCursor);
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

