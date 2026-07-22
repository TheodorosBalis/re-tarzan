#include "tarzan_ghidra_types.hpp"

// Address: 0x00430560
// Label: CEntities::EaseEntitySceneObjectToCurrentJungleSurfaceAngles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::EaseEntitySceneObjectToCurrentJungleSurfaceAngles(undefined4 entry6,int sceneObject)

{
  int entry;
  int *intCursor;
  int entry2;
  uint value;
  int entry3;
  int *intCursor2;
  int entry4;
  int entry5;
  
  intCursor = (int *)GetJungleSurfaceSegment
                            (*(undefined4 *)(sceneObject + 0x110),*(undefined4 *)(sceneObject + 0x10c));
  if (*(char *)(sceneObject + 0x75) == '\0') {
    if ((intCursor[5] & 0x2000U) != 0) {
      return;
    }
    intCursor2 = intCursor + 7;
  }
  else {
    if (intCursor[3] == 0) {
      return;
    }
    intCursor2 = intCursor + -7;
  }
  entry3 = intCursor2[1];
  entry = intCursor[1];
  entry5 = *intCursor2 - *intCursor;
  entry4 = intCursor2[2] - intCursor[2];
  entry2 = SqrtToInt(entry4 * entry4 + entry5 * entry5);
  value = GetAngleFromXZVector12Bit(entry3 - entry,entry2 >> 6);
  entry3 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(sceneObject + 0xa0),value & 0xfff);
  *(short *)(sceneObject + 0xa0) = *(short *)(sceneObject + 0xa0) + (short)(entry3 >> 4);
  entry3 = GetAngleFromXZVector12Bit(entry5,entry4);
  entry3 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(sceneObject + 0xa2),entry3 - 0x800U & 0xfff);
  *(short *)(sceneObject + 0xa2) = *(short *)(sceneObject + 0xa2) + (short)(entry3 >> 4);
  return;
}

