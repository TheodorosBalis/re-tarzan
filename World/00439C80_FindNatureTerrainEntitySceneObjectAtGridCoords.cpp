#include "tarzan_ghidra_types.hpp"

// Address: 0x00439C80
// Label: FindNatureTerrainEntitySceneObjectAtGridCoords
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int FindNatureTerrainEntitySceneObjectAtGridCoords(undefined4 arg1)

{
  int foundIndex;
  
  foundIndex = FindNatureTerrainCellIndexAtGridCoords(arg1,g_NatureTerrainDataBlock + 0x3c);
  if (foundIndex != -1) {
    return *(int *)(foundIndex * 4 + g_NatureTerrainEntitySceneObjectOffsetTable) + foundIndex * 4 +
           g_NatureTerrainEntitySceneObjectOffsetTable;
  }
  return 0;
}

