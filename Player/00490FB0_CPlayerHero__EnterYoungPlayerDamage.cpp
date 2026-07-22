#include "tarzan_ghidra_types.hpp"

// Address: 0x00490FB0
// Label: CPlayerHero::EnterYoungPlayerDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungPlayerDamage(void)

{
  undefined2 value;
  char resultFlag;
  
  CPlayerHero::PlayAnimation(0x20);
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  g_PlayerDamageInvulnerabilityTicks = 0x3c;
  g_PlayerDamageFlashTicks = 0x3c;
  CPlayerHero::ApplyDamageContactPushback();
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x00491020. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
    return;
  }
  return;
}

