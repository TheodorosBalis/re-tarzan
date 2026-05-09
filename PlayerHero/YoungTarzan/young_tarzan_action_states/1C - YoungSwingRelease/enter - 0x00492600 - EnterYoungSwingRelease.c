/*
State 0x1C Enter: CPlayerHero::EnterYoungSwingRelease
Address: 0x00492600
*/


void CPlayerHero__EnterYoungSwingRelease(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  
  uVar6 = 0;
  sVar5 = 0;
  iVar2 = FindRuntimeEntityAttachmentByFlags(g_CurrentSwingRuntimeEntry,0x8000000);
  if (iVar2 != 0) {
    *(undefined2 *)(iVar2 + 0xe) = 4;
    uVar6 = (uint)*(ushort *)(g_ActiveSwingMotionTable + 8 + (uint)*(ushort *)(iVar2 + 0x10) * 0xc);
    sVar5 = *(short *)(g_ActiveSwingMotionTable + 10 + (uint)*(ushort *)(iVar2 + 0x10) * 0xc);
  }
  uVar1 = g_PlayerActionState;
  if (g_CurrentSwingRuntimeEntry != 0) {
    PlayAudioById(0x17,0,g_PlayerSceneEntry + 0x14);
    if ((g_PreviousPlayerActionState == 0x1f) && (uVar6 != 0)) {
      SnapSceneEntryVerticalPositionToCurrentSurface(g_PlayerSceneEntry);
      iVar2 = *(int *)(g_PlayerSceneEntryData + 8) - *(int *)(g_PlayerSceneEntry + 0x48);
      iVar3 = *(int *)(g_PlayerSceneEntryData + 0xc) - *(int *)(g_PlayerSceneEntry + 0x4c);
      iVar4 = *(int *)(g_PlayerSceneEntryData + 0x10) - *(int *)(g_PlayerSceneEntry + 0x50);
      iVar2 = SqrtToInt(iVar4 * iVar4 + iVar3 * iVar3 + iVar2 * iVar2);
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x30;
      g_PlayerTargetMoveSpeed = 0x30;
      *(int *)(g_PlayerMotionState + 0x10) = (iVar2 >> 7) + 0x10;
      *(undefined4 *)(g_PlayerMotionState + 0x18) = 0;
      *(undefined4 *)(g_PlayerMotionState + 0x14) = 2;
      *(undefined4 *)(g_PlayerMotionState + 0x20) = *(undefined4 *)(g_PlayerMotionState + 0x10);
      *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x60;
      *(undefined4 *)(g_PlayerMotionState + 0x24) = 4;
      *(undefined4 *)(g_PlayerMotionState + 0x28) = 5;
      *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
      iVar2 = g_CurrentSwingSegmentIndex;
      if (0xd < g_CurrentSwingSegmentIndex) {
        iVar2 = 0xd;
      }
      *(int *)(g_PlayerMotionState + 0x20) = iVar2 * 4 + 0xc;
      if (*(int *)(g_PlayerMotionState + 0x20) < 0x1c) {
        *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x1c;
      }
      CPlayerHero_UpdateMovementAndCollision(1);
      CPlayerHero_UpdateJumpArcVerticalMotion(0);
      g_PlayerMoveHeadingAngle = *(ushort *)(g_PlayerSceneEntry + 0x132);
      if (*(char *)(g_PlayerSceneEntry + 0x75) == '\0') {
        g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle ^ 0x800;
      }
      *(ushort *)(g_PlayerSceneEntry + 0xa2) = g_PlayerMoveHeadingAngle;
      DAT_0051cdf0 = (undefined2)uVar6;
      *(undefined **)(g_PlayerAnimationState + 0xc) = (&g_PlayerAnimationScriptPointerTable)[uVar6];
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(short *)(g_PlayerAnimationState + 0x16) = sVar5 + -1;
      CPlayerHero_AdvanceAnimationScript();
      g_PlayerJumpArcActive = 0;
      return;
    }
    if (g_PreviousPlayerActionState == 0x18) {
      if (*(byte *)(g_PlayerSceneEntry + 0x75) != g_PlayerFacingBeforeSwing) {
        *(byte *)(g_PlayerSceneEntry + 0x75) = ~*(byte *)(g_PlayerSceneEntry + 0x75);
        *(ushort *)(g_PlayerSceneEntry + 0xa2) = *(ushort *)(g_PlayerSceneEntry + 0xa2) ^ 0x800;
      }
    }
    SnapSceneEntryVerticalPositionToCurrentSurface(g_PlayerSceneEntry);
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    g_PlayerTargetMoveSpeed = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 4;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 2;
    *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x10;
    *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x60;
    *(undefined4 *)(g_PlayerMotionState + 0x24) = 4;
    *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
    CPlayerHero_UpdateMovementAndCollision(1);
    g_PlayerMoveHeadingAngle = *(ushort *)(g_PlayerSceneEntry + 0x132);
    if (*(char *)(g_PlayerSceneEntry + 0x75) == '\0') {
      g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle ^ 0x800;
    }
    *(ushort *)(g_PlayerSceneEntry + 0xa2) = g_PlayerMoveHeadingAngle;
    CPlayerHero_PlayAnimation(0x4f);
    return;
  }
  g_PlayerActionState = 7;
  g_PreviousPlayerActionState = uVar1;
  /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
  CPlayerHero__EnterYoungTarzanFalling();
  return;
}

