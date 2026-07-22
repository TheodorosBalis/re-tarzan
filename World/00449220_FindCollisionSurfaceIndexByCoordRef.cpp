#include "tarzan_ghidra_types.hpp"

// Address: 0x00449220
// Label: FindCollisionSurfaceIndexByCoordRef
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int FindCollisionSurfaceIndexByCoordRef(int arg1)

{
  int foundIndex;
  int foundIndex2;
  int foundIndex3;
  
  foundIndex = 0;
  if (0 < *g_CollisionSurfaceTable) {
    foundIndex3 = 4;
    do {
      foundIndex2 = *(int *)(foundIndex3 + (int)g_CollisionSurfaceTable) + foundIndex3;
      if (((*(byte *)((int)g_CollisionSurfaceTable + foundIndex2 + 9) & 0x80) == 0) &&
         (*(int *)((int)g_CollisionSurfaceTable + foundIndex2 + 0xc) == arg1)) {
        return foundIndex;
      }
      foundIndex = foundIndex + 1;
      foundIndex3 = foundIndex3 + 4;
    } while (foundIndex < *g_CollisionSurfaceTable);
  }
  return -1;
}

