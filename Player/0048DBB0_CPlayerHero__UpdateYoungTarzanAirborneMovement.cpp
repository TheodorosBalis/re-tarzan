#include "tarzan_ghidra_types.hpp"

// Address: 0x0048DBB0
// Label: CPlayerHero::UpdateYoungTarzanAirborneMovement
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungTarzanAirborneMovement(void)

{
  char resultFlag;
  int value;
  undefined4 value2;
  
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
  CPlayerHero::UpdateRunInputAndMovement();
  CPlayerHero::TrySnapDownToGround();
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
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
     (((g_PlayerInputHeldMask & 0x400000) != 0 || ((g_PlayerInputHeldMask & 0x3800000) != 0)))) {
    if ((g_PlayerJumpArcActive == '\0') && (*(char *)(g_PlayerMotionState + 0xd) != '\0'))
    goto LAB_0048dd3c;
    if ((g_PlayerCurrentAnimationId != 0x8d) && (g_PlayerCurrentAnimationId != 0x91)) {
      if (((g_PlayerInputHeldMask & 0x400000) == 0) && ((g_PlayerInputHeldMask & 0x800000) == 0)) {
        if ((g_PlayerPowerFruitInventoryFlags & 0x10) == 0) goto LAB_0048dcd5;
        value2 = 0x91;
      }
      else {
        value2 = 0x8d;
      }
      CPlayerHero::PlayAnimation(value2);
    }
  }
LAB_0048dcd5:
  if (g_PlayerJumpArcActive != '\0') {
    value = CPlayerHero::TryClampJumpArcToSurfaceCeiling(0xa0);
    if (value != 0) {
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) = value;
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 7;
      (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
      g_PlayerJumpArcActive = '\0';
    }
    if ((g_PlayerActionState == 0x30) || (g_PlayerActionState == 0x31)) {
      value2 = 0;
    }
    else {
      value2 = 1;
    }
    CPlayerHero::UpdateJumpArcVerticalMotion(value2);
  }
LAB_0048dd3c:
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

