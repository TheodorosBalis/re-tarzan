/*
State 0x3E Update: CPlayerHero::UpdateYoungTutorialPickupReturnIdle
Address: 0x00490E20
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\00490E20_CPlayerHero__UpdateYoungTutorialPickupReturnIdle.c
*/


void CPlayerHero__UpdateYoungTutorialPickupReturnIdle(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  
  g_PlayerDamageInvulnerabilityTicks = 0x3c;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  CPlayerHero__UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero__TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
  CPlayerHero__EnterYoungTarzanFalling();
    return;
  }
  iVar3 = CPlayerHero__AdvanceAnimationScript();
  uVar1 = g_PlayerActionState;
  if (iVar3 == 5) {
    g_PlayerActionState = 0;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x00 -> CPlayerHero::EnterYoungTarzanIdle */
  CPlayerHero__EnterYoungTarzanIdle();
    return;
  }
  return;
}


