/*
State 0x0C Enter: CPlayerHero::EnterYoungPlayerDamage
Address: 0x00490FB0
*/


void CPlayerHero__EnterYoungPlayerDamage(void)

{
  undefined2 uVar1;
  char cVar2;
  
  CPlayerHero_PlayAnimation(0x20);
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  g_PlayerDamageInvulnerabilityTicks = 0x3c;
  g_PlayerDamageFlashTicks = 0x3c;
  CPlayerHero_ApplyDamageContactPushback();
  CPlayerHero_UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero_TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
    CPlayerHero__EnterYoungTarzanFalling();
    return;
  }
  return;
}

