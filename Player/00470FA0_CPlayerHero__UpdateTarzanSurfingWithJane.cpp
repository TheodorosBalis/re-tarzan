#include "tarzan_ghidra_types.hpp"

// Address: 0x00470FA0
// Label: CPlayerHero::UpdateTarzanSurfingWithJane
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateTarzanSurfingWithJane(void)

{
  if (g_PlayerActionState != 9) {
    if (g_PlayerBalanceWobbleTimer < 0) {
      g_PlayerBalanceWobbleTimer = g_PlayerBalanceWobbleTimer + 1;
    }
    else if ((g_PlayerEdgeBalanceInputMask & g_PlayerInputHeldMask) != 0) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 9;
      (*(code *)g_JaneEnterSurfingWithTarzanHandlerPtr)();
    }
  }
  (*(code *)(&g_TarzanSurfingWithJaneActionStateUpdateColumn)[(uint)g_PlayerActionState * 2])();
  CPlayerHero::UpdateEntitySceneObjectFacingAngles();
  if (g_TarzanSurfingWithJaneActionEffectTimer == 0) {
    if (0 < g_TarzanSurfingWithJaneActionEffectLevel) {
      g_TarzanSurfingWithJaneActionEffectLevel = g_TarzanSurfingWithJaneActionEffectLevel + -1;
    }
  }
  else {
    g_TarzanSurfingWithJaneActionEffectTimer = g_TarzanSurfingWithJaneActionEffectTimer + -1;
    if (g_TarzanSurfingWithJaneActionEffectLevel < 10) {
      g_TarzanSurfingWithJaneActionEffectLevel = g_TarzanSurfingWithJaneActionEffectLevel + 2;
    }
  }
  *(int *)(g_PlayerEntitySceneObject + 0x70) = g_TarzanSurfingWithJaneActionEffectLevel >> 1;
  CPlayerHero::UpdateTarzanSurfingWithJaneAttachmentProbes();
  return;
}

