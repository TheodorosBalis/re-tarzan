/*
State 0x10 Enter: CPlayerHero::EnterTerkEdgeBalance
Address: 0x00479E00
*/


void CPlayerHero__EnterTerkEdgeBalance(void)

{
  int iVar1;
  
  if (g_CurrentSwingRuntimeEntry != 0) {
    iVar1 = FindRuntimeEntityAttachmentByFlags(g_CurrentSwingRuntimeEntry,0x8000000);
    if (iVar1 != 0) {
      *(undefined2 *)(iVar1 + 0xe) = 8;
    }
  }
  *g_PlayerSceneEntryData = 0;
  DAT_0051ce60 = 0;
  DAT_0051ce78 = 0x20;
  *(undefined2 *)(g_PlayerSceneEntry + 0x142) = 0x100;
  return;
}



