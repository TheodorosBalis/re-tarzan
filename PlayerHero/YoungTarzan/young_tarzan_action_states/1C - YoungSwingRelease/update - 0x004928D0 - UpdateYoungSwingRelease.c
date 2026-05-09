/*
State 0x1C Update: CPlayerHero::UpdateYoungSwingRelease
Address: 0x004928D0
*/


void CPlayerHero__UpdateYoungSwingRelease(void)

{
  int iVar1;
  
  CPlayerHero_UpdateMovementAndCollision(1);
  CPlayerHero_UpdateJumpArcVerticalMotion(0);
  CPlayerHero_TrySnapDownToGround();
  iVar1 = CPlayerHero_AdvanceAnimationScript();
  if (iVar1 == 0xe) {
    g_PlayerJumpArcActive = 1;
  }
  return;
}

