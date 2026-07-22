#include "tarzan_ghidra_types.hpp"

// Address: 0x00471990
// Label: CPlayerHero::EnterTarzanSurfingWithJaneHazardDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterTarzanSurfingWithJaneHazardDamage(void)

{
  g_PlayerCurrentAnimationId = 7;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_JaneSurfingHazardDamageAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
  if ((_g_PlayerSequenceFlags & 0x2000) == 0) {
    if (g_TarzanSurfingWithJaneActionSoundActive != '\0') {
      PlayAudioById(0x237,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    }
    g_TarzanSurfingWithJaneActionEffectTimer = 0;
    g_TarzanSurfingWithJaneActionSoundActive = '\0';
  }
  PlayForceFeedbackEffect_Stub(0,2,0x10);
  return;
}

