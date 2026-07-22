#include "tarzan_ghidra_types.hpp"

// Address: 0x00435D20
// Label: CPlayerHero::UpdateJumpArcVerticalMotion
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateJumpArcVerticalMotion(char arg1)

{
  short shortValue;
  int value;
  
  if (*(char *)(g_PlayerMotionState + 0xd) == '\0') {
    *(int *)(g_PlayerMotionState + 0x20) =
         *(int *)(g_PlayerMotionState + 0x20) + *(int *)(g_PlayerMotionState + 0x24);
    if (*(int *)(g_PlayerMotionState + 0x2c) < *(int *)(g_PlayerMotionState + 0x20)) {
      *(int *)(g_PlayerMotionState + 0x20) = *(int *)(g_PlayerMotionState + 0x2c);
    }
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + *(int *)(g_PlayerMotionState + 0x20);
    return;
  }
  CEntities::TryCorrectEntitySceneObjectVerticalCollisionPenetration(g_PlayerEntitySceneObject);
  value = *(int *)(g_PlayerMotionState + 0x28);
  if (arg1 != '\0') {
    if (_g_PlayerHeroMode == 2) {
      if (((g_PlayerInputHeldMask & 0x200000) == 0) && (0x18 < *(int *)(g_PlayerMotionState + 0x20))
         ) {
        value = 0x18;
      }
    }
    else if (_g_PlayerHeroMode == 9) {
      if (((g_PlayerInputHeldMask & 0x200000) == 0) && (0x40 < *(int *)(g_PlayerMotionState + 0x20))
         ) {
        value = 0x30;
      }
    }
    else if (((g_PlayerInputHeldMask & 0x200000) == 0) &&
            (0x40 < *(int *)(g_PlayerMotionState + 0x20))) {
      value = 0x28;
    }
  }
  value = *(int *)(g_PlayerMotionState + 0x20) - value;
  *(int *)(g_PlayerMotionState + 0x20) = value;
  if (value < 0) {
    *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
    *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
    shortValue = g_PlayerActionState;
    switch(_g_PlayerHeroMode) {
    case 2:
      if (g_PlayerActionState != 0x1c) {
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 7;
        (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
        g_PlayerJumpArcActive = 0;
        return;
      }
      break;
    case 3:
      g_PlayerActionState = 0x34;
      g_PreviousPlayerActionState = shortValue;
      (*(code *)g_AdultTarzanEnterSaborBattleIdleHandlerPtr)();
      g_PlayerJumpArcActive = 0;
      return;
    case 4:
      g_PlayerActionState = 4;
      g_PreviousPlayerActionState = shortValue;
      (*(code *)g_JaneEnterFallingHandlerPtr)();
      g_PlayerJumpArcActive = 0;
      return;
    case 5:
      g_PlayerActionState = 0;
      g_PreviousPlayerActionState = shortValue;
      (*(code *)g_TarzanSurfingWithJaneActionStateEnterColumn)();
      g_PlayerJumpArcActive = 0;
      return;
    case 6:
      g_PlayerActionState = 10;
      g_PreviousPlayerActionState = shortValue;
      (*(code *)g_TerkEnterFallingHandlerPtr)();
      g_PlayerJumpArcActive = 0;
      return;
    default:
      if (g_PlayerActionState != 0x1b) {
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 7;
        (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
      }
      break;
    case 9:
      g_PlayerActionState = 3;
      g_PreviousPlayerActionState = shortValue;
      (*(code *)g_StampedeEnterFallingHandlerPtr)();
      g_PlayerJumpArcActive = 0;
      return;
    }
    g_PlayerJumpArcActive = 0;
    return;
  }
  *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
       *(int *)(g_PlayerEntitySceneObjectData + 0xc) - *(int *)(g_PlayerMotionState + 0x20);
  return;
}

