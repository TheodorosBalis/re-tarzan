/*
State 0x0F Enter: CPlayerHero::EnterTerkGroundDamage
Address: 0x00479FA0
*/


void CPlayerHero__EnterTerkGroundDamage(void)

{
  undefined2 uVar1;
  char cVar2;
  
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  g_PlayerCurrentAnimationId = 0x1f;
  *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2bc;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  *(undefined2 *)(g_PlayerSceneEntry + 0x142) = 0x100;
  g_PlayerDamageInvulnerabilityTicks = 0x3c;
  g_PlayerDamageFlashTicks = 0x3c;
  CPlayerHero__ApplyDamageContactPushback();
  CPlayerHero__UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero__TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x0047a08e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CPlayerHero__EnterTerkFalling_0050c198)();
    return;
  }
  return;
}


