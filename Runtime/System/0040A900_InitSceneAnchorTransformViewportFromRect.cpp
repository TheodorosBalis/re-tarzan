#include "tarzan_ghidra_types.hpp"

// Address: 0x0040A900
// Label: InitSceneAnchorTransformViewportFromRect
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitSceneAnchorTransformViewportFromRect(int arg1)

{
  short *value;
  
  value = *(short **)(arg1 + 0xc4);
  ComputeSceneAnchorViewportScale(arg1,value);
  *(undefined4 *)(arg1 + 100) = 1;
  *(int *)(arg1 + 0x18) = ((int)value[2] - (int)*value >> 1) + (int)*value;
  *(int *)(arg1 + 0x1c) = ((int)value[3] - (int)value[1] >> 1) + (int)value[1];
  return;
}

