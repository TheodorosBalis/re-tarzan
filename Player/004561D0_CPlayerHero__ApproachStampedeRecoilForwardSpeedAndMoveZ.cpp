#include "tarzan_ghidra_types.hpp"

// Address: 0x004561D0
// Label: CPlayerHero::ApproachStampedeRecoilForwardSpeedAndMoveZ
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::ApproachStampedeRecoilForwardSpeedAndMoveZ(void)

{
  int value;
  
  value = *(int *)(g_PlayerMotionState + 0x30);
  if (value != *(int *)(g_PlayerMotionState + 0x3c)) {
    if (*(int *)(g_PlayerMotionState + 0x3c) < value) {
      *(int *)(g_PlayerMotionState + 0x30) = value - *(int *)(g_PlayerMotionState + 0x38);
      value = *(int *)(g_PlayerMotionState + 0x3c);
      if (value <= *(int *)(g_PlayerMotionState + 0x30)) goto LAB_00456217;
    }
    else {
      *(int *)(g_PlayerMotionState + 0x30) = *(int *)(g_PlayerMotionState + 0x34) + value;
      value = *(int *)(g_PlayerMotionState + 0x3c);
      if (*(int *)(g_PlayerMotionState + 0x30) <= value) goto LAB_00456217;
    }
    *(int *)(g_PlayerMotionState + 0x30) = value;
  }
LAB_00456217:
  *(int *)(g_PlayerEntitySceneObject + 0x1c) =
       *(int *)(g_PlayerEntitySceneObject + 0x1c) + (*(int *)(g_PlayerMotionState + 0x30) >> 8);
  return;
}

