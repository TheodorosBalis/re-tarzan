#include "tarzan_ghidra_types.hpp"

// Address: 0x0044AFE0
// Label: CEntities::UpdateBouncingPickupMotionAndLifetime
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::UpdateBouncingPickupMotionAndLifetime(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort verticalVelocity;
  int sceneObject;
  char bounceResult;
  int motionAttachment;
  uint facingIndex;
  undefined4 bounceSoundId;
  
  sceneObject = entity->sceneObjects;
  if (sceneObject != 0) {
    motionAttachment = CEntities::FindEntityAttachmentByFlags(entry,0x40000063);
    if (motionAttachment != 0) {
      if ((*(byte *)(motionAttachment + 0x1e) & 0x80) != 0) {
        verticalVelocity = *(ushort *)(motionAttachment + 0x12);
        if ((short)verticalVelocity < 0) {
          *(short *)(motionAttachment + 0x10) = *(short *)(motionAttachment + 0x10) + verticalVelocity;
          if (*(short *)(motionAttachment + 0x10) < 1) {
            *(undefined2 *)(motionAttachment + 0x10) = 0;
            *(ushort *)(motionAttachment + 0x12) = ~verticalVelocity + 1;
          }
          ((EntitySceneObject *)sceneObject)->y = ((EntitySceneObject *)sceneObject)->y - (int)*(short *)(motionAttachment + 0x10);
          if ((*(byte *)(motionAttachment + 0x1e) & 1) == 0) {
            ComputeEntitySceneObjectCollisionMoveDelta(0,0,sceneObject);
          }
          else {
            *(short *)(motionAttachment + 0xc) = *(short *)(motionAttachment + 0xc) - *(short *)(motionAttachment + 0xe);
            ComputeEntitySceneObjectCollisionMoveDelta((int)*(short *)(motionAttachment + 0xc),0,sceneObject);
            ((EntitySceneObject *)sceneObject)->x = ((EntitySceneObject *)sceneObject)->x + *(int *)(sceneObject + 0x54);
            ((EntitySceneObject *)sceneObject)->z = ((EntitySceneObject *)sceneObject)->z + *(int *)(sceneObject + 0x5c);
          }
          if ((*(byte *)(motionAttachment + 0x1e) & 4) != 0) {
            *(short *)(motionAttachment + 0x1a) = *(short *)(motionAttachment + 0x1a) + *(short *)(motionAttachment + 0x14);
            *(short *)(motionAttachment + 0x14) = *(short *)(motionAttachment + 0x14) - *(short *)(motionAttachment + 0x16);
            facingIndex = *(ushort *)(sceneObject + 0x132) - 0x400 & 0xfff;
            *(int *)(sceneObject + 0x3c) =
                 (int)(short)(&g_SinCosTable12Bit)[facingIndex - 0x400 & 0xfff] *
                 (int)*(short *)(motionAttachment + 0x1a) >> 0xc;
            *(int *)(sceneObject + 0x44) =
                 (int)(short)(&g_SinCosTable12Bit)[facingIndex] * (int)*(short *)(motionAttachment + 0x1a) >> 0xc;
          }
        }
        else {
          *(short *)(motionAttachment + 0x10) = *(short *)(motionAttachment + 0x10) + verticalVelocity;
          ((EntitySceneObject *)sceneObject)->y = ((EntitySceneObject *)sceneObject)->y + (int)*(short *)(motionAttachment + 0x10);
          if ((*(byte *)(motionAttachment + 0x1e) & 1) == 0) {
            ComputeEntitySceneObjectCollisionMoveDelta(0,0,sceneObject);
          }
          else {
            *(short *)(motionAttachment + 0xc) = *(short *)(motionAttachment + 0xc) - *(short *)(motionAttachment + 0xe);
            ComputeEntitySceneObjectCollisionMoveDelta((int)*(short *)(motionAttachment + 0xc),0,sceneObject);
            ((EntitySceneObject *)sceneObject)->x = ((EntitySceneObject *)sceneObject)->x + *(int *)(sceneObject + 0x54);
            ((EntitySceneObject *)sceneObject)->z = ((EntitySceneObject *)sceneObject)->z + *(int *)(sceneObject + 0x5c);
          }
          if ((*(byte *)(motionAttachment + 0x1e) & 4) != 0) {
            *(short *)(motionAttachment + 0x1a) = *(short *)(motionAttachment + 0x1a) + *(short *)(motionAttachment + 0x14);
            *(short *)(motionAttachment + 0x14) = *(short *)(motionAttachment + 0x14) - *(short *)(motionAttachment + 0x16);
            facingIndex = *(ushort *)(sceneObject + 0x132) - 0x400 & 0xfff;
            *(int *)(sceneObject + 0x3c) =
                 (int)(short)(&g_SinCosTable12Bit)[facingIndex - 0x400 & 0xfff] *
                 (int)*(short *)(motionAttachment + 0x1a) >> 0xc;
            *(int *)(sceneObject + 0x44) =
                 (int)(short)(&g_SinCosTable12Bit)[facingIndex] * (int)*(short *)(motionAttachment + 0x1a) >> 0xc;
          }
          bounceResult = CEntities::CheckEntitySceneObjectVerticalImpact(sceneObject);
          if (bounceResult != '\0') {
            *(short *)(motionAttachment + 0x10) = *(short *)(motionAttachment + 0x10) >> 1;
            *(ushort *)(motionAttachment + 0x12) = ~*(ushort *)(motionAttachment + 0x12) + 1;
            if (*(short *)(motionAttachment + 0x10) < 8) {
              *(byte *)(motionAttachment + 0x1e) = *(byte *)(motionAttachment + 0x1e) & 0x7f;
            }
            bounceResult = *(char *)(motionAttachment + 0x1f);
            *(short *)(motionAttachment + 0xc) = *(short *)(motionAttachment + 0xc) >> 1;
            *(short *)(motionAttachment + 0x14) = *(short *)(motionAttachment + 0x14) >> 1;
            *(byte *)(motionAttachment + 0x1e) = *(byte *)(motionAttachment + 0x1e) | 0x40;
            if (bounceResult != '\0') {
              if (bounceResult == '\x02') {
                bounceSoundId = 0xb2;
              }
              else if (bounceResult == '\x03') {
                bounceSoundId = 0xb1;
              }
              else {
                bounceSoundId = 0xb3;
              }
              PlayAudioById(bounceSoundId,(int *)0,(undefined4 *)&((EntitySceneObject *)sceneObject)->x);
              *(char *)(motionAttachment + 0x1f) = *(char *)(motionAttachment + 0x1f) + -1;
            }
          }
        }
      }
      *(short *)(motionAttachment + 0x1c) = *(short *)(motionAttachment + 0x1c) + -1;
      if (*(short *)(motionAttachment + 0x1c) < 0) {
        CEntities::SpawnEntityByTypeAtPosition
                  (((EntitySceneObject *)sceneObject)->x,((EntitySceneObject *)sceneObject)->y,
                   ((EntitySceneObject *)sceneObject)->z,0x13,0x11);
        return 1;
      }
    }
  }
  return 0;
}

