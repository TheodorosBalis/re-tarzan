/*
State 0x1D Enter: CPlayerHero::EnterYoungSwingToClimbableSurface
Address: 0x00492BE0
*/


void CPlayerHero__EnterYoungSwingToClimbableSurface(void)

{
  if (DAT_0051ce40 == '\0') {
    CPlayerHero__PlayAnimation(0x53);
    return;
  }
  CPlayerHero__PlayAnimation(0x57);
  return;
}


