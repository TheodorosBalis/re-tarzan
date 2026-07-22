#include "tarzan_ghidra_types.hpp"

// Address: 0x00430630
// Label: CEntities::OrientEntitySceneObjectToAdjacentJungleSurfaceSegment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::OrientEntitySceneObjectToAdjacentJungleSurfaceSegment
               (undefined4 entry6,int sceneObject)

{
  int entry;
  int entry2;
  ushort value;
  short shortValue;
  int *intCursor;
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
  entry = intCursor2[1];
  entry2 = intCursor[1];
  entry4 = *intCursor2 - *intCursor;
  entry5 = intCursor2[2] - intCursor[2];
  entry3 = SqrtToInt(entry5 * entry5 + entry4 * entry4);
  value = GetAngleFromXZVector12Bit(entry - entry2,entry3 >> 6);
  *(ushort *)(sceneObject + 0xa0) = value & 0xfff;
  shortValue = GetAngleFromXZVector12Bit(entry4,entry5);
  *(ushort *)(sceneObject + 0xa2) = shortValue - 0x800U & 0xfff;
  return;
}

