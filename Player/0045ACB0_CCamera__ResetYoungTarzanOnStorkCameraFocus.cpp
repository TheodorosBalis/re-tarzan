#include "tarzan_ghidra_types.hpp"

// Address: 0x0045ACB0
// Label: CCamera::ResetYoungTarzanOnStorkCameraFocus
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CCamera::ResetYoungTarzanOnStorkCameraFocus(void)

{
  g_CameraFocusX = *(undefined4 *)(g_PlayerEntitySceneObjectData + 8);
  g_CameraFocusY = *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc);
  g_CameraFocusZ = *(undefined4 *)(g_PlayerEntitySceneObjectData + 0x10);
  g_CameraRoll = 0;
  _g_StorkCameraResetPending = 0;
  return;
}

