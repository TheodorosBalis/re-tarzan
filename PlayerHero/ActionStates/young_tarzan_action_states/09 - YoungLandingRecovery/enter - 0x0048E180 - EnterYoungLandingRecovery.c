/*
State 0x09 Enter: CPlayerHero::EnterYoungLandingRecovery
Address: 0x0048E180
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\0048E180_CPlayerHero__EnterYoungLandingRecovery.c
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__EnterYoungLandingRecovery(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if (DAT_005314ac != 0) {
    *(undefined2 *)(DAT_005314ac + 0x48) = 7;
  }
  uVar1 = g_PlayerActionState;
  DAT_005314ac = 0;
  if (g_PlayerCurrentCollisionMode == 5) {
    g_PlayerActionState = 0x12;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x12 -> CPlayerHero::EnterYoungSurfingMode */
  CPlayerHero__EnterYoungSurfingMode();
    return;
  }
  if (g_PlayerInteractionLockFlags == 0x4000) {
    uVar3 = 0x19;
  }
  else {
    if (DAT_0051cdf0 == 0x15) {
      CPlayerHero__PlayAnimation(0x18);
      _DAT_0051c510 = 0x28;
      _DAT_0051c514 = 8;
      FUN_004abce0(0,2,0xf);
      goto LAB_0048e373;
    }
    if ((g_PlayerCollisionContactFlags & 0x800000) != 0) {
      QueuePlayerDamageEvent(0,5);
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x30;
      /* table enter state 0x30 -> CPlayerHero::EnterYoungApplyDamageOnJumping */
  CPlayerHero__EnterYoungApplyDamageOnJumping();
      return;
    }
    if ((g_PlayerCollisionContactFlags & 0x200000) != 0) {
      iVar2 = RandomModulo(4);
      if (iVar2 == 1) {
        uVar3 = 0x32;
      }
      else if (iVar2 == 2) {
        uVar3 = 0x33;
      }
      else if (iVar2 == 3) {
        uVar3 = 0x34;
      }
      else {
        uVar3 = 0x35;
      }
      PlayAudioById(uVar3,g_PlayerSceneEntry + 0x104,g_PlayerSceneEntry + 0x14);
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x31;
      /* table enter state 0x31 -> CPlayerHero::EnterYoungBouncingMode */
  CPlayerHero__EnterYoungBouncingMode();
      return;
    }
    if (((g_PlayerSurfaceTriggerPacket & 0x200) != 0) && ((g_PlayerInputHeldMask & 0x200000) != 0))
    {
      g_PlayerActionState = 0x31;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x31 -> CPlayerHero::EnterYoungBouncingMode */
  CPlayerHero__EnterYoungBouncingMode();
      return;
    }
    if ((g_PlayerSurfaceTriggerPacket & 0x100) != 0) {
      g_PlayerActionState = 0x31;
      g_PreviousPlayerActionState = uVar1;
      (*(code *)PTR_FUN_0050a170)();
      return;
    }
    DAT_0051cebc = 0;
    if ((g_PreviousPlayerActionState == 8) && ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0))
    {
      uVar3 = 0x17;
    }
    else {
      uVar3 = 0x16;
    }
  }
  CPlayerHero__PlayAnimation(uVar3);
LAB_0048e373:
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  return;
}


