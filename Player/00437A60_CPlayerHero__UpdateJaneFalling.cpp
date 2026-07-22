#include "tarzan_ghidra_types.hpp"

// Address: 0x00437A60
// Label: CPlayerHero::UpdateJaneFalling
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateJaneFalling(void)

{
  short shortValue;
  char resultFlag;
  
  CPlayerHero::UpdateJumpArcVerticalMotion(0);
  CPlayerHero::ApproachJaneForwardSpeed();
  CPlayerHero::ApplyJaneForwardMotionXZ();
  RefreshEntitySceneObjectNatureTerrainVerticalDelta(g_PlayerEntitySceneObject);
  if ((_g_PlayerSequenceFlags & 0x2000) == 0) {
    CPlayerHero::UpdateJaneRouteRelativeFacing();
    shortValue = g_PlayerActionState;
    if ((_g_PlayerSequenceFlags & 0x2000) == 0) {
      if (g_PlayerFacingCurrentCollisionSurface != '\0') {
        g_PlayerActionState = 8;
        g_PreviousPlayerActionState = shortValue;
                    /* WARNING: Could not recover jumptable at 0x00437abc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_JaneEnterDamageHandlerPtr)();
        return;
      }
      if (g_NatureTerrainHazardContactFlag != 0) {
        g_JaneDamageReactionType = 2;
        if (g_PlayerActionState != 8) {
          g_PreviousPlayerActionState = g_PlayerActionState;
          g_PlayerActionState = 8;
          (*(code *)g_JaneEnterDamageHandlerPtr)();
          QueuePlayerDamageEvent(0,7);
        }
        return;
      }
    }
    if (g_JaneGroundSnapSuppressed == 0) {
      resultFlag = CPlayerHero::TryResolveGroundContactSnap();
      shortValue = g_PlayerActionState;
      if (resultFlag != '\0') {
        g_PlayerActionState = 6;
        g_PreviousPlayerActionState = shortValue;
                    /* WARNING: Could not recover jumptable at 0x00437b2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_JaneEnterLandingRecoveryHandlerPtr)();
        return;
      }
    }
  }
  CPlayerHero::AdvanceAnimationScript();
  return;
}

