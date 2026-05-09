/*
State 0x12 Enter: CPlayerHero::EnterYoungSurfingMode
Address: 0x00491470
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\00491470_CPlayerHero__EnterYoungSurfingMode.c
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__EnterYoungSurfingMode(void)

{
  *(undefined1 *)(g_PlayerSceneEntry + 0x75) = 0;
  PlayAudioById(0x28,g_PlayerSceneEntry + 0x104,g_PlayerSceneEntry + 0x14);
  CPlayerHero__PlayAnimation(0x29);
  PlayAudioById(0x29,&DAT_0051ce90,g_PlayerSceneEntry + 0x14);
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0xa0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0xa0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x80;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  _DAT_0053a2c0 = 0xffffffff;
  return;
}


