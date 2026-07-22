#include "tarzan_ghidra_types.hpp"

// Address: 0x00491780
// Label: CPlayerHero::EnterYoungTreeSurfingDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungTreeSurfingDamage(void)

{
  CPlayerHero::PlayAnimation(0x2c);
  DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
  QueuePlayerDamageEvent(0,6);
  PlayForceFeedbackEffect_Stub(0,2,0x10);
  return;
}

