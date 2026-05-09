/*
State 0x2A Enter: CPlayerHero::EnterYoungClimbableWallGrab
Address: 0x0048F730
*/


void CPlayerHero__EnterYoungClimbableWallGrab(void)

{
  g_PlayerLatchedInteractionCollisionSurface = g_PlayerInteractionCollisionSurface;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  DAT_0051ce80 = 0;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  CPlayerHero_PlayAnimation(0x7d);
  CPlayerHero_AdvanceAnimationScript();
  g_PlayerTiltControlEnabled = 0;
  return;
}

