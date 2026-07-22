#include "tarzan_ghidra_types.hpp"

// Address: 0x00430C40
// Label: CEntities::CanAnimalTraverseJungleSurfaceDistance
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint CEntities::CanAnimalTraverseJungleSurfaceDistance(undefined4 entry,int sceneObject,int attachment)

{
  ushort *dataCursor;
  int value;
  uint value4;
  int value2;
  int value3;
  
  value4 = *(uint *)(sceneObject + 0x110);
  value2 = value4 * 4 + 4;
  dataCursor = (ushort *)(*(int *)(value2 + g_CollisionSurfaceTable) + value2 + g_CollisionSurfaceTable);
  if (*(char *)(sceneObject + 0x75) == '\0') {
    value2 = -attachment;
    while (value2 = *(int *)(sceneObject + 0x10c) + value2, value2 < 0) {
      if ((*(uint *)(dataCursor + 0x22) & 0xc000) == 0) {
        return 0;
      }
      value4 = (uint)dataCursor[0x24];
      value2 = value4 * 4 + 4;
      dataCursor = (ushort *)
               (*(int *)(value2 + g_CollisionSurfaceTable) + value2 + g_CollisionSurfaceTable);
      value2 = *(int *)(dataCursor + 2) - attachment;
    }
  }
  else {
    value2 = *(int *)(sceneObject + 0x10c) + attachment;
    value3 = *(int *)(dataCursor + 2);
    if (value3 < value2) {
      do {
        value2 = value2 - value3;
        if ((*(uint *)(dataCursor + (uint)*dataCursor * 0xe + 0x14) & 0xc000) == 0) {
          return 0;
        }
        value4 = (uint)dataCursor[(uint)*dataCursor * 0xe + 0x16];
        value = value4 * 4 + 4;
        value = *(int *)(value + g_CollisionSurfaceTable) + value;
        value3 = *(int *)(value + 4 + g_CollisionSurfaceTable);
        dataCursor = (ushort *)(value + g_CollisionSurfaceTable);
      } while (value3 < value2);
    }
  }
  value2 = GetJungleSurfaceSegment(value4,value2);
  if ((*(uint *)(value2 + 0x14) & 0x800) == 0) {
    return *(uint *)(value2 + 0x14) >> 8 & 1;
  }
  return 1;
}

