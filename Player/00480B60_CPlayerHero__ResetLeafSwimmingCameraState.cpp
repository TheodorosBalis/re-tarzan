#include "tarzan_ghidra_types.hpp"

// Address: 0x00480B60
// Label: CPlayerHero::ResetLeafSwimmingCameraState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::ResetLeafSwimmingCameraState(void)

{
  g_LeafSwimmingCameraInitialized = 0;
  _g_LeafSwimmingCameraResetPending = 0;
  g_LeafSwimmingCameraDynamicPitchActive = 0;
  g_CameraEyeDistanceFromFocus = 0;
  g_CameraRoll = 0;
  g_LeafSwimmingCameraDistanceBoostActive = 0;
  return;
}

