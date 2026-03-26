// Address: 0x0045EB50

void CMenu__LevelComplete_UpdateTARZANSlots(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  undefined4 uVar5;
  
  iVar1 = *(int *)(&g_LevelCompleteRewardSlotPtrTable + param_1 * 0xc);
  uVar2 = *(uint *)(iVar1 + 0x58);
  uVar3 = uVar2 + 0x800;
  *(uint *)(iVar1 + 0x58) = uVar3;
  bVar4 = (byte)param_1;
  if ((0x63ff < (int)(uVar3 & 0xffffff00)) || (g_LevelCompleteFastForwardRequested != 0)) {
    g_LevelCompleteRewardSlotDoneMask = g_LevelCompleteRewardSlotDoneMask | 1 << (bVar4 & 0x1f);
    if ((int)(uVar2 & 0xffffff00) < 0x6400) {
      if ((g_LevelTransitionRewardMask6 >> (bVar4 & 0x1f) & 1) == 0) {
        uVar5 = 0x3db;
      }
      else {
        uVar5 = 0x3dc;
      }
      LoadSoundFileAndInitAudio(uVar5,0,0);
    }
    *(uint *)(iVar1 + 0x58) = (uint)CONCAT11(100,(char)*(undefined4 *)(iVar1 + 0x58));
  }
  CMenu__LevelComplete_AddSlotSpin(iVar1,0x3c);
  if ((g_LevelTransitionRewardMask6 >> (bVar4 & 0x1f) & 1) != 0) {
    *(ushort *)(iVar1 + 0xe) = *(ushort *)(iVar1 + 0xe) & 0xfbde;
    return;
  }
  *(ushort *)(iVar1 + 0xe) = *(ushort *)(iVar1 + 0xe) | 0x421;
  *(int *)(iVar1 + 0x30) =
       ((int)(short)(&DAT_0077c788)[(TotalGameLoopTicks + -4) * 0x100 + param_1 * 400 & 0xfff] >> 2)
       + 0x600;
  return;
}


