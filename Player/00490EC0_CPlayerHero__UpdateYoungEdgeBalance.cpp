#include "tarzan_ghidra_types.hpp"

// Address: 0x00490EC0
// Label: CPlayerHero::UpdateYoungEdgeBalance
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateYoungEdgeBalance(void)

{
  undefined2 value;
  uint value2;
  short shortValue;
  uint value3;
  bool flagByte;
  
  value = g_PlayerActionState;
  if (((g_PlayerEdgeBalanceInputMask & g_PlayerInputHeldMask) != 0) &&
     (shortValue = g_PlayerBalanceWobbleTimer + 1, flagByte = g_PlayerBalanceWobbleTimer < 0,
     g_PlayerBalanceWobbleTimer = shortValue, flagByte)) {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value;
    (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
    return;
  }
  if ((g_PlayerEdgeBalanceInputMask & g_PlayerInputHeldMask) == 0) {
    if (5 < g_PlayerBalanceWobbleTimer) {
      g_PlayerActionState = 7;
      g_PreviousPlayerActionState = value;
      g_PlayerBalanceWobbleTimer = g_PlayerBalanceWobbleTimer + 1;
      (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
      return;
    }
    g_PlayerBalanceWobbleTimer = -8;
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

