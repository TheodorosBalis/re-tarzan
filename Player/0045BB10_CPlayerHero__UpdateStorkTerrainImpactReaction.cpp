#include "tarzan_ghidra_types.hpp"

// Address: 0x0045BB10
// Label: CPlayerHero::UpdateStorkTerrainImpactReaction
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateStorkTerrainImpactReaction(void)

{
  undefined2 value2;
  int value;
  
  value2 = g_PlayerActionState;
  if ((g_StorkTerrainCollisionFlags & 2) != 0) {
    value = CPlayerHero::AdvanceAnimationScript();
    value2 = g_PlayerActionState;
    if (value != 0) {
      if (g_StorkImpactAnimationVariant == 0) {
        g_PlayerActionState = 0;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_StorkActionStateTable)();
      }
      value2 = g_PlayerActionState;
      if (g_StorkImpactAnimationVariant == 1) {
        g_PlayerActionState = 0;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_StorkActionStateTable)();
      }
      value2 = g_PlayerActionState;
      if (g_StorkImpactAnimationVariant == 2) {
        g_PlayerActionState = 6;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_StorkEnterGroundedRecoveryWaitHandlerPtr)();
      }
      value2 = g_PlayerActionState;
      if (g_StorkImpactAnimationVariant == 3) {
        g_PlayerActionState = 0;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_StorkActionStateTable)();
      }
      value2 = g_PlayerActionState;
      if (g_StorkImpactAnimationVariant == 4) {
        g_PlayerActionState = 0;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_StorkActionStateTable)();
      }
    }
    CPlayerHero::IntegrateStorkVerticalMotion();
    CPlayerHero::ApproachStorkForwardSpeed();
    CPlayerHero::ClampStorkFlightSpeedAndTilt();
    CPlayerHero::ApplyStorkForwardMotionXZ();
    return;
  }
  g_PlayerActionState = 5;
  g_PreviousPlayerActionState = value2;
  (*(code *)g_StorkEnterPostImpactFallingHandlerPtr)();
  CPlayerHero::IntegrateStorkVerticalMotion();
  return;
}

