// Address: 0x0045E800

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu__LevelComplete_Enter(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  int *piVar5;
  
  if (((byte)DAT_00534010 & 1) != 0) {
    g_LevelTransitionRewardMask6 = 0x3f;
  }
  LoadMenuGraphicBlock(&g_LevelCompleteGraphicBlock);
  ShowLoadGameHeaderGraphics();
  _g_LoadGameMenuEntryFlag = 1;
  ptrToDecideWhichMenu = 0;
  ptrToDecideWhichMenu2 = &g_MenuDescriptor_LevelComplete;
  InitSceneAnchorTransform
            (&g_TransitionSceneAnchorPrimary,*(undefined4 *)(g_ActiveMenuContext + 0x1c));
  DAT_0051c4dc = 900;
  piVar5 = (int *)&g_LevelCompleteSlotLayoutTableA;
  if (g_LevelCompleteInputMode != 0) {
    piVar5 = &g_LevelCompleteSlotLayoutTableB;
  }
  puVar4 = &g_LevelCompleteRewardSceneEntries;
  iVar3 = 0x14;
  do {
    InitLoadGamePreviewTransform(puVar4 + -0x15);
    uVar1 = piVar5[4];
    *(short *)((int)puVar4 + -0x46) = (short)piVar5[5];
    if ((uVar1 & 0x7000) == 0x3000) {
      *puVar4 = *puVar4 & 0xff;
      puVar4[1] = puVar4[1] & 0xff;
      iVar2 = *piVar5;
      puVar4[2] = puVar4[2] & 0xff;
      puVar4[-0x10] = puVar4[-0x10] & 0xff | iVar2 << 8;
      puVar4[-0xf] = piVar5[1] << 8 | puVar4[-0xf] & 0xff;
      puVar4[-0xe] = piVar5[2];
    }
    else {
      iVar2 = piVar5[1];
      uVar1 = piVar5[2];
      *puVar4 = *piVar5 << 8 | *puVar4 & 0xff;
      puVar4[-0x10] = 0;
      puVar4[1] = iVar2 << 8 | puVar4[1] & 0xff;
      puVar4[2] = puVar4[2] & 0xff;
      puVar4[-0xf] = 0;
      puVar4[-0xe] = uVar1;
    }
    uVar1 = piVar5[3];
    *(short *)(puVar4 + -0x12) = (short)piVar5[4];
    puVar4[0x2b] = (uint)&g_TransitionSceneAnchorPrimary;
    puVar4[-0x11] = uVar1;
    *(undefined2 *)((int)puVar4 + 0x52) = 0;
    puVar4[0x18] = 1;
    puVar4 = puVar4 + 0x51;
    piVar5 = piVar5 + 6;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 0;
  do {
    CMenu__LevelComplete_InitRewardSlot(iVar3);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 6);
  DAT_00533ff0 = DAT_00533ff0 == '\0' && (g_LevelTransitionRewardMask4 & 0xf) == 0xf;
  CMenu__LevelComplete_SetSceneEntryTripletBatch(&g_LevelCompleteRewardBurstScenes,4,0x800);
  _g_LevelCompleteState = (uint)(g_LevelCompleteInputMode == 0);
  _g_LevelCompleteStartingLevelIndex = (int)g_LevelTransitionContext._3_1_;
  g_TotalTokensCollected = (uint)gCurrentTokensCollected;
  g_LevelCompleteStateTimer = 0x20;
  g_LevelCompleteDisplayedScore = 0;
  g_LevelCompleteRewardSlotDoneMask = 0;
  g_LevelCompleteFastForwardRequested = 0;
  _g_LevelCompleteRewardBurstSystem = 0;
  g_LevelCompleteHundredsSfxCounter = _g_LevelCompleteStartingLevelIndex;
  CMenu__LevelComplete_CommitProgressAndAdvanceLevel();
  return;
}


