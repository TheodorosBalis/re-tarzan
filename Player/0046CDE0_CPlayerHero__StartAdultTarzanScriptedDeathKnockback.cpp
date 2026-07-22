#include "tarzan_ghidra_types.hpp"

// Address: 0x0046CDE0
// Label: CPlayerHero::StartAdultTarzanScriptedDeathKnockback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::StartAdultTarzanScriptedDeathKnockback(undefined4 arg1)

{
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = 0x31;
  (*(code *)g_AdultTarzanEnterScriptedDeathKnockbackHandlerPtr)();
  CPlayerHero::BeginScriptedMotionSequence(arg1,0x20,0,0x30,8,0x1e);
  *(int *)(g_PlayerMotionState + 0x10) = *(int *)(g_PlayerEntitySceneObjectData + 8) / 0x96;
  *(int *)(g_PlayerMotionState + 0x30) = *(int *)(g_PlayerEntitySceneObjectData + 0x10) / 0x96;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x10;
  CPlayerHero::PlayAdultTarzanAnimation(0x17);
  g_PlayerDamageInvulnerabilityTicks = 0;
  g_PlayerDamageFlashTicks = 0;
  *(byte *)(g_PlayerEntitySceneObjectData + 3) = *(byte *)(g_PlayerEntitySceneObjectData + 3) | 0x80
  ;
  return;
}

