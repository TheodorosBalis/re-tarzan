/*
State 0x2E Enter: CPlayerHero::EnterYoungClimbableSurfaceJumpOff
Address: 0x0048F5E0
*/


void CPlayerHero__EnterYoungClimbableSurfaceJumpOff(void)

{
  if (*(char *)(g_PlayerSceneEntry + 0x75) == '\0') {
    CPlayerHero__PlayAnimation(0x72);
    return;
  }
  CPlayerHero__PlayAnimation(0x6e);
  return;
}


