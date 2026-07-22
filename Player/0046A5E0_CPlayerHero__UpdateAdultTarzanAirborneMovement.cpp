#include "tarzan_ghidra_types.hpp"

// Address: 0x0046A5E0
// Label: CPlayerHero::UpdateAdultTarzanAirborneMovement
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanAirborneMovement(void)

{
  char resultFlag;
  int value;
  undefined4 value2;
  
  resultFlag = TryStartPlayerAttachmentInteraction();
  if (resultFlag != '\0') {
    return;
  }
  CPlayerHero::UpdateRunInputAndMovement();
  CPlayerHero::TrySnapDownToGround();
  if ((g_PlayerFacingCurrentCollisionSurface != '\0') &&
     ((*( undefined2 *)((int)&g_PlayerSurfaceTriggerPacket + 2) & 0x200) == 0)) {
    if (((*( undefined2 *)((int)&g_PlayerSurfaceTriggerPacket + 2) & 0x2000) == 0) && (g_PlayerActionState != 0x2e)) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x2e;
      (*(code *)g_AdultTarzanEnterAirborneDamageHandlerPtr)();
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
    }
  }
  if (((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
       (((ushort)g_PlayerSurfaceTriggerPacket & 0x800) == 0)) && (g_HudPowerFruitSelectorScene != 0)
      ) && (((g_PlayerInputHeldMask & 0x400000) != 0 || ((g_PlayerInputHeldMask & 0x3800000) != 0)))
     ) {
    if ((g_PlayerJumpArcActive == '\0') && (*(char *)(g_PlayerMotionState + 0xd) != '\0'))
    goto LAB_0046a756;
    if ((g_PlayerCurrentAnimationId != 0x81) && (g_PlayerCurrentAnimationId != 0x8a)) {
      if (((g_PlayerInputHeldMask & 0x400000) == 0) && ((g_PlayerInputHeldMask & 0x800000) == 0)) {
        if ((g_PlayerPowerFruitInventoryFlags & 0x10) == 0) goto LAB_0046a6e9;
        g_PlayerAttackHitSfxPlayed = 0;
        value2 = 0x8a;
      }
      else {
        value2 = 0x81;
      }
      CPlayerHero::PlayAdultTarzanAnimation(value2);
    }
  }
LAB_0046a6e9:
  if (g_PlayerJumpArcActive != '\0') {
    value = CPlayerHero::TryClampJumpArcToSurfaceCeiling(0x14e);
    if (value != 0) {
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) = value;
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 7;
      (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
      g_PlayerJumpArcActive = '\0';
    }
    if (((g_PlayerActionState == 0x2e) || (g_PlayerActionState == 0x2d)) ||
       (g_PlayerActionState == 0x2f)) {
      value2 = 0;
    }
    else {
      value2 = 1;
    }
    CPlayerHero::UpdateJumpArcVerticalMotion(value2);
  }
LAB_0046a756:
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 4) {
    CEntities::SpawnEntityByTypeAtPosition(0,0,0,0xf,0x11);
  }
  else {
    if (value == 8) {
      if (g_PlayerHeldThrowableEntity != 0) {
        *(undefined2 *)(g_PlayerHeldThrowableEntity + 0x48) = 7;
      }
      g_PlayerHeldThrowableEntity = 0;
      return;
    }
    if ((value == 0x12) && ((g_PlayerInputHeldMask & 0xc00000) != 0)) {
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      return;
    }
  }
  return;
}

