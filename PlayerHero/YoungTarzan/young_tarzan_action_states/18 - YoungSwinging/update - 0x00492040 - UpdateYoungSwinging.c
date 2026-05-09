/*
State 0x18 Update: CPlayerHero::UpdateYoungSwinging
Address: 0x00492040
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungSwinging(void)

{
  undefined2 uVar1;
  int iVar2;
  
  uVar1 = g_PlayerActionState;
  if (g_CurrentSwingRuntimeEntry == 0) {
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && (g_PlayerCurrentCollisionSurface != 0)) {
      if ((g_PlayerInputHeldMask & 0x200000) != 0) {
        g_PlayerActionState = 7;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
        CPlayerHero__EnterYoungTarzanFalling();
        return;
      }
      if (((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0) &&
         ((*(byte *)(g_PlayerCurrentCollisionSurface + 0x14) & 0x10) != 0)) {
        g_PlayerActionState = 0x1d;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x1D -> CPlayerHero::EnterYoungSwingToClimbableSurface */
        CPlayerHero__EnterYoungSwingToClimbableSurface();
        return;
      }
    }
  }
  else {
    if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
      if (((g_PlayerInputHeldMask & 0x10) != 0) && (2 < g_CurrentSwingSegmentIndex)) {
        g_PlayerActionState = 0x19;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x19 -> CPlayerHero::EnterYoungSwingMoveToPreviousSegment */
        CPlayerHero__EnterYoungSwingMoveToPreviousSegment();
LAB_004920ea:
        *(undefined2 *)(g_PlayerSceneEntry + 0x78) = 0;
        *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 0;
        return;
      }
      if (((g_PlayerInputHeldMask & 0x40) != 0) && (g_CurrentSwingSegmentIndex < 0xd)) {
        g_PlayerActionState = 0x1b;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x1B -> CPlayerHero::EnterYoungSwingMoveToNextSegment */
        CPlayerHero__EnterYoungSwingMoveToNextSegment();
        goto LAB_004920ea;
      }
      if ((g_PlayerInputPressedMask & 0x200000) != 0) {
        g_PlayerActionState = 0x1c;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x1C -> CPlayerHero::EnterYoungSwingRelease */
        CPlayerHero__EnterYoungSwingRelease();
        goto LAB_004920ea;
      }
    }
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
       ((g_PlayerInputPressedMask & g_CameraFollowFlags) != 0)) {
      g_PlayerActionState = 0x1f;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x1F -> CPlayerHero::EnterYoungSwingPump */
      CPlayerHero__EnterYoungSwingPump();
      *(undefined2 *)(g_PlayerSceneEntry + 0x78) = 0;
      *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 0;
      return;
    }
    UpdatePlayerOnSwing(g_CurrentSwingRuntimeEntry);
  }
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    *(byte *)(g_PlayerSceneEntry + 0x75) = ~*(byte *)(g_PlayerSceneEntry + 0x75);
  }
  iVar2 = CPlayerHero_AdvanceAnimationScript();
  if ((0x3c < iVar2) && (iVar2 < 0x3f)) {
    if (*(byte *)(g_PlayerSceneEntry + 0x75) != g_PlayerFacingBeforeSwing) {
      *(byte *)(g_PlayerSceneEntry + 0x75) = ~*(byte *)(g_PlayerSceneEntry + 0x75);
      *(ushort *)(g_PlayerSceneEntry + 0xa2) = *(ushort *)(g_PlayerSceneEntry + 0xa2) ^ 0x800;
    }
    CPlayerHero_PlayAnimation(iVar2);
  }
  CPlayerHero_UpdateMovementAndCollision(0);
  return;
}

