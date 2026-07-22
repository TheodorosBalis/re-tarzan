#include "tarzan_ghidra_types.hpp"

// Address: 0x0046D5B0
// Label: CPlayerHero::EnterAdultTarzanTreeSurfingCrashDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanTreeSurfingCrashDamage(void)

{
  CPlayerHero::PlayAdultTarzanAnimation(0x2e);
  DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
  QueuePlayerDamageEvent(0,6);
  PlayForceFeedbackEffect_Stub(0,2,0x10);
  return;
}

