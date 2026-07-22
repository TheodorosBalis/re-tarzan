#include "tarzan_ghidra_types.hpp"

// Address: 0x004917B0
// Label: CPlayerHero::EnterYoungApplyDamageOnTreeSurfing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungApplyDamageOnTreeSurfing(void)

{
  CPlayerHero::PlayAnimation(0x2b);
  DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
  PlayForceFeedbackEffect_Stub(0,2,0x10);
  return;
}

