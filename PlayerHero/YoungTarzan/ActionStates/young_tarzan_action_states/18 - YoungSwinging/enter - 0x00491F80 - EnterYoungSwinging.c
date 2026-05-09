/*
State 0x18 Enter: CPlayerHero::EnterYoungSwinging
Address: 0x00491F80
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\00491F80_CPlayerHero__EnterYoungSwinging.c
*/


void CPlayerHero__EnterYoungSwinging(void)

{
  int iVar1;
  
  if (g_CurrentSwingRuntimeEntry == 0) {
    if (DAT_0051ce40 == '\0') {
      CPlayerHero__PlayAnimation(0x52);
      DAT_0051ce80 = 0;
      return;
    }
    CPlayerHero__PlayAnimation(0x51);
    DAT_0051ce80 = 0;
    return;
  }
  iVar1 = FindRuntimeEntityAttachmentByFlags(g_CurrentSwingRuntimeEntry,0x8000000);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0xe) = 4;
  }
  if (g_PreviousPlayerActionState == 0x1f) {
    if (DAT_0051ce40 == '\0') {
      CPlayerHero__PlayAnimation(99);
      DAT_0051ce80 = 0;
      return;
    }
    CPlayerHero__PlayAnimation(0x62);
    DAT_0051ce80 = 0;
    return;
  }
  if (DAT_0051ce40 == '\0') {
    CPlayerHero__PlayAnimation(0x3e);
    DAT_0051ce80 = 0;
    return;
  }
  CPlayerHero__PlayAnimation(0x3d);
  DAT_0051ce80 = 0;
  return;
}


