/*
State 0x13 Enter: CPlayerHero::EnterYoungApplyDamageOnTreeSurfing
Address: 0x004917B0
*/


void CPlayerHero__EnterYoungApplyDamageOnTreeSurfing(void)

{
  CPlayerHero_PlayAnimation(0x2b);
  DetachEntitySoundHandle(&DAT_0051ce90);
  PlayForceFeedbackEffect_Stub(0,2,0x10);
  return;
}

