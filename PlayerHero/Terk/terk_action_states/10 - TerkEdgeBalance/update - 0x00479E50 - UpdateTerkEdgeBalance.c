/*
State 0x10 Update: CPlayerHero::UpdateTerkEdgeBalance
Address: 0x00479E50
*/


void CPlayerHero__UpdateTerkEdgeBalance(void)

{
  undefined2 uVar1;
  uint uVar2;
  short sVar3;
  uint uVar4;
  bool bVar5;
  
  uVar1 = g_PlayerActionState;
  if (((g_PlayerEdgeBalanceInputMask & g_PlayerInputHeldMask) != 0) &&
     (sVar3 = DAT_0051ce60 + 1, bVar5 = DAT_0051ce60 < 0, DAT_0051ce60 = sVar3, bVar5)) {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = uVar1;
    (*(code *)PTR_CPlayerHero__EnterTerkFalling_0050c198)();
    return;
  }
  if ((g_PlayerEdgeBalanceInputMask & g_PlayerInputHeldMask) == 0) {
    if (5 < DAT_0051ce60) {
      g_PlayerActionState = 10;
      g_PreviousPlayerActionState = uVar1;
      DAT_0051ce60 = DAT_0051ce60 + 1;
      (*(code *)PTR_CPlayerHero__EnterTerkFalling_0050c198)();
      return;
    }
    DAT_0051ce60 = -8;
  }
  uVar4 = 0;
  uVar2 = 0;
  if ((g_PlayerInputHeldMask & 0x10) != 0) {
    uVar4 = -DAT_0051ce78;
  }
  if ((g_PlayerInputHeldMask & 0x40) != 0) {
    uVar4 = DAT_0051ce78;
  }
  if ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0) {
    uVar2 = -DAT_0051ce78;
  }
  if ((g_CameraFollowFlags & g_PlayerInputHeldMask & 0xffffffef) != 0) {
    uVar2 = DAT_0051ce78;
  }
  if (*(char *)(g_PlayerSceneEntry + 0x75) != '\0') {
    uVar2 = ~uVar2 + 1;
  }
  CPlayerHero__ApplyEdgeBalanceMovementDeltas(uVar2,uVar4);
  return;
}



