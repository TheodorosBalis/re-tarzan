/*
State 0x36 Enter: CPlayerHero::EnterYoungTutorialPickupReaction
Address: 0x004905D0
*/


void CPlayerHero__EnterYoungTutorialPickupReaction(void)

{
  if ((uint)*(byte *)(g_PlayerSceneEntry + 0x75) == *(uint *)(&DAT_00515248 + DAT_0053a2dc * 0x30))
  {
    CPlayerHero__PlayAnimation(0x94);
    return;
  }
  CPlayerHero__PlayAnimation(0x93);
  return;
}


