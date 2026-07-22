#include "tarzan_ghidra_types.hpp"

// Address: 0x004717D0
// Label: CPlayerHero::EnterTarzanSurfingWithJaneBraking
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterTarzanSurfingWithJaneBraking(void)

{
  g_PlayerCurrentAnimationId = 9;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_JaneSurfingBrakingAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  if ((_g_PlayerSequenceFlags & 0x2000) == 0) {
    if (g_TarzanSurfingWithJaneActionSoundActive != '\0') {
      PlayAudioById(0x237,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    }
    g_TarzanSurfingWithJaneActionEffectTimer = 0;
    g_TarzanSurfingWithJaneActionSoundActive = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = g_PlayerSurfaceMotionSpeed;
    return;
  }
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = g_PlayerSurfaceMotionSpeed;
  return;
}

