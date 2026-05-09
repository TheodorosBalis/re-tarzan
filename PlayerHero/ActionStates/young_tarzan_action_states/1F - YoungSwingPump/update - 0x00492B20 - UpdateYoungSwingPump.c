/*
State 0x1F Update: CPlayerHero::UpdateYoungSwingPump
Address: 0x00492B20
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\00492B20_CPlayerHero__UpdateYoungSwingPump.c
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungSwingPump(void)

{
  undefined2 uVar1;
  int iVar2;
  
  if (g_CurrentSwingRuntimeEntry != 0) {
    if (((byte)g_PlayerInputHeldMask & 0xa0) == 0) {
      if (_DAT_0051cdd8 != 0) {
        _DAT_0051cdd8 = _DAT_0051cdd8 + -1;
      }
    }
    else {
      _DAT_0051cdd8 = 10;
    }
    iVar2 = UpdatePlayerOnSwing(g_CurrentSwingRuntimeEntry);
    uVar1 = g_PlayerActionState;
    if (iVar2 == 8) {
      PlayAudioById(0x12,0,g_PlayerSceneEntry + 0x14);
    }
    else if ((iVar2 == 0xc) && (_DAT_0051cdd8 == 0)) {
      g_PlayerActionState = 0x18;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x18 -> CPlayerHero::EnterYoungSwinging */
  CPlayerHero__EnterYoungSwinging();
    }
  }
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    *(undefined1 *)(g_PlayerSceneEntry + 0x75) = DAT_0051ce70;
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 0x1c;
    /* table enter state 0x1C -> CPlayerHero::EnterYoungSwingRelease */
  CPlayerHero__EnterYoungSwingRelease();
    return;
  }
  return;
}


