/*
State 0x03 Update: CPlayerHero::UpdateTerkTurnAround
Address: 0x00476F50
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateTerkTurnAround(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  
  uVar1 = g_PlayerActionState;
  if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  if (((g_PlayerCurrentAnimationId != 10) && ((_g_PlayerSequenceFlags & 0xf000) == 0)) &&
     ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    g_PlayerActionState = 6;
    g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00476fa3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CPlayerHero__EnterTerkStandingJump_0050c178)();
    return;
  }
  iVar3 = CPlayerHero__AdvanceAnimationScript();
  uVar1 = g_PlayerActionState;
  if (iVar3 == 6) {
    if (g_PlayerCurrentAnimationId == 10) {
      g_PlayerActionState = 0xd;
      g_PreviousPlayerActionState = uVar1;
      (*(code *)PTR_CPlayerHero__EnterTerkBlock_0050c1b0)();
      g_PlayerCurrentAnimationId = 0x1b;
      *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2ac;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      CPlayerHero__AdvanceAnimationScript();
    }
    else if (((_g_PlayerSequenceFlags & 0xf000) == 0) && (g_PlayerCurrentCollisionMode == 2)) {
      cVar2 = CPlayerHero__IsFacingCurrentCollisionSurface();
      uVar1 = g_PlayerActionState;
      if ((cVar2 == '\0') &&
         (((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0 &&
          (g_PlayerCollisionFacingFlags == '\0')))) {
        g_PlayerActionState = 1;
        g_PreviousPlayerActionState = uVar1;
        (*(code *)PTR_CPlayerHero__EnterTerkMoveForward_0050c150)();
      }
    }
  }
  else if (iVar3 == 0xd) {
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x40;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x30;
  }
  CPlayerHero__UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero__TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x004770b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CPlayerHero__EnterTerkFalling_0050c198)();
    return;
  }
  return;
}


