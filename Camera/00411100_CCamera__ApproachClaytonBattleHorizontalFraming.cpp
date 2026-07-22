#include "tarzan_ghidra_types.hpp"

#define g_ClaytonEntity (*(Entity **)0x0051C678)
#define g_PlayerEntitySceneObjectData (*(int *)0x0051CDAC)

// Address: 0x00411100
// Label: CCamera::ApproachClaytonBattleHorizontalFraming
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CCamera::ApproachClaytonBattleHorizontalFraming(int *cameraTargetPose,int xOffset)

{
  int *targetPose;
  int currentValue;
  int targetValue;
  int horizontalFraming;
  
  targetPose = cameraTargetPose;
  targetValue = (((EntitySceneObject *)g_ClaytonEntity->sceneObjects)->x +
          *(int *)(g_PlayerEntitySceneObjectData + 8)) / 2;
  currentValue = *targetPose;
  if (currentValue != targetValue) {
    if (currentValue < targetValue) {
      *targetPose = currentValue + 0x40;
      if (currentValue + 0x40 <= targetValue) goto LAB_0041113d;
    }
    else {
      *targetPose = currentValue + -0x40;
      if (targetValue <= currentValue + -0x40) goto LAB_0041113d;
    }
    *targetPose = targetValue;
  }
LAB_0041113d:
  horizontalFraming = targetPose[5];
  targetValue = xOffset + horizontalFraming * 2;
  targetValue = horizontalFraming + targetValue + 500;
  targetValue = (int)(targetValue + (targetValue >> 0x1f & 3U)) >> 2;
  if (horizontalFraming != targetValue) {
    if (horizontalFraming < targetValue) {
      targetPose[5] = horizontalFraming + 0x32;
      if (targetValue < horizontalFraming + 0x32) {
        targetPose[5] = targetValue;
        return;
      }
    }
    else {
      targetPose[5] = horizontalFraming + -0x32;
      if (horizontalFraming + -0x32 < targetValue) {
        targetPose[5] = targetValue;
      }
    }
  }
  return;
}
