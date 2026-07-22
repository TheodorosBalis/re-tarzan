#include "tarzan_ghidra_types.hpp"

// Address: 0x00455480
// Label: CPlayerHero::ApplyStampedeDamageReaction
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::ApplyStampedeDamageReaction(undefined4 arg1,undefined4 arg2)

{
  int value;
  
  if ((g_PlayerActionState != 8) && (g_PlayerDamageInvulnerabilityTicks == 0)) {
    QueuePlayerDamageEvent(arg1,arg2);
    value = CEntities::IsEntityVectorMostlyPositiveX(g_PlayerEntity,arg1);
    g_PreviousPlayerActionState = g_PlayerActionState;
    if (value != 0) {
      g_PlayerActionState = 5;
                    /* WARNING: Could not recover jumptable at 0x004554d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_StampedeEnterDamageRecoilTowardNegativeXHandlerPtr)();
      return;
    }
    g_PlayerActionState = 6;
                    /* WARNING: Could not recover jumptable at 0x004554eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_StampedeEnterDamageRecoilTowardPositiveXHandlerPtr)();
    return;
  }
  return;
}

