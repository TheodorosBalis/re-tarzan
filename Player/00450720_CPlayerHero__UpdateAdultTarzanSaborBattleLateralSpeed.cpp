#include "tarzan_ghidra_types.hpp"

// Address: 0x00450720
// Label: CPlayerHero::UpdateAdultTarzanSaborBattleLateralSpeed
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanSaborBattleLateralSpeed(void)

{
  int value;
  
  value = 0x20;
  if (((g_PlayerActionState == 0x36) || (g_PlayerActionState == 0x37)) ||
     (g_PlayerActionState == 0x38)) {
    value = 0x28;
  }
  if (((byte)g_PlayerInputHeldMask & 0x80) == 0) {
    if (((byte)g_PlayerInputHeldMask & 0x20) != 0) {
      *(int *)(g_PlayerMotionState + 0x10) = *(int *)(g_PlayerMotionState + 0x10) + 4;
      if (value < *(int *)(g_PlayerMotionState + 0x10)) {
        *(int *)(g_PlayerMotionState + 0x10) = value;
      }
    }
  }
  else {
    *(int *)(g_PlayerMotionState + 0x10) = *(int *)(g_PlayerMotionState + 0x10) + -4;
    if (*(int *)(g_PlayerMotionState + 0x10) < -value) {
      *(int *)(g_PlayerMotionState + 0x10) = -value;
      return;
    }
  }
  return;
}

