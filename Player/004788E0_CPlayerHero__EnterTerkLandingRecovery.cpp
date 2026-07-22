#include "tarzan_ghidra_types.hpp"

// Address: 0x004788E0
// Label: CPlayerHero::EnterTerkLandingRecovery
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterTerkLandingRecovery(void)

{
  int value;
  undefined4 value2;
  
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if ((g_PlayerCollisionContactFlags & 0x200000) != 0) {
    value = RandomModulo(4);
    if (value == 1) {
      value2 = 0x4c8;
    }
    else if (value == 2) {
      value2 = 0x4c9;
    }
    else if (value == 3) {
      value2 = 0x4ca;
    }
    else {
      value2 = 0x4cb;
    }
    PlayAudioById(value2,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 7;
                    /* WARNING: Could not recover jumptable at 0x00478998. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_g_TerkEnterBounceHandlerPtr)();
    return;
  }
  if (((g_PlayerSurfaceTriggerPacket & 0x200) != 0) && ((g_PlayerInputHeldMask & 0x200000) != 0)) {
    PlayAudioById(0x28c,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    value = RandomModulo(4);
    if (value == 1) {
      value2 = 0x4c8;
    }
    else if (value == 2) {
      value2 = 0x4c9;
    }
    else if (value == 3) {
      value2 = 0x4ca;
    }
    else {
      value2 = 0x4cb;
    }
    PlayAudioById(value2,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 7;
                    /* WARNING: Could not recover jumptable at 0x00478a53. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_g_TerkEnterBounceHandlerPtr)();
    return;
  }
  if ((g_PlayerSurfaceTriggerPacket & 0x100) != 0) {
    PlayAudioById(0x28b,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    value = RandomModulo(4);
    if (value == 1) {
      value2 = 0x4c8;
    }
    else if (value == 2) {
      value2 = 0x4c9;
    }
    else if (value == 3) {
      value2 = 0x4ca;
    }
    else {
      value2 = 0x4cb;
    }
    PlayAudioById(value2,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 7;
                    /* WARNING: Could not recover jumptable at 0x00478af8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_g_TerkEnterBounceHandlerPtr)();
    return;
  }
  g_PlayerBounceChainCount = 0;
  if (g_PreviousPlayerActionState == 0xb) {
    if ((g_PlayerInputHeldMask & 0xa0) != 0) {
      g_PlayerCurrentAnimationId = 0x16;
      *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkLandingRecoveryTiming;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      goto LAB_00478b8e;
    }
    g_PlayerCurrentAnimationId = 0x15;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkLandingRecoveryAnimationScript;
  }
  else {
    g_PlayerCurrentAnimationId = 0x15;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkLandingRecoveryAnimationScript;
  }
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
LAB_00478b8e:
  CPlayerHero::AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  return;
}

