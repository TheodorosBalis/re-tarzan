#include "tarzan_ghidra_types.hpp"

// Address: 0x00492C00
// Label: CPlayerHero::UpdateYoungSwingToClimbableSurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateYoungSwingToClimbableSurface(void)

{
  undefined2 value2;
  int value;
  
  value2 = g_PlayerActionState;
  if ((g_PlayerInputHeldMask & 0x200000) != 0) {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00492c21. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
    return;
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 8) {
    g_PlayerSwingTransitionStep = g_PlayerSwingTransitionStep + 1;
    CPlayerHero::SnapToCurrentJungleSurface();
    if ((g_PlayerCurrentCollisionSurface == 0) ||
       ((*(byte *)(g_PlayerCurrentCollisionSurface + 0x14) & 0x20) == 0)) goto LAB_00492d2b;
    if (2 < g_PlayerSwingTransitionStep) {
      if (g_PlayerAnimationSurfaceSide == '\0') {
        CPlayerHero::PlayAnimation(0x55);
        CPlayerHero::UpdateMovementAndCollision(1);
        return;
      }
LAB_00492cf7:
      CPlayerHero::PlayAnimation(0x59);
      CPlayerHero::UpdateMovementAndCollision(1);
      return;
    }
  }
  else {
    if (value != 0xc) goto LAB_00492d2b;
    if ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0) {
      if (g_PlayerAnimationSurfaceSide == '\0') {
        CPlayerHero::PlayAnimation(0x5d);
        CPlayerHero::UpdateMovementAndCollision(1);
        return;
      }
      CPlayerHero::PlayAnimation(0x5e);
      CPlayerHero::UpdateMovementAndCollision(1);
      return;
    }
    if ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0) goto LAB_00492d2b;
    if (2 < g_PlayerSwingTransitionStep) {
      if (g_PlayerAnimationSurfaceSide == '\0') {
        CPlayerHero::PlayAnimation(0x55);
        CPlayerHero::UpdateMovementAndCollision(1);
        return;
      }
      goto LAB_00492cf7;
    }
  }
  if (g_PlayerAnimationSurfaceSide == '\0') {
    CPlayerHero::PlayAnimation(0x56);
    CPlayerHero::UpdateMovementAndCollision(1);
    return;
  }
  CPlayerHero::PlayAnimation(0x5a);
LAB_00492d2b:
  CPlayerHero::UpdateMovementAndCollision(1);
  return;
}

