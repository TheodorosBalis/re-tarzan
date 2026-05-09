/*
State 0x1C Update: CPlayerHero::UpdateYoungSwingRelease
Address: 0x004928D0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\004928D0_CPlayerHero__UpdateYoungSwingRelease.c
*/


void CPlayerHero__UpdateYoungSwingRelease(void)

{
  int iVar1;
  
  CPlayerHero__UpdateMovementAndCollision(1);
  CPlayerHero__UpdateJumpArcVerticalMotion(0);
  CPlayerHero__TrySnapDownToGround();
  iVar1 = CPlayerHero__AdvanceAnimationScript();
  if (iVar1 == 0xe) {
    DAT_0051ce04 = 1;
  }
  return;
}


