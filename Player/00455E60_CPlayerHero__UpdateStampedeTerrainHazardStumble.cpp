#include "tarzan_ghidra_types.hpp"

// Address: 0x00455E60
// Label: CPlayerHero::UpdateStampedeTerrainHazardStumble
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateStampedeTerrainHazardStumble(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  
  CPlayerHero::UpdateJumpArcVerticalMotion(0);
  RefreshEntitySceneObjectNatureTerrainVerticalDelta(g_PlayerEntitySceneObject);
  resultFlag = CPlayerHero::TryResolveGroundContactSnap();
  value2 = g_PlayerActionState;
  if (resultFlag != '\0') {
    g_PlayerActionState = 1;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00455e95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_StampedeEnterRunningHandlerPtr)();
    return;
  }
  CPlayerHero::ApproachStampedeForwardSpeed();
  CPlayerHero::ApplyStampedeForwardMotionXZ();
  value = CPlayerHero::AdvanceAnimationScript();
  value2 = g_PlayerActionState;
  if (value != 0) {
    g_PlayerActionState = 3;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00455ec5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_StampedeEnterFallingHandlerPtr)();
    return;
  }
  return;
}

