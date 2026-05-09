/*
State 0x36 Update: CPlayerHero::UpdateYoungTutorialPickupReaction
Address: 0x00490610
*/


void CPlayerHero__UpdateYoungTutorialPickupReaction(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  
  CPlayerHero_UpdateMovementAndCollision(1);
  uVar1 = g_PlayerActionState;
  g_PlayerDamageInvulnerabilityTicks = 0x3c;
  if (DAT_0053a2e8 == 2) {
    g_PlayerActionState = 0x37;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x37 -> CPlayerHero::EnterYoungTarzanAndTerkTutorialPickupSequence */
    CPlayerHero__EnterYoungTarzanAndTerkTutorialPickupSequence();
    return;
  }
  cVar2 = CPlayerHero_TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
    CPlayerHero__EnterYoungTarzanFalling();
    return;
  }
  iVar3 = CPlayerHero_AdvanceAnimationScript();
  if (iVar3 == 5) {
    DAT_0053a2e8 = 1;
  }
  else {
    if (iVar3 == 6) {
      *(byte *)(g_PlayerSceneEntry + 0x75) = ~*(byte *)(g_PlayerSceneEntry + 0x75);
      *(ushort *)(g_PlayerSceneEntry + 0xa2) = *(ushort *)(g_PlayerSceneEntry + 0xa2) ^ 0x800;
      return;
    }
    if (iVar3 == 8) {
      CPlayerHero_PlayAnimation(0x94);
      return;
    }
  }
  return;
}

