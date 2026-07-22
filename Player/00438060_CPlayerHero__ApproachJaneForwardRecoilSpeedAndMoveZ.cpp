#include "tarzan_ghidra_types.hpp"

// Address: 0x00438060
// Label: CPlayerHero::ApproachJaneForwardRecoilSpeedAndMoveZ
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::ApproachJaneForwardRecoilSpeedAndMoveZ(void)

{
  int value;
  
  value = *(int *)(g_PlayerMotionState + 0x30);
  if (value != *(int *)(g_PlayerMotionState + 0x3c)) {
    if (*(int *)(g_PlayerMotionState + 0x3c) < value) {
      *(int *)(g_PlayerMotionState + 0x30) = value - *(int *)(g_PlayerMotionState + 0x38);
      value = *(int *)(g_PlayerMotionState + 0x3c);
      if (value <= *(int *)(g_PlayerMotionState + 0x30)) goto LAB_004380a7;
    }
    else {
      *(int *)(g_PlayerMotionState + 0x30) = *(int *)(g_PlayerMotionState + 0x34) + value;
      value = *(int *)(g_PlayerMotionState + 0x3c);
      if (*(int *)(g_PlayerMotionState + 0x30) <= value) goto LAB_004380a7;
    }
    *(int *)(g_PlayerMotionState + 0x30) = value;
  }
LAB_004380a7:
  *(int *)(g_PlayerEntitySceneObject + 0x1c) =
       *(int *)(g_PlayerEntitySceneObject + 0x1c) + *(int *)(g_PlayerMotionState + 0x30);
  return;
}

