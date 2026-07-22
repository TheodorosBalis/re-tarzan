#include "tarzan_ghidra_types.hpp"

// Address: 0x0048DF20
// Label: CPlayerHero::UpdateYoungTarzanFalling
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungTarzanFalling(void)

{
  short shortValue;
  char resultFlag;
  int value;
  undefined4 value2;
  
  resultFlag = CPlayerHero::IsOnTreeSurfingSurface();
  if (resultFlag != '\0') {
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 0x24;
                    /* WARNING: Could not recover jumptable at 0x0048df3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterDiveHandlerPtr)();
    return;
  }
  if (g_PlayerActionState == 0x11) {
    *(int *)(g_PlayerEntitySceneObject + 0xa8) = *(int *)(g_PlayerEntitySceneObject + 0xa8) + -0x40;
    if (*(int *)(g_PlayerEntitySceneObject + 0xa8) < 0x1001) {
      *(undefined4 *)(g_PlayerEntitySceneObject + 0xa8) = 0x1000;
    }
    *(undefined4 *)(g_PlayerEntitySceneObject + 0xb0) =
         *(undefined4 *)(g_PlayerEntitySceneObject + 0xa8);
    *(undefined4 *)(g_PlayerEntitySceneObject + 0xac) =
         *(undefined4 *)(g_PlayerEntitySceneObject + 0xb0);
  }
  if (g_PlayerPickupInteractionFlags == 0x4000) goto LAB_0048e0d7;
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if (((ram0x0051cdca & 0x2000) == 0) && (g_PlayerActionState != 0x30)) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x30;
      (*(code *)g_YoungEnterJumpDamageHandlerPtr)();
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
    }
  }
  if (((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
       (((g_PlayerInputHeldMask & 0x400000) != 0 || ((g_PlayerInputHeldMask & 0x3800000) != 0)))) &&
      ((g_PlayerJumpArcActive != '\0' || (*(char *)(g_PlayerMotionState + 0xd) == '\0')))) &&
     ((g_PlayerCurrentAnimationId != 0x8d && (g_PlayerCurrentAnimationId != 0x91)))) {
    if (((g_PlayerInputHeldMask & 0x400000) == 0) && ((g_PlayerInputHeldMask & 0x800000) == 0)) {
      if ((g_PlayerPowerFruitInventoryFlags & 0x10) == 0) goto LAB_0048e08c;
      value2 = 0x91;
    }
    else {
      value2 = 0x8d;
    }
    CPlayerHero::PlayAnimation(value2);
  }
LAB_0048e08c:
  resultFlag = TryStartPlayerAttachmentInteraction();
  if (resultFlag != '\0') {
    return;
  }
  if ((g_PlayerPickupInteractionFlags & 0x8000) != 0) {
    g_PlayerPickupInteractionFlags = 0x4000;
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 0x10;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x10;
    g_PlayerTargetMoveSpeed = 0;
  }
LAB_0048e0d7:
  CPlayerHero::UpdateJumpArcVerticalMotion(0);
  CPlayerHero::UpdateRunInputAndMovement();
  resultFlag = CPlayerHero::IsOnTreeSurfingSurface();
  shortValue = g_PlayerActionState;
  if ((resultFlag != '\0') && (0 < *(int *)(g_PlayerEntitySceneObjectData + 0xc))) {
    g_PlayerActionState = 0x25;
    g_PreviousPlayerActionState = shortValue;
                    /* WARNING: Could not recover jumptable at 0x0048e111. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_g_YoungTarzanFallDiveCallback_Field0000)();
    return;
  }
  resultFlag = CPlayerHero::TryResolveGroundContactSnap();
  shortValue = g_PlayerActionState;
  if (resultFlag != '\0') {
    g_PlayerActionState = 9;
    g_PreviousPlayerActionState = shortValue;
                    /* WARNING: Could not recover jumptable at 0x0048e137. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterLandingRecoveryHandlerPtr)();
    return;
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 4) {
    CEntities::SpawnEntityByTypeAtPosition(0,0,0,0xf,0x11);
  }
  else if (value == 8) {
    if (g_PlayerHeldThrowableEntity != 0) {
      *(undefined2 *)(g_PlayerHeldThrowableEntity + 0x48) = 7;
    }
    g_PlayerHeldThrowableEntity = 0;
    return;
  }
  return;
}

