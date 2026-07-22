#include "tarzan_ghidra_types.hpp"

// Address: 0x0046D5E0
// Label: CPlayerHero::EnterAdultTarzanTreeSurfingObstacleDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanTreeSurfingObstacleDamage(void)

{
  CPlayerHero::PlayAdultTarzanAnimation(0x2d);
  DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
  QueuePlayerDamageEvent(0,4);
  PlayForceFeedbackEffect_Stub(0,2,0x10);
  return;
}

