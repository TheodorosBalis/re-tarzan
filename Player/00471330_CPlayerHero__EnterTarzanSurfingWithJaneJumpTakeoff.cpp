#include "tarzan_ghidra_types.hpp"

// Address: 0x00471330
// Label: CPlayerHero::EnterTarzanSurfingWithJaneJumpTakeoff
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterTarzanSurfingWithJaneJumpTakeoff(void)

{
  g_PlayerCurrentAnimationId = 3;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_JaneSurfingJumpTakeoffAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x80;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0xe;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 0xf;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xf0;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = g_PlayerSurfaceMotionSpeed;
  g_PlayerTargetMoveSpeed = *(undefined4 *)(g_PlayerMotionState + 0x10);
  if ((_g_PlayerSequenceFlags & 0x2000) == 0) {
    if (g_TarzanSurfingWithJaneActionSoundActive != '\0') {
      PlayAudioById(0x237,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    }
    g_TarzanSurfingWithJaneActionEffectTimer = 0;
    g_TarzanSurfingWithJaneActionSoundActive = '\0';
  }
  _g_TarzanSurfingWithJaneActionPhaseValue = 0;
  return;
}

