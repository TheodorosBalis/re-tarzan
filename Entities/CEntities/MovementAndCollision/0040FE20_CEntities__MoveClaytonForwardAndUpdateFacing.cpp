#include "tarzan_ghidra_types.hpp"

// Address: 0x0040FE20
// Label: CEntities::MoveClaytonForwardAndUpdateFacing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::MoveClaytonForwardAndUpdateFacing(undefined4 entry,int sceneObject,int attachment)

{
  if (*(char *)(sceneObject + 0x75) != '\0') {
    attachment = -attachment;
  }
  ComputeEntitySceneObjectCollisionMoveDelta(attachment,0,sceneObject);
  *(int *)(sceneObject + 0x14) = *(int *)(sceneObject + 0x14) + *(int *)(sceneObject + 0x54);
  *(int *)(sceneObject + 0x18) = *(int *)(sceneObject + 0x18) + *(int *)(sceneObject + 0x58);
  *(int *)(sceneObject + 0x1c) = *(int *)(sceneObject + 0x1c) + *(int *)(sceneObject + 0x5c);
  *(ushort *)(sceneObject + 0xa2) = *(ushort *)(sceneObject + 0x132);
  if (*(char *)(sceneObject + 0x75) == '\0') {
    *(ushort *)(sceneObject + 0xa2) = *(ushort *)(sceneObject + 0x132) ^ 0x800;
    *(ushort *)(sceneObject + 0xa0) = 0x400U - *(short *)(sceneObject + 0x130) & 0xfff;
    return;
  }
  *(ushort *)(sceneObject + 0xa0) = *(short *)(sceneObject + 0x130) - 0x400U & 0xfff;
  return;
}

