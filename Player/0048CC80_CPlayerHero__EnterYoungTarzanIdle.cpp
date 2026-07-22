#include "tarzan_ghidra_types.hpp"

// Address: 0x0048CC80
// Label: CPlayerHero::EnterYoungTarzanIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterYoungTarzanIdle(void)

{
  undefined2 value;
  short shortValue;
  
  value = g_PlayerActionState;
  g_PlayerPickupInteractionFlags = 0;
  g_TutorialPickupSequencePhase = 0;
  if (g_PlayerCurrentCollisionMode != 4) {
    CPlayerHero::PlayAnimation(8);
    shortValue = RandomModulo(10);
    g_PlayerIdleFidgetDelayTicks = shortValue + 5;
    g_PlayerTiltControlEnabled = 0;
    return;
  }
  g_PlayerActionState = 0x26;
  g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048ccd5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_g_YoungEnterWaterIdleHandlerPtr)();
  return;
}

