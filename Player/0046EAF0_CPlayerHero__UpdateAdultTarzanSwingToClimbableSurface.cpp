#include "tarzan_ghidra_types.hpp"

// Address: 0x0046EAF0
// Label: CPlayerHero::UpdateAdultTarzanSwingToClimbableSurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanSwingToClimbableSurface(void)

{
  undefined2 value2;
  int value;
  
  value2 = g_PlayerActionState;
  if ((g_PlayerInputHeldMask & 0x200000) != 0) {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046eb11. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
    return;
  }
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 8) {
    g_PlayerSwingTransitionStep = g_PlayerSwingTransitionStep + 1;
    CPlayerHero::SnapToCurrentJungleSurface();
    if ((g_PlayerCurrentCollisionSurface == 0) ||
       ((*(byte *)(g_PlayerCurrentCollisionSurface + 0x14) & 0x20) == 0)) goto LAB_0046ec3d;
    if (2 < g_PlayerSwingTransitionStep) {
      if (g_PlayerAnimationSurfaceSide == '\0') {
        CPlayerHero::PlayAdultTarzanAnimation(0x54);
        CPlayerHero::UpdateMovementAndCollision(1);
        return;
      }
LAB_0046ec09:
      CPlayerHero::PlayAdultTarzanAnimation(0x58);
      CPlayerHero::UpdateMovementAndCollision(1);
      return;
    }
  }
  else {
    if (value != 0xc) goto LAB_0046ec3d;
    if ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0) {
      if (g_PlayerAnimationSurfaceSide == '\0') {
        CPlayerHero::PlayAdultTarzanAnimation(0x5c);
        CPlayerHero::UpdateMovementAndCollision(1);
        return;
      }
      CPlayerHero::PlayAdultTarzanAnimation(0x5d);
      CPlayerHero::UpdateMovementAndCollision(1);
      return;
    }
    if ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0) goto LAB_0046ec3d;
    if (2 < g_PlayerSwingTransitionStep) {
      if (g_PlayerAnimationSurfaceSide == '\0') {
        CPlayerHero::PlayAdultTarzanAnimation(0x54);
        CPlayerHero::UpdateMovementAndCollision(1);
        return;
      }
      goto LAB_0046ec09;
    }
  }
  if (g_PlayerAnimationSurfaceSide == '\0') {
    CPlayerHero::PlayAdultTarzanAnimation(0x55);
    CPlayerHero::UpdateMovementAndCollision(1);
    return;
  }
  CPlayerHero::PlayAdultTarzanAnimation(0x59);
LAB_0046ec3d:
  CPlayerHero::UpdateMovementAndCollision(1);
  return;
}

