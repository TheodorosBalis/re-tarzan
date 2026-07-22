#include "tarzan_ghidra_types.hpp"

// Address: 0x0046CEF0
// Label: CPlayerHero::UpdateAdultTarzanEdgeBalance
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanEdgeBalance(void)

{
  undefined2 value;
  short shortValue;
  uint value2;
  uint value3;
  bool flagByte;
  
  value = g_PlayerActionState;
  if (((g_PlayerEdgeBalanceInputMask & g_PlayerInputHeldMask) != 0) &&
     (shortValue = g_PlayerBalanceWobbleTimer + 1, flagByte = g_PlayerBalanceWobbleTimer < 0,
     g_PlayerBalanceWobbleTimer = shortValue, flagByte)) {
    if (_g_PlayerHeroMode == 1) {
      g_PlayerActionState = 7;
      g_PreviousPlayerActionState = value;
      (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
      return;
    }
    if (_g_PlayerHeroMode == 3) {
      g_PlayerActionState = 0x34;
      g_PreviousPlayerActionState = value;
      (*(code *)g_AdultTarzanEnterSaborBattleIdleHandlerPtr)();
      return;
    }
  }
  if ((g_PlayerEdgeBalanceInputMask & g_PlayerInputHeldMask) == 0) {
    shortValue = g_PlayerBalanceWobbleTimer + 1;
    if (g_PlayerBalanceWobbleTimer < 6) {
      g_PlayerBalanceWobbleTimer = -8;
    }
    else {
      g_PlayerBalanceWobbleTimer = shortValue;
      if (_g_PlayerHeroMode == 1) {
        g_PlayerActionState = 7;
        g_PreviousPlayerActionState = value;
        (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
        return;
      }
      if (_g_PlayerHeroMode == 3) {
        g_PlayerActionState = 0x34;
        g_PreviousPlayerActionState = value;
        (*(code *)g_AdultTarzanEnterSaborBattleIdleHandlerPtr)();
        return;
      }
    }
  }
  value3 = 0;
  value2 = 0;
  if ((g_PlayerInputHeldMask & 0x10) != 0) {
    value3 = -g_PlayerBalanceWobbleAmount;
  }
  if ((g_PlayerInputHeldMask & 0x40) != 0) {
    value3 = g_PlayerBalanceWobbleAmount;
  }
  if ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0) {
    value2 = -g_PlayerBalanceWobbleAmount;
  }
  if ((g_CameraFollowFlags & g_PlayerInputHeldMask & 0xffffffef) != 0) {
    value2 = g_PlayerBalanceWobbleAmount;
  }
  if (*(char *)(g_PlayerEntitySceneObject + 0x75) != '\0') {
    value2 = ~value2 + 1;
  }
  CPlayerHero::ApplyEdgeBalanceMovementDeltas(value2,value3);
  return;
}

