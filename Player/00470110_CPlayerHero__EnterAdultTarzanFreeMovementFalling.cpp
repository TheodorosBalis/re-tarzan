#include "tarzan_ghidra_types.hpp"

// Address: 0x00470110
// Label: CPlayerHero::EnterAdultTarzanFreeMovementFalling
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanFreeMovementFalling(void)

{
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x40;
  g_PlayerTargetMoveSpeed = 0x40;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 4;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x70;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 5;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  if (((g_PlayerCurrentAnimationId != 0x81) && (g_PlayerCurrentAnimationId != 0x8a)) &&
     (g_PreviousPlayerActionState != 0x2f)) {
    if (g_PreviousPlayerActionState != 0x45) {
      if (g_PreviousPlayerActionState != 0x46) {
        CPlayerHero::PlayAdultTarzanAnimation(0x12);
        g_CurrentSwingEntity = 0;
        return;
      }
      CPlayerHero::PlayAdultTarzanAnimation(0x15);
      g_CurrentSwingEntity = 0;
      g_PlayerActionState = 0x48;
      return;
    }
    CPlayerHero::PlayAdultTarzanAnimation(0x14);
  }
  g_CurrentSwingEntity = 0;
  return;
}

