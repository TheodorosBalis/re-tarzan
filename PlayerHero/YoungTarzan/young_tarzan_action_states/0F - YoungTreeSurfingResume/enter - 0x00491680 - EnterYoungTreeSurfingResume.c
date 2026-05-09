/*
State 0x0F Enter: CPlayerHero::EnterYoungTreeSurfingResume
Address: 0x00491680
*/


void CPlayerHero__EnterYoungTreeSurfingResume(void)

{
  CPlayerHero__PlayAnimation(0x2d);
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = DAT_0051ce00;
  return;
}


