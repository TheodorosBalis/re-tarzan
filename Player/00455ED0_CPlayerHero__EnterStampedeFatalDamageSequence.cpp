#include "tarzan_ghidra_types.hpp"

// Address: 0x00455ED0
// Label: CPlayerHero::EnterStampedeFatalDamageSequence
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterStampedeFatalDamageSequence(void)

{
  int value;
  int value2;
  int value3;
  int value4;
  
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x24;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 3;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 3;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xffffff38;
  g_StampedeWorldConstraintUpdatesEnabled = 0;
  value3 = *(int *)(g_PlayerEntitySceneObject + 0x14) - g_StampedeCameraTargetX;
  value4 = *(int *)(g_PlayerEntitySceneObject + 0x1c) - g_StampedeCameraTargetZ;
  value2 = *(int *)(g_PlayerEntitySceneObject + 0x18) - g_StampedeCameraTargetY;
  value = SqrtToInt(value3 * value3 + value4 * value4);
  _g_StampedeEntryCameraX = GetAngleFromXZVector12Bit(value2,value >> 6);
  _g_StampedeEntryCameraX = _g_StampedeEntryCameraX & 0xfff;
  _g_StampedeEntryCameraZ = GetAngleFromXZVector12Bit(value3,value4);
  _g_StampedeEntryCameraZ = _g_StampedeEntryCameraZ & 0xfff;
  value = SqrtToInt(value2 * value2 + value3 * value3 + value4 * value4);
  _g_StampedeFatalDamageSequenceState = (value >> 6) / 0x30;
  _g_StampedeFatalDamageFallTicks = 1;
  _g_StampedeFatalDamageFadeTicks = 0;
  _g_StampedeFatalDamageCameraState = *(int *)(g_PlayerEntitySceneObject + 0x18) + 0x100;
  g_GameplayRuntimeFlags = g_GameplayRuntimeFlags & 0xfffffffb;
  _g_StampedeElephantRideCooldown = _g_StampedeFatalDamageSequenceState;
  QueuePlayerDamageEvent(0,0x200);
  g_PlayerSequenceDelayTicks = 0x14;
  g_StampedeCameraTrackPaused = 1;
  PlayAudioById(0x1dd,(int *)0,(undefined4 *)0);
  g_PlayerCurrentAnimationId = 6;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_StampedeFatalDamageAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

