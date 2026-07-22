#include "tarzan_ghidra_types.hpp"

// Address: 0x004704B0
// Label: CPlayerHero::EnterAdultTarzanFreeMovementLandingRecovery
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanFreeMovementLandingRecovery(void)

{
  int value;
  undefined4 value2;
  
  if (((g_PreviousPlayerActionState == 8) || (g_PreviousPlayerActionState == 0x10)) ||
     (g_PreviousPlayerActionState == 0x48)) {
    value2 = 0x19;
  }
  else {
    value2 = 0x18;
  }
  CPlayerHero::PlayAdultTarzanAnimation(value2);
  if ((g_PlayerCollisionContactFlags & 0x800000) != 0) {
    QueuePlayerDamageEvent(0,5);
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 0x2e;
                    /* WARNING: Could not recover jumptable at 0x00470502. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_AdultTarzanEnterAirborneDamageHandlerPtr)();
    return;
  }
  if ((g_PlayerCollisionContactFlags & 0x200000) != 0) {
    value = RandomModulo(4);
    if (value == 1) {
      value2 = 99;
    }
    else if (value == 2) {
      value2 = 100;
    }
    else if (value == 3) {
      value2 = 0x65;
    }
    else {
      value2 = 0x66;
    }
    PlayAudioById(value2,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 0x2d;
                    /* WARNING: Could not recover jumptable at 0x0047057e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_AdultTarzanEnterBounceHandlerPtr)();
    return;
  }
  if (((g_PlayerSurfaceTriggerPacket & 0x200) != 0) && ((g_PlayerInputHeldMask & 0x200000) != 0)) {
    value = RandomModulo(4);
    if (value == 1) {
      value2 = 99;
    }
    else if (value == 2) {
      value2 = 100;
    }
    else if (value == 3) {
      value2 = 0x65;
    }
    else {
      value2 = 0x66;
    }
    PlayAudioById(value2,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    PlayAudioById(0x28c,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 0x2d;
                    /* WARNING: Could not recover jumptable at 0x00470629. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_AdultTarzanEnterBounceHandlerPtr)();
    return;
  }
  if ((g_PlayerSurfaceTriggerPacket & 0x100) != 0) {
    value = RandomModulo(4);
    if (value == 1) {
      value2 = 99;
    }
    else if (value == 2) {
      value2 = 100;
    }
    else if (value == 3) {
      value2 = 0x65;
    }
    else {
      value2 = 0x66;
    }
    PlayAudioById(value2,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    PlayAudioById(0x28b,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 0x2d;
                    /* WARNING: Could not recover jumptable at 0x004706bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_AdultTarzanEnterBounceHandlerPtr)();
    return;
  }
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  return;
}

