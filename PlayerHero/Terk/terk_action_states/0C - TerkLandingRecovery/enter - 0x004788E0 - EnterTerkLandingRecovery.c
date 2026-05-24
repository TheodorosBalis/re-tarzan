/*
State 0x0C Enter: CPlayerHero::EnterTerkLandingRecovery
Address: 0x004788E0
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__EnterTerkLandingRecovery(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if ((g_PlayerCollisionContactFlags & 0x200000) != 0) {
    iVar1 = RandomModulo(4);
    if (iVar1 == 1) {
      uVar2 = 0x4c8;
    }
    else if (iVar1 == 2) {
      uVar2 = 0x4c9;
    }
    else if (iVar1 == 3) {
      uVar2 = 0x4ca;
    }
    else {
      uVar2 = 0x4cb;
    }
    PlayAudioById(uVar2,g_PlayerSceneEntry + 0x104,g_PlayerSceneEntry + 0x14);
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 7;
                    /* WARNING: Could not recover jumptable at 0x00478998. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_DAT_0050c180)();
    return;
  }
  if (((g_PlayerSurfaceTriggerPacket & 0x200) != 0) && ((g_PlayerInputHeldMask & 0x200000) != 0)) {
    PlayAudioById(0x28c,0,g_PlayerSceneEntry + 0x14);
    iVar1 = RandomModulo(4);
    if (iVar1 == 1) {
      uVar2 = 0x4c8;
    }
    else if (iVar1 == 2) {
      uVar2 = 0x4c9;
    }
    else if (iVar1 == 3) {
      uVar2 = 0x4ca;
    }
    else {
      uVar2 = 0x4cb;
    }
    PlayAudioById(uVar2,g_PlayerSceneEntry + 0x104,g_PlayerSceneEntry + 0x14);
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 7;
                    /* WARNING: Could not recover jumptable at 0x00478a53. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_DAT_0050c180)();
    return;
  }
  if ((g_PlayerSurfaceTriggerPacket & 0x100) != 0) {
    PlayAudioById(0x28b,0,g_PlayerSceneEntry + 0x14);
    iVar1 = RandomModulo(4);
    if (iVar1 == 1) {
      uVar2 = 0x4c8;
    }
    else if (iVar1 == 2) {
      uVar2 = 0x4c9;
    }
    else if (iVar1 == 3) {
      uVar2 = 0x4ca;
    }
    else {
      uVar2 = 0x4cb;
    }
    PlayAudioById(uVar2,g_PlayerSceneEntry + 0x104,g_PlayerSceneEntry + 0x14);
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 7;
                    /* WARNING: Could not recover jumptable at 0x00478af8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_DAT_0050c180)();
    return;
  }
  g_PlayerBounceChainCount = 0;
  if (g_PreviousPlayerActionState == 0xb) {
    if ((g_PlayerInputHeldMask & 0xa0) != 0) {
      g_PlayerCurrentAnimationId = 0x16;
      *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c298;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      goto LAB_00478b8e;
    }
    g_PlayerCurrentAnimationId = 0x15;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c294;
  }
  else {
    g_PlayerCurrentAnimationId = 0x15;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c294;
  }
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
LAB_00478b8e:
  CPlayerHero__AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  return;
}


