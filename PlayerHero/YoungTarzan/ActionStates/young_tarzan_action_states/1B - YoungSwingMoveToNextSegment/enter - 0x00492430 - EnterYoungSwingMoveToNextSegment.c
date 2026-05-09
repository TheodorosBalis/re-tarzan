/*
State 0x1B Enter: CPlayerHero::EnterYoungSwingMoveToNextSegment
Address: 0x00492430
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\00492430_CPlayerHero__EnterYoungSwingMoveToNextSegment.c
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__EnterYoungSwingMoveToNextSegment(void)

{
  undefined2 uVar1;
  int iVar2;
  
  if (g_CurrentSwingRuntimeEntry != 0) {
    iVar2 = FindRuntimeEntityAttachmentByFlags(g_CurrentSwingRuntimeEntry,0x8000000);
    uVar1 = g_PlayerActionState;
    if (iVar2 == 0) {
      g_PlayerActionState = 0x18;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x18 -> CPlayerHero::EnterYoungSwinging */
  CPlayerHero__EnterYoungSwinging();
      return;
    }
    *(undefined2 *)(iVar2 + 0xe) = 4;
    uVar1 = g_PlayerActionState;
    if (0xc < g_CurrentSwingSegmentIndex) {
      g_PlayerActionState = 0x18;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x18 -> CPlayerHero::EnterYoungSwinging */
  CPlayerHero__EnterYoungSwinging();
      return;
    }
  }
  if (g_PreviousPlayerActionState == 0x18) {
    if (*(byte *)(g_PlayerSceneEntry + 0x75) != g_PlayerFacingBeforeSwing) {
      *(byte *)(g_PlayerSceneEntry + 0x75) = ~*(byte *)(g_PlayerSceneEntry + 0x75);
      *(ushort *)(g_PlayerSceneEntry + 0xa2) = *(ushort *)(g_PlayerSceneEntry + 0xa2) ^ 0x800;
    }
  }
  if (DAT_0051ce40 == '\0') {
    CPlayerHero__PlayAnimation(0x47);
    return;
  }
  CPlayerHero__PlayAnimation(0x46);
  return;
}


