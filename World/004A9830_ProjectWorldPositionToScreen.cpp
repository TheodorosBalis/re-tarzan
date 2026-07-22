#include "tarzan_ghidra_types.hpp"

// Address: 0x004A9830
// Label: ProjectWorldPositionToScreen
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ProjectWorldPositionToScreen(int *arg1,int *arg2,int *arg3)

{
  int value;
  undefined1 localState3 [4];
  undefined1 localState2 [4];
  undefined1 localState [4];
  
  UpdateRenderCameraState(arg2);
  SetTransformBasisFromRef(arg2 + 0x1a);
  ProjectTriangleVertexAndReturnScreenCoords
            ((float)(*arg1 - *arg2),(float)(arg1[1] - arg2[1]),
             (float)(arg1[2] - arg2[2]),localState2,localState3,localState);
  value = ConvertFpuTopToInt64();
  arg3[1] = ((value * 0xf0) / 0x1e0) * 0x100 | arg3[1] & 0xffU;
  value = ConvertFpuTopToInt64();
  *arg3 = ((value << 9) / 0x280) * 0x100;
  value = ConvertFpuTopToInt64();
  arg3[2] = value >> 2;
  return;
}

