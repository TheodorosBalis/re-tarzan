#include "tarzan_ghidra_types.hpp"

// Address: 0x0048F870
// Label: CPlayerHero::EnterYoungClimbableWallIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungClimbableWallIdle(void)

{
  undefined4 value;
  
  if (g_PlayerAnimationSurfaceSide == '\0') {
    value = 0x7f;
  }
  else {
    value = 0x7e;
  }
  CPlayerHero::PlayAnimation(value);
  if (g_PreviousPlayerActionState == 0x2d) {
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + -0x70;
  }
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  g_PlayerTiltControlEnabled = 0;
  return;
}

