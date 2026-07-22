#include "tarzan_ghidra_types.hpp"

// Address: 0x00491030
// Label: CPlayerHero::UpdateYoungPlayerDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateYoungPlayerDamage(void)

{
  undefined2 value;
  char resultFlag;
  ushort value2;
  
  CPlayerHero::ApplyDamageContactPushback();
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value;
    (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
  }
  value = g_PlayerActionState;
  if (g_PlayerCurrentAnimationId == 0x21) {
    value2 = g_PlayerSequenceFlags & 0xf000;
    if ((value2 == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      if ((g_CameraFollowFlags & g_PlayerInputHeldMask) == 0) {
        g_PlayerActionState = 6;
        g_PreviousPlayerActionState = value;
        (*(code *)g_YoungEnterTarzanStandingJumpHandlerPtr)();
        return;
      }
      g_PlayerActionState = 5;
      g_PreviousPlayerActionState = value;
      (*(code *)g_YoungEnterTarzanMovingJumpHandlerPtr)();
      return;
    }
    if ((value2 == 0) && ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) {
      if (g_PlayerCurrentCollisionMode == 2) {
        g_PlayerActionState = 3;
        g_PreviousPlayerActionState = value;
        (*(code *)g_YoungEnterTarzanTurnAroundHandlerPtr)();
        return;
      }
      if ((g_PlayerInputHeldMask & 0x80) == 0) {
        g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + 0x2d;
      }
      else {
        g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + -0x2d;
      }
    }
    if (value2 == 0) {
      if ((g_PlayerInputHeldMask & 0x80000) != 0) {
        g_PlayerActionState = 10;
        g_PreviousPlayerActionState = value;
        (*(code *)g_YoungEnterBlockHandlerPtr)();
        return;
      }
      if ((g_PlayerInputPressedMask & 0x100000) != 0) {
        g_PlayerActionState = 0x2f;
        g_PreviousPlayerActionState = value;
        (*(code *)g_YoungEnterPoundHandlerPtr)();
        return;
      }
    }
  }
  else {
    if ((g_PlayerInputPressedMask & 0x200000) != 0) {
      g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
    }
    if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
      g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
    }
    g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  }
  CPlayerHero::AdvanceAnimationScript();
  return;
}

