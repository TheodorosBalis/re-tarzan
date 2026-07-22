#include "tarzan_ghidra_types.hpp"

// Address: 0x004605C0
// Label: CPlayerHero::EnterAdultTarzanElephantFatalDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanElephantFatalDamage(void)

{
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x19;
  PlayAudioById(0x59,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  *(undefined1 *)(g_PlayerEntitySceneObject + 0x74) = 0;
  g_GameplayRuntimeFlags = g_GameplayRuntimeFlags & 0xfffffffb;
  QueuePlayerDamageEvent(0,0x200);
  g_PlayerSequenceDelayTicks = 0xf;
  g_PlayerCurrentAnimationId = 4;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_AdultTarzanElephantFatalDamageAnimationScriptPtr
  ;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

