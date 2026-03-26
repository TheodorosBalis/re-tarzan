// Address: 0x0045EAE0

void CMenu__LevelComplete_InitRewardSlot(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 0x144;
  *(undefined **)(&g_LevelCompleteRewardSlotPtrTable + param_1 * 0xc) =
       &g_LevelCompleteRewardSlotScenes + iVar1;
  *(undefined4 *)(&DAT_0053918c + iVar1) = 0;
  *(undefined4 *)(&DAT_00539190 + iVar1) = 0;
  *(undefined4 *)(&DAT_00539194 + iVar1) = 0;
  return;
}


