#include "tarzan_ghidra_types.hpp"

// Address: 0x00439CC0
// Label: ConvertWorldPosToNatureTerrainGridCoords
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ConvertWorldPosToNatureTerrainGridCoords(int *arg1,int *arg2)

{
  int value;
  
  value = *arg1;
  if (value < 0) {
    value = (value - g_NatureTerrainCellSizeX) + 1;
  }
  *arg2 = value;
  value = arg1[1];
  if (value < 0) {
    value = (value - g_NatureTerrainCellSizeY) + 1;
  }
  arg2[1] = value;
  value = arg1[2];
  if (value < 0) {
    value = (value - g_NatureTerrainCellSizeZ) + 1;
  }
  arg2[2] = value;
  *arg2 = *arg2 / g_NatureTerrainCellSizeX;
  arg2[1] = arg2[1] / g_NatureTerrainCellSizeY;
  arg2[2] = arg2[2] / g_NatureTerrainCellSizeZ;
  return;
}

