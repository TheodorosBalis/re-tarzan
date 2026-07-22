#include "tarzan_ghidra_types.hpp"

// Address: 0x0046A7B0
// Label: CPlayerHero::EnterAdultTarzanFallOrKnockback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanFallOrKnockback(void)

{
  int value;
  undefined4 value2;
  
  value = g_PlayerEntitySceneObject;
  if (*(int *)(g_PlayerEntitySceneObject + 0x60) != 0) {
    *(undefined4 *)(*(int *)(g_PlayerEntitySceneObject + 0x60) + 0x60) = 0;
  }
  *(undefined4 *)(value + 0x60) = 0;
  if (g_PlayerCurrentCollisionMode == 1) {
    CPlayerHero::EnterAdultTarzanFreeMovementFalling();
    g_PlayerActionState = 0x47;
    return;
  }
  if (g_PreviousPlayerActionState == 0x22) {
    CPlayerHero::PlayAdultTarzanAnimation(0x12);
    return;
  }
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x40;
  g_PlayerTargetMoveSpeed = 0x40;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 4;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x70;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 5;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  if (g_PlayerCurrentAnimationId == 0x81) {
    g_CurrentSwingEntity = 0;
    g_PlayerTiltControlEnabled = 0;
    return;
  }
  if (g_PlayerCurrentAnimationId == 0x8a) {
    g_CurrentSwingEntity = 0;
    g_PlayerTiltControlEnabled = 0;
    return;
  }
  switch(g_PreviousPlayerActionState) {
  case 5:
    CPlayerHero::PlayAdultTarzanAnimation(0x15);
    g_PlayerTiltControlEnabled = 0;
    g_CurrentSwingEntity = 0;
    g_PlayerActionState = 8;
    return;
  case 6:
    value2 = 0x14;
    break;
  default:
switchD_0046a883_caseD_7:
    value2 = 0x12;
    break;
  case 0xf:
    CPlayerHero::PlayAdultTarzanAnimation(0x2a);
    g_PlayerTiltControlEnabled = 0;
    g_CurrentSwingEntity = 0;
    g_PlayerActionState = 0x10;
    return;
  case 0x17:
  case 0x1c:
    if (g_CurrentSwingEntity != 0) goto switchD_0046a883_caseD_7;
    if (g_PlayerAnimationSurfaceSide == '\0') {
      value2 = 0x5a;
    }
    else {
      value2 = 0x5b;
    }
    break;
  case 0x2d:
  case 0x2e:
    goto switchD_0046a883_caseD_2d;
  }
  CPlayerHero::PlayAdultTarzanAnimation(value2);
switchD_0046a883_caseD_2d:
  g_PlayerTiltControlEnabled = 0;
  g_CurrentSwingEntity = 0;
  return;
}

