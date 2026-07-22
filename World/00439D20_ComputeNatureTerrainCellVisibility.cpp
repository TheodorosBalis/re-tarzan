#include "tarzan_ghidra_types.hpp"

// Address: 0x00439D20
// Label: ComputeNatureTerrainCellVisibility
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ComputeNatureTerrainCellVisibility(short *arg1)

{
  short localState4;
  short localState6;
  short localState3;
  short localState5;
  short localState2;
  short localState;
  
  localState4 = *arg1 * (short)g_NatureTerrainCellSizeX - (short)g_CameraFocusX;
  localState6 = arg1[2] * (short)g_NatureTerrainCellSizeY - (short)g_CameraFocusY;
  localState3 = arg1[4] * (short)g_NatureTerrainCellSizeZ - (short)g_CameraFocusZ;
  localState5 = (short)g_NatureTerrainCellSizeX + localState4;
  localState2 = (short)g_NatureTerrainCellSizeY + localState6;
  localState = (short)g_NatureTerrainCellSizeZ + localState3;
  ClassifyLocalBoundsVisibility(&localState4);
  return 0;
}

