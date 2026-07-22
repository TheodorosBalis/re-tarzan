#include "tarzan_ghidra_types.hpp"

// Address: 0x004834F0
// Label: CEntities::UpdateLeafSwimmingFish
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateLeafSwimmingFish(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  short *value6;
  short shortValue;
  char resultFlag;
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x40000000);
  if (value == 0) goto LAB_004837d5;
  CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  AdvanceRuntimePathAttachmentFromEntitySceneObject(entry);
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x20000000);
  if (value2 == 0) goto LAB_004837d5;
  if (*(int *)(value2 + 0x4c) == 0) {
    value3 = *(int *)(value2 + 0x30);
    *(undefined4 *)(value2 + 0x28) = 0;
    value = (((int)(short)(&g_SinCosTable12Bit)[value3 - 0x400U & 0xfff] << 8) >> 0xc) -
            ((EntitySceneObject *)value)->z;
LAB_00483609:
    *(uint *)(value2 + 0x30) = *(int *)(value2 + 0x44) + value3 & 0xfff;
    value3 = entity->sceneObjects;
    value = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value3)->yaw,value + 0x800);
    value6 = (short *)(&((EntitySceneObject *)value3)->yaw);
    *value6 = *value6 + (short)(value >> 3);
  }
  else if (*(int *)(value2 + 0x4c) == 1) {
    *(undefined4 *)(value2 + 0x5c) = 0x100;
    if (*(int *)(value2 + 0x50) < 0x2000) {
      *(int *)(value2 + 0x50) = *(int *)(value2 + 0x50) + *(int *)(value2 + 0x58);
      *(int *)(value2 + 0x58) = *(int *)(value2 + 0x58) + 0x100;
    }
    if (*(int *)(value2 + 0x28) == 0) {
      value3 = GetAngleFromXZVector12Bit
                        (-(*(int *)(entity->sceneObjects + 0x14) -
                          *(int *)(g_PlayerEntitySceneObjectData + 8)),
                         *(int *)(entity->sceneObjects + 0x1c) -
                         *(int *)(g_PlayerEntitySceneObjectData + 0x10));
      *(uint *)(value2 + 0x28) = ((-1 < (value3 + -0x800) * 0x100000) - 1 & 0x400) - 0x200;
    }
    value3 = *(int *)(value2 + 0x30);
    value = ((((int)(short)(&g_SinCosTable12Bit)[value3 - 0x400U & 0xfff] << 6) >> 0xc) -
            ((EntitySceneObject *)value)->z) + *(int *)(value2 + 0x28);
    goto LAB_00483609;
  }
  value = entity->sceneObjects;
  value3 = *(int *)(g_PlayerEntity + 0x38);
  value4 = ((EntitySceneObject *)value3)->x - ((EntitySceneObject *)value)->x;
  value5 = ((EntitySceneObject *)value3)->y - ((EntitySceneObject *)value)->y;
  value3 = ((EntitySceneObject *)value3)->z - ((EntitySceneObject *)value)->z;
  value = *(int *)(value2 + 0x38);
  *(uint *)(value2 + 0x4c) = (uint)(value3 * value3 + value5 * value5 + value4 * value4 < 0x40000);
  *(int *)(value2 + 0x38) = value + -1;
  if (value == 0) {
    value = entity->sceneObjects;
    value = CEntities::SpawnEntityByTypeAtPosition
                      (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                       ((EntitySceneObject *)value)->z,0x19f,0x11);
    if (value != 0) {
      value = CEntities::FindEntityAttachmentByFlags(value,0x10000000);
      if (value != 0) {
        ((EntitySceneObject *)value)->worldObject = *(int *)(entity->sceneObjects + 0x18) + -0x60;
      }
    }
    value = RandomModulo(0x20);
    *(int *)(value2 + 0x38) = value + 8;
  }
  value = entity->sceneObjects;
  value2 = *(int *)(value2 + 0x50) >> 8;
  shortValue = (&g_SinCosTable12Bit)[(int)((EntitySceneObject *)value)->yaw & 0xfff];
  ((EntitySceneObject *)value)->x =
       ((EntitySceneObject *)value)->x +
       ((short)(&g_SinCosTable12Bit)[(int)((EntitySceneObject *)value)->yaw - 0x400U & 0xfff] * value2 >> 0xc)
  ;
  intCursor = (int *)(entity->sceneObjects + 0x1c);
  *intCursor = *intCursor + (shortValue * value2 >> 0xc);
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000018);
  if (value != 0) {
    value2 = g_LeafSwimmingBoundarySurfaceIndexA * 4 + 4;
    *(int *)(value + 0xc) =
         *(int *)(value2 + g_CollisionSurfaceTable) + value2 + g_CollisionSurfaceTable;
    UpdatePathFollowerAttachmentNearestSegment(value,entity->sceneObjects + 0x14);
    PushEntitySceneObjectOutsidePathBoundaryRadiusXZ
              (entity->sceneObjects,((EntitySceneObject *)value)->worldObject,0,&((EntitySceneObject *)value)->y,0x20);
  }
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000019);
  if (value != 0) {
    value2 = g_LeafSwimmingBoundarySurfaceIndexB * 4 + 4;
    *(int *)(value + 0xc) =
         *(int *)(value2 + g_CollisionSurfaceTable) + value2 + g_CollisionSurfaceTable;
    UpdatePathFollowerAttachmentNearestSegment(value,entity->sceneObjects + 0x14);
    PushEntitySceneObjectOutsidePathBoundaryRadiusXZ
              (entity->sceneObjects,((EntitySceneObject *)value)->worldObject,1,&((EntitySceneObject *)value)->y,0x20);
  }
LAB_004837d5:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

