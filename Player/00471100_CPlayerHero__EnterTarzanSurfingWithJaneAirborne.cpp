#include "tarzan_ghidra_types.hpp"

// Address: 0x00471100
// Label: CPlayerHero::EnterTarzanSurfingWithJaneAirborne
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterTarzanSurfingWithJaneAirborne(void)

{
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x80;
  g_PlayerTargetMoveSpeed = 0x80;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 2;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x40;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x80;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 8;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  if ((_g_PlayerSequenceFlags & 0x2000) == 0) {
    if (g_TarzanSurfingWithJaneActionSoundActive != '\0') {
      PlayAudioById(0x237,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    }
    g_TarzanSurfingWithJaneActionEffectTimer = 0;
    g_TarzanSurfingWithJaneActionSoundActive = '\0';
  }
  g_PlayerCurrentAnimationId = 4;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_JaneSurfingAirborneAnimationScriptAlt;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

