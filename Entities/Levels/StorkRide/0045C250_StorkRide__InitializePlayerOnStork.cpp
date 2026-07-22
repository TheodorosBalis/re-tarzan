#include "tarzan_ghidra_types.hpp"

// Address: 0x0045C250
// Label: StorkRide::InitializePlayerOnStork
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StorkRide::InitializePlayerOnStork(void)

{
  CCamera::ResetYoungTarzanOnStorkCameraFocus();
  *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2) = 0x800;
  return;
}

