/*
State 0x23 Enter: CPlayerHero::EnterYoungClimbableSurfaceJumpOff
Address: 0x0048F5E0
*/


void CPlayerHero__EnterYoungClimbableSurfaceJumpOff(void)

{
  if (*(char *)(g_PlayerSceneEntry + 0x75) == '\0') {
    CPlayerHero_PlayAnimation(0x72);
    return;
  }
  CPlayerHero_PlayAnimation(0x6e);
  return;
}

