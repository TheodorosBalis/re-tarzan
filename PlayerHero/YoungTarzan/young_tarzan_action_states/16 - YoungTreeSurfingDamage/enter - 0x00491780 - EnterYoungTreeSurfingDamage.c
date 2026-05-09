/*
State 0x16 Enter: CPlayerHero::EnterYoungTreeSurfingDamage
Address: 0x00491780
*/


void CPlayerHero__EnterYoungTreeSurfingDamage(void)

{
  CPlayerHero_PlayAnimation(0x2c);
  DetachEntitySoundHandle(&DAT_0051ce90);
  QueuePlayerDamageEvent(0,6);
  PlayForceFeedbackEffect_Stub(0,2,0x10);
  return;
}

