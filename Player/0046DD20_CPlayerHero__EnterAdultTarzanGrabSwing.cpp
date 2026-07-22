#include "tarzan_ghidra_types.hpp"

// Address: 0x0046DD20
// Label: CPlayerHero::EnterAdultTarzanGrabSwing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanGrabSwing(void)

{
  int value;
  undefined4 value2;
  
  if (g_CurrentSwingEntity == 0) {
    value2 = 0x4f;
  }
  else {
    value = *(int *)(g_CurrentSwingEntity + 0x38);
    if (value != 0) {
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x110) = *(undefined4 *)(value + 0x110);
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c) = *(undefined4 *)(value + 0x10c);
    }
    value = CEntities::FindEntityAttachmentByFlags(g_CurrentSwingEntity,0x8000000);
    if (value != 0) {
      *(undefined2 *)(value + 0xe) = 4;
      *(int *)(value + 0x14) = *(int *)(value + 0x20) >> 1;
    }
    value2 = 0x3e;
  }
  CPlayerHero::PlayAdultTarzanAnimation(value2);
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  g_PlayerSwingTransitionStep = 0;
  CPlayerHero::AdvanceAnimationScript();
  CPlayerHero::UpdateMovementAndCollision(0);
  return;
}

