/*
State 0x18 Enter: CPlayerHero::EnterTerkClimbableWallGrab
Address: 0x00478E30
*/


void CPlayerHero__EnterTerkClimbableWallGrab(void)

{
  g_PlayerLatchedInteractionCollisionSurface = g_PlayerInteractionCollisionSurface;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  DAT_0051ce80 = 0;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  *(int *)(g_PlayerSceneEntryData + 0xc) =
       ((*(int *)(g_PlayerSceneEntryData + 0xc) - g_PlayerInteractionCollisionBaseY) / 0xa0) * 0xa0
       + g_PlayerInteractionCollisionBaseY;
  g_PlayerCurrentAnimationId = 0x23;
  *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2cc;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  g_PlayerTiltControlEnabled = 0;
  DAT_0051ce40 = (-(*(char *)(g_PlayerSceneEntry + 0x75) != '\0') & 1U) - 1;
  return;
}


