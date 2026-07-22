#include "tarzan_ghidra_types.hpp"

// Address: 0x0040A890
// Label: ComputeSceneAnchorViewportScale
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComputeSceneAnchorViewportScale(int arg1,int arg2)

{
  short shortValue;
  
  *(undefined4 *)(arg1 + 0x5c) = 0x1000;
  *(int *)(arg1 + 0x58) = (g_SceneAnchorAspectHeightUnits << 0xc) / g_SceneAnchorAspectWidthUnits
  ;
  *(int *)(arg1 + 0x5c) = (*(short *)(arg2 + 6) * 0x1000) / 0xf0;
  shortValue = *(short *)(arg2 + 4);
  *(undefined4 *)(arg1 + 0x60) = 0x1000;
  *(int *)(arg1 + 0x58) = ((int)shortValue * *(int *)(arg1 + 0x58)) / 0xf0;
  return;
}

