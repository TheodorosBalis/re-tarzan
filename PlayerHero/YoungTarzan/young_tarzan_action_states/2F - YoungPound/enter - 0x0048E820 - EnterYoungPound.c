/*
State 0x2F Enter: CPlayerHero::EnterYoungPound
Address: 0x0048E820
*/


void CPlayerHero__EnterYoungPound(void)

{
  CPlayerHero__PlayAnimation(0x1e);
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  PlayAudioById(10,&DAT_0051ce90,g_PlayerSceneEntry + 0x14);
  return;
}


