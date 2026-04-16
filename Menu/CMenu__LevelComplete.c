// Address: 0x0045EC80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu__LevelComplete(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined4 uVar6;
  
  CMenu__LevelComplete_SetSceneEntryTripletBatch(&g_LevelCompleteScoreSceneEntries,1,0x13e8);
  CMenu__LevelComplete_SetSceneEntryTripletBatch(&g_LevelCompleteCounterSceneEntries,4,0x380);
  _DAT_0053854a = (undefined2)((FrameCount * 0xf & 0x7ffU) << 1);
  g_LevelCompleteDigitBaseSprite = *(undefined2 *)(((int)DAT_00533fec % 3) * 4 + 0x505868);
  CMenu__LevelComplete_SetThreeDigitCounterSprites
            (0x538730,g_LevelCompleteHundredsSfxCounter,0x2000);
  CMenu__LevelComplete_SetThreeDigitCounterSprites
            (0x538d84,g_TotalTokensCollected - g_LevelCompleteDisplayedScore,0x2000);
  CMenu__LevelComplete_SetSceneEntryTripletBatch(0x538afc,1,0x35c);
  CMenu__LevelComplete_SetSceneEntryTripletBatch(0x538c40,4,0x380);
  _DAT_00538b9e = (undefined2)((FrameCount * 0x19 & 0x7ffU) << 1);
  if (((ram0x00534026 & 0x8000) == 0) || (FadeBrightness == 0)) {
    if ((MenuKeyPressed & 0x5000) != 0) {
      g_LevelCompleteFastForwardRequested = g_LevelCompleteFastForwardRequested + 1;
    }
    if (g_LevelCompleteInputMode == 0) {
      iVar4 = 0;
      do {
        CMenu__LevelComplete_UpdateTARZANSlots(iVar4);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 6);
      CMenu__LevelComplete_SetSceneEntryTripletBatch(&g_LevelCompleteRewardBurstScenes,4,0x800);
      _DAT_00539d0c =
           ((int)(short)(&DAT_0077c788)[(TotalGameLoopTicks - 8U & 0x1f) * 0x80] >> 2) + 6000;
      _DAT_00539940 = _DAT_0050562c * 0x100 + _DAT_00539d0c;
      _DAT_00539a84 = _DAT_00505644 * 0x100 + _DAT_00539d0c;
      _DAT_00539bc8 = _DAT_0050565c * 0x100 + _DAT_00539d0c;
      _DAT_00539d0c = _DAT_00505674 * 0x100 + _DAT_00539d0c;
    }
    switch(_g_LevelCompleteState) {
    case 0:
      iVar4 = g_LevelCompleteDisplayedScore / 100;
      iVar3 = g_LevelCompleteDisplayedScore / 10;
      if (g_LevelCompleteFastForwardRequested == 0) {
        g_LevelCompleteDisplayedScore = g_LevelCompleteDisplayedScore + 2;
      }
      else {
        g_LevelCompleteDisplayedScore = g_LevelCompleteDisplayedScore + 0x32;
      }
      iVar2 = (g_TotalTokensCollected / 100) * 100;
      if (iVar2 < g_LevelCompleteDisplayedScore) {
        g_LevelCompleteDisplayedScore = iVar2;
      }
      if (iVar4 < g_LevelCompleteDisplayedScore / 100) {
        PlayAudioById(0xbe,0,0);
        g_LevelCompleteHundredsSfxCounter = g_LevelCompleteHundredsSfxCounter + 1;
        CMenu__LevelComplete_InitRewardBurstSystem(&g_LevelCompleteRewardBurstSystem,&DAT_00538784);
      }
      if (iVar3 < g_LevelCompleteDisplayedScore / 10) {
        PlayAudioById(0xb5,0,0);
      }
      if (g_LevelCompleteDisplayedScore == (g_TotalTokensCollected / 100) * 100) {
        if (g_LevelCompleteInputMode == 0) {
          g_LevelCompleteStateTimer = 0x50;
          _g_LevelCompleteState = 3;
          return;
        }
        _g_LevelCompleteState = 4;
        return;
      }
      break;
    case 1:
      if (g_LevelCompleteRewardSlotDoneMask == 0x3f) {
        if ((g_LevelTransitionRewardMask6 & 0x3f) != 0x3f) {
          _g_LevelCompleteState = 0;
          return;
        }
        g_LevelCompleteStateTimer = 0x1e;
        _g_LevelCompleteState = 2;
        return;
      }
      break;
    case 2:
      if (((g_LevelCompleteStateTimer / 5) * 5 == g_LevelCompleteStateTimer) &&
         (iVar4 = 6 - g_LevelCompleteStateTimer / 5,
         CMenu__LevelComplete_InitRewardBurstSystem
                   (&g_LevelCompleteRewardBurstSystem,&DAT_005391a4 + iVar4 * 0x144), iVar4 == 0)) {
        PlayAudioById
                  (*(undefined4 *)
                    (&g_LevelCompleteWorldRewardSfxTable + ((int)DAT_00533fec % 3) * 4),0,0);
      }
      if (g_LevelCompleteFastForwardRequested != 0) {
        g_LevelCompleteStateTimer = 0;
        _g_LevelCompleteState = 0;
        return;
      }
      g_LevelCompleteStateTimer = g_LevelCompleteStateTimer + -1;
      if (g_LevelCompleteStateTimer == 0) {
        _g_LevelCompleteState = 0;
        return;
      }
      break;
    case 3:
      iVar3 = g_LevelCompleteStateTimer + -1;
      iVar4 = iVar3 / 0x14;
      bVar5 = (g_LevelCompleteStateTimer / 0x14) * 0x14 == g_LevelCompleteStateTimer;
      g_LevelCompleteStateTimer = iVar3;
      if (bVar5) {
        if (((byte)(1 << ((byte)iVar4 & 0x1f)) & g_LevelTransitionRewardMask4) == 0) {
          uVar6 = 0x3e0;
        }
        else {
          uVar6 = *(undefined4 *)(&g_LevelCompleteSlotRewardSfxTable + iVar4 * 4);
        }
        PlayAudioById(uVar6,0,0);
      }
      CMenu__LevelComplete_SetRewardBurstSlotState(iVar4);
      if (g_LevelCompleteFastForwardRequested == 0) {
        if (g_LevelCompleteStateTimer != 0) {
          return;
        }
      }
      else {
        CMenu__LevelComplete_SetRewardBurstSlotState(0);
        CMenu__LevelComplete_SetRewardBurstSlotState(1);
        CMenu__LevelComplete_SetRewardBurstSlotState(2);
        CMenu__LevelComplete_SetRewardBurstSlotState(3);
        g_LevelCompleteStateTimer = 0;
      }
      if ((g_LevelTransitionRewardMask4 & 0xf) != 0xf) {
        PlayAudioById(0x3e5,0,0);
        _g_LevelCompleteState = 4;
        return;
      }
      PlayAudioById(0xbf,0,0);
      CMenu__LevelComplete_InitRewardBurstSystem(&g_LevelCompleteRewardBurstSystem,&DAT_0053993c);
      _g_LevelCompleteState = 4;
      return;
    case 4:
      if (g_LevelCompleteInputMode == 0) {
        uVar1 = MenuKeyJustReleased & MenuKeyPressed & 0x5000;
      }
      else {
        uVar1 = MenuKeyJustReleased & MenuKeyPressed & 0x4000;
      }
      if (uVar1 != 0) {
        PlayAudioById(0xac,0,0);
        CMenu__LevelComplete_BeginExitTransition(0);
        _g_LevelCompleteState = 5;
      }
    }
  }
  return;
}


