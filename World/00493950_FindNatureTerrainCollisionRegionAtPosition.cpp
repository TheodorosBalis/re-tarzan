#include "tarzan_ghidra_types.hpp"

// Address: 0x00493950
// Label: FindNatureTerrainCollisionRegionAtPosition
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int * FindNatureTerrainCollisionRegionAtPosition(int *arg1)

{
  int *intCursor;
  int *intCursor2;
  int foundIndex;
  
  ResolveEntitySceneObjectPointers(&g_CurrentWorldSceneContext);
  foundIndex = *(int *)(*(int *)(g_NatureTerrainDataBlock + 0x14) + 0x14 + g_NatureTerrainDataBlock);
  intCursor2 = (int *)(*(int *)(g_NatureTerrainDataBlock + 0x14) + g_NatureTerrainDataBlock + 0x18);
  if (foundIndex != 0) {
    do {
      foundIndex = foundIndex + -1;
      intCursor = (int *)(*intCursor2 + (int)intCursor2);
      if ((((*intCursor <= *arg1) && (*arg1 <= intCursor[3])) && (intCursor[2] <= arg1[2])) &&
         (arg1[2] <= intCursor[5])) {
        return intCursor;
      }
      intCursor2 = intCursor2 + 1;
    } while (foundIndex != 0);
  }
  return (int *)0x0;
}

