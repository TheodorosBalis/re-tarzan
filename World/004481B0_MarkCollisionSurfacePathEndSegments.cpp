#include "tarzan_ghidra_types.hpp"

// Address: 0x004481B0
// Label: MarkCollisionSurfacePathEndSegments
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void MarkCollisionSurfacePathEndSegments(void)

{
  int value;
  ushort *dataCursor;
  int value2;
  int value3;
  
  value3 = 0;
  if (0 < *g_CollisionSurfaceTable) {
    value2 = 4;
    do {
      value = *(int *)(value2 + (int)g_CollisionSurfaceTable) + value2;
      value2 = value2 + 4;
      dataCursor = (ushort *)(value + (int)g_CollisionSurfaceTable);
      value3 = value3 + 1;
      *(uint *)(dataCursor + (uint)*dataCursor * 0xe + 0x14) =
           *(uint *)(dataCursor + (uint)*dataCursor * 0xe + 0x14) | 0x2000;
    } while (value3 < *g_CollisionSurfaceTable);
  }
  return;
}

