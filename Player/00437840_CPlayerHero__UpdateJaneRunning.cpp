#include "tarzan_ghidra_types.hpp"

// Address: 0x00437840
// Label: CPlayerHero::UpdateJaneRunning
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateJaneRunning(void)

{
  int value;
  int value2;
  short shortValue;
  char resultFlag;
  
  if ((_g_PlayerSequenceFlags & 0x2000) == 0) {
    CPlayerHero::UpdateJaneRouteRelativeFacing();
    shortValue = g_PlayerActionState;
    if ((g_PlayerInputPressedMask & 0x200000) != 0) {
      g_PlayerActionState = 3;
      g_PreviousPlayerActionState = shortValue;
                    /* WARNING: Could not recover jumptable at 0x00437874. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*_g_JaneEnterJumpHandlerPtr)();
      return;
    }
    if ((_g_PlayerSequenceFlags & 0x2000) == 0) {
      if (g_PlayerFacingCurrentCollisionSurface != '\0') {
        g_PlayerActionState = 8;
        g_PreviousPlayerActionState = shortValue;
                    /* WARNING: Could not recover jumptable at 0x004378a4. Too many branches */
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
    RefreshEntitySceneObjectNatureTerrainVerticalDelta(g_PlayerEntitySceneObject);
    resultFlag = CPlayerHero::TrySnapToNearbyGround();
    shortValue = g_PlayerActionState;
    if (resultFlag == '\0') {
      g_PlayerActionState = 4;
      g_PreviousPlayerActionState = shortValue;
                    /* WARNING: Could not recover jumptable at 0x00437918. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_JaneEnterFallingHandlerPtr)();
      return;
    }
  }
  value2 = g_PlayerEntitySceneObject;
  if (g_JaneScriptedFollowActive == 0) {
    CPlayerHero::AdvanceAnimationScript();
  }
  else if (g_JaneScriptedFollowEntity != 0) {
    value = *(int *)(g_JaneScriptedFollowEntity + 0x38);
    *(undefined4 *)(g_PlayerEntitySceneObject + 0x14) = *(undefined4 *)(value + 0x14);
    *(undefined4 *)(value2 + 0x18) = *(undefined4 *)(value + 0x18);
    *(undefined4 *)(value2 + 0x1c) = *(undefined4 *)(value + 0x1c);
  }
  CPlayerHero::ApproachJaneForwardSpeed();
  CPlayerHero::ApplyJaneForwardMotionXZ();
  return;
}

