#include "tarzan_ghidra_types.hpp"

// Address: 0x0040A5E0
// Label: UpdateRenderCameraState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateRenderCameraState(int cameraState)

{
  Entity *entity = (Entity *)cameraState;
  int value;
  int value2;
  undefined4 localState4 [2];
  undefined4 localState3;
  undefined1 localState2 [16];
  undefined1 localState [32];
  
  if (*(int *)(cameraState + 0x48) != 0) {
    *(int *)(cameraState + 0x48) = *(int *)(cameraState + 0x48) + -1;
  }
  BuildBasisMatrixFromEulerAngles(cameraState + 0x30,localState);
  TransformVectorByBasis(localState,cameraState,localState4);
  value = cameraState + 0x68;
  localState4[0] = 0;
  localState3 = 0;
  BuildBasisMatrixFromEulerAngles(cameraState + 0x50,value);
  if (*(int *)(cameraState + 100) != 0) {
    ScaleBasisAxesClamped(value,cameraState + 0x58);
  }
  TransformVectorByBasis(value,localState4,localState2);
  MultiplyBasisMatrices(value,localState,value);
  *(undefined4 *)(cameraState + 0x84) = *(undefined4 *)(cameraState + 0x14);
  value = entity->previous * *(int *)(cameraState + 0x58);
  *(int *)(cameraState + 0x7c) = (int)(value + (value >> 0x1f & 0xfffU)) >> 0xc;
  value = entity->next * *(int *)(cameraState + 0x5c);
  *(int *)(cameraState + 0x80) = (int)(value + (value >> 0x1f & 0xfffU)) >> 0xc;
  if (*(int *)(cameraState + 0x48) != 0) {
    value = RandomModulo(*(int *)(cameraState + 0x4c) << 2);
    value2 = RandomModulo(*(int *)(cameraState + 0x4c) << 1);
    *(int *)(cameraState + 0x80) = *(int *)(cameraState + 0x80) + (value - value2);
  }
  _g_RenderCameraScaleBasisXX = *(undefined2 *)(cameraState + 0x58);
  _g_RenderCameraScaleBasisXY = 0;
  _g_RenderCameraScaleBasisXZ = 0;
  _g_RenderCameraScaleBasisYX = 0;
  _g_RenderCameraScaleBasisYY = *(undefined2 *)(cameraState + 0x5c);
  _g_RenderCameraScaleBasisYZ = 0;
  _g_RenderCameraScaleBasisZX = 0;
  _g_RenderCameraScaleBasisZY = 0;
  _g_RenderCameraScaleBasisZZ = *(undefined2 *)(cameraState + 0x60);
  ApplyAnchorProjectionParams(cameraState);
  return;
}

