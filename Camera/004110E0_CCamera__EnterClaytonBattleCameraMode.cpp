#include "tarzan_ghidra_types.hpp"

#define g_CameraFollowMode (*(short *)0x0051CE88)
#define g_ClaytonBattleCameraState (*(int *)0x0051C68C)

// Address: 0x004110E0
// Label: CCamera::EnterClaytonBattleCameraMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CCamera::EnterClaytonBattleCameraMode(void)

{
  g_CameraFollowMode = 0x13;
  g_ClaytonBattleCameraState = 0;
  return;
}

