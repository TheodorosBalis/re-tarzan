/*
State 0x15 Enter: CPlayerHero::EnterYoungFatalDamageSequence
Address: 0x004911E0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\004911E0_CPlayerHero__EnterYoungFatalDamageSequence.c
*/


void CPlayerHero__EnterYoungFatalDamageSequence(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  DAT_0051ce00 = 0x40;
  iVar4 = FUN_0043fc90(*(undefined4 *)(g_PlayerSceneEntryData + 4),
                       *(undefined4 *)(g_PlayerSceneEntryData + 6),
                       *(undefined4 *)(g_PlayerSceneEntryData + 8),0x2e,0x11);
  iVar1 = *(int *)(iVar4 + 0x38);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(g_PlayerSceneEntryData + 4);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(g_PlayerSceneEntryData + 6);
    uVar2 = *(undefined4 *)(g_PlayerSceneEntryData + 8);
    *(ushort *)(iVar1 + 0xe) = *(ushort *)(iVar1 + 0xe) & 0x7fff;
    *(undefined4 *)(iVar1 + 0x1c) = uVar2;
    *(int *)(iVar1 + 0x10) = DAT_0051c6cc + 0x1a0;
    *(undefined2 *)(iVar1 + 0xc) = *g_PlayerSceneEntryData;
    *(undefined2 *)(iVar1 + 0xa0) = *(undefined2 *)(g_PlayerSceneEntry + 0xa0);
    *(undefined2 *)(iVar1 + 0xa2) = *(undefined2 *)(g_PlayerSceneEntry + 0xa2);
    *(undefined2 *)(iVar1 + 0xa4) = *(undefined2 *)(g_PlayerSceneEntry + 0xa4);
    *(undefined2 *)(iVar1 + 0xa6) = *(undefined2 *)(g_PlayerSceneEntry + 0xa6);
    iVar3 = g_PlayerSceneEntry;
    *(undefined4 *)(iVar1 + 0x10c) = *(undefined4 *)(g_PlayerSceneEntry + 0x10c);
    *(undefined4 *)(iVar1 + 0x110) = *(undefined4 *)(iVar3 + 0x110);
    *(undefined4 *)(iVar1 + 0x110) = *(undefined4 *)(g_PlayerSceneEntry + 0x110);
    *(undefined4 *)(iVar1 + 0x10c) = *(undefined4 *)(g_PlayerSceneEntry + 0x10c);
    *(undefined4 *)(iVar1 + 0x114) = *(undefined4 *)(g_PlayerSceneEntry + 0x114);
    *(undefined2 *)(iVar1 + 0x142) = *(undefined2 *)(g_PlayerSceneEntry + 0x142);
    iVar3 = g_PlayerSceneEntry;
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(g_PlayerSceneEntry + 0x14);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar3 + 0x18);
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(iVar3 + 0x1c);
    iVar3 = g_PlayerSceneEntry;
    *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(g_PlayerSceneEntry + 0x3c);
    *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(iVar3 + 0x40);
    *(undefined4 *)(iVar1 + 0x44) = *(undefined4 *)(iVar3 + 0x44);
    iVar3 = g_PlayerSceneEntry;
    *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(g_PlayerSceneEntry + 0x48);
    *(undefined4 *)(iVar1 + 0x4c) = *(undefined4 *)(iVar3 + 0x4c);
    *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(iVar3 + 0x50);
    iVar3 = g_PlayerSceneEntry;
    *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(g_PlayerSceneEntry + 0x54);
    *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar3 + 0x58);
    *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(iVar3 + 0x5c);
    g_ActiveCameraAnchorEntry = iVar4;
  }
  FUN_00435f50(0,0,0,0,0,0x1e);
  CPlayerHero__PlayAnimation(0x22);
  QueuePlayerDamageEvent(0,0x200);
  g_PlayerSequenceDelayTicks = 0x1e;
  return;
}


