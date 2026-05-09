/*
State 0x26 Enter: CPlayerHero::EnterYoungWaterIdle
Address: 0x004901A0
*/


void CPlayerHero__EnterYoungWaterIdle(void)

{
  CPlayerHero_PlayAnimation(0x79);
  g_PlayerTiltControlEnabled = 0;
  return;
}

