/*
State 0x2C Enter: CPlayerHero::EnterYoungClimbableWallMoveDown
Address: 0x0048F9B0
*/


void CPlayerHero__EnterYoungClimbableWallMoveDown(void)

{
  if (DAT_0051ce40 == '\0') {
    CPlayerHero_PlayAnimation(0x80);
    return;
  }
  CPlayerHero_PlayAnimation(0x81);
  return;
}

