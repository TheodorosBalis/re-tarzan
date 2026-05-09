/*
State 0x00 Enter: CPlayerHero::EnterYoungTarzanIdle
Address: 0x0048CC80
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\0048CC80_CPlayerHero__EnterYoungTarzanIdle.c
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__EnterYoungTarzanIdle(void)

{
  undefined2 uVar1;
  short sVar2;
  
  uVar1 = g_PlayerActionState;
  g_PlayerInteractionLockFlags = 0;
  DAT_0053a2e8 = 0;
  if (g_PlayerCurrentCollisionMode != 4) {
    CPlayerHero__PlayAnimation(8);
    sVar2 = RandomModulo(10);
    g_PlayerIdleFidgetDelayTicks = sVar2 + 5;
    g_PlayerTiltControlEnabled = 0;
    return;
  }
  g_PlayerActionState = 0x26;
  g_PreviousPlayerActionState = uVar1;
  /* table enter state 0x26 -> CPlayerHero::EnterYoungWaterIdle */
  CPlayerHero__EnterYoungWaterIdle();
  return;
}


