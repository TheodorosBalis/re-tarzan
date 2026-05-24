/*
State 0x1C Update: CPlayerHero::UpdateTerkClimbableWallJumpOff
Address: 0x004797F0
*/


void CPlayerHero__UpdateTerkClimbableWallJumpOff(void)

{
  int iVar1;
  
  iVar1 = CPlayerHero__AdvanceAnimationScript();
  if (iVar1 == 8) {
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x80;
    g_PlayerTargetMoveSpeed = 0x80;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x40;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 2;
    *(undefined4 *)(g_PlayerMotionState + 0x20) = 8;
    *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xf0;
    *(undefined4 *)(g_PlayerMotionState + 0x24) = 8;
    *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  }
  CPlayerHero__UpdateJumpArcVerticalMotion(0);
  return;
}


