#include "tarzan_ghidra_types.hpp"

// Address: 0x0045EC80
// Label: CMenu::LevelComplete
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::LevelComplete(void)

{
  uint value;
  int menuIndex;
  int menuIndex2;
  int menuIndex3;
  bool flagByte;
  undefined4 value2;
  
  CMenu::LevelComplete_SetEntitySceneObjectTripletBatch(&g_LevelCompleteScoreEntitySceneObjects,1,0x13e8);
  CMenu::LevelComplete_SetEntitySceneObjectTripletBatch(&g_LevelCompleteCounterEntitySceneObjects,4,0x380)
  ;
  _g_LevelCompleteMenuScene_Field004A = (undefined2)((FrameCount * 0xf & 0x7ffU) << 1);
  g_LevelCompleteDigitBaseSprite =
       *(undefined2 *)
        (&g_LevelCompleteDigitSpriteByRewardSetTable + ((int)g_HudHeroRewardSetIndex % 3) * 4);
  CMenu::LevelComplete_SetThreeDigitCounterSprites
            (0x538730,g_LevelCompleteHundredsSfxCounter,0x2000);
  CMenu::LevelComplete_SetThreeDigitCounterSprites
            (0x538d84,g_TotalTokensCollected - g_LevelCompleteDisplayedScore,0x2000);
  CMenu::LevelComplete_SetEntitySceneObjectTripletBatch(0x538afc,1,0x35c);
  CMenu::LevelComplete_SetEntitySceneObjectTripletBatch(0x538c40,4,0x380);
  _g_LevelCompleteMenuScene_Field069E = (undefined2)((FrameCount * 0x19 & 0x7ffU) << 1);
  if (((ram0x00534026 & 0x8000) == 0) || (FadeBrightness == 0)) {
    if ((g_InputCurrentMask & 0x5000) != 0) {
      g_LevelCompleteFastForwardRequested = g_LevelCompleteFastForwardRequested + 1;
    }
    if (g_LevelCompleteInputMode == 0) {
      menuIndex3 = 0;
      do {
        CMenu::LevelComplete_UpdateTARZANSlots(menuIndex3);
        menuIndex3 = menuIndex3 + 1;
      } while (menuIndex3 < 6);
      CMenu::LevelComplete_SetEntitySceneObjectTripletBatch
                (&g_LevelCompleteRewardBurstScenes,4,0x800);
      _g_LevelCompleteMenuScene_Field180C =
           ((int)(short)(&g_SinCosTable12Bit)[(TotalGameLoopTicks - 8U & 0x1f) * 0x80] >> 2) + 6000;
      _g_LevelCompleteMenuScene_Field1440 =
           _g_LevelCompleteRewardBurstYOffsetScaleA * 0x100 + _g_LevelCompleteMenuScene_Field180C;
      _g_LevelCompleteMenuScene_Field1584 =
           _g_LevelCompleteRewardBurstYOffsetScaleB * 0x100 + _g_LevelCompleteMenuScene_Field180C;
      _g_LevelCompleteMenuScene_Field16C8 =
           _g_LevelCompleteRewardBurstYOffsetScaleC * 0x100 + _g_LevelCompleteMenuScene_Field180C;
      _g_LevelCompleteMenuScene_Field180C =
           _g_LevelCompleteRewardBurstYOffsetScaleD * 0x100 + _g_LevelCompleteMenuScene_Field180C;
    }
    switch(_g_LevelCompleteState) {
    case 0:
      menuIndex3 = g_LevelCompleteDisplayedScore / 100;
      menuIndex2 = g_LevelCompleteDisplayedScore / 10;
      if (g_LevelCompleteFastForwardRequested == 0) {
        g_LevelCompleteDisplayedScore = g_LevelCompleteDisplayedScore + 2;
      }
      else {
        g_LevelCompleteDisplayedScore = g_LevelCompleteDisplayedScore + 0x32;
      }
      menuIndex = (g_TotalTokensCollected / 100) * 100;
      if (menuIndex < g_LevelCompleteDisplayedScore) {
        g_LevelCompleteDisplayedScore = menuIndex;
      }
      if (menuIndex3 < g_LevelCompleteDisplayedScore / 100) {
        PlayAudioById(0xbe,(int *)0,(undefined4 *)0);
        g_LevelCompleteHundredsSfxCounter = g_LevelCompleteHundredsSfxCounter + 1;
        CMenu::LevelComplete_InitRewardBurstSystem(&g_LevelCompleteRewardBurstSystem,&DAT_00538784);
      }
      if (menuIndex2 < g_LevelCompleteDisplayedScore / 10) {
        PlayAudioById(0xb5,(int *)0,(undefined4 *)0);
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
        if ((g_CollectedTARZANLetterMask6 & 0x3f) != 0x3f) {
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
         (menuIndex3 = 6 - g_LevelCompleteStateTimer / 5,
         CMenu::LevelComplete_InitRewardBurstSystem
                   (&g_LevelCompleteRewardBurstSystem,&DAT_005391a4 + menuIndex3 * 0x144), menuIndex3 == 0)) {
        PlayAudioById(*(undefined4 *)
                       (&g_LevelCompleteWorldRewardSfxTable + ((int)g_HudHeroRewardSetIndex % 3) * 4
                       ),0,0);
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
      menuIndex2 = g_LevelCompleteStateTimer + -1;
      menuIndex3 = menuIndex2 / 0x14;
      flagByte = (g_LevelCompleteStateTimer / 0x14) * 0x14 == g_LevelCompleteStateTimer;
      g_LevelCompleteStateTimer = menuIndex2;
      if (flagByte) {
        if (((byte)(1 << ((byte)menuIndex3 & 0x1f)) & g_CollectedSketchPieceMask4) == 0) {
          value2 = 0x3e0;
        }
        else {
          value2 = *(undefined4 *)(&g_LevelCompleteSlotRewardSfxTable + menuIndex3 * 4);
        }
        PlayAudioById(value2,(int *)0,(undefined4 *)0);
      }
      CMenu::LevelComplete_SetRewardBurstSlotState(menuIndex3);
      if (g_LevelCompleteFastForwardRequested == 0) {
        if (g_LevelCompleteStateTimer != 0) {
          return;
        }
      }
      else {
        CMenu::LevelComplete_SetRewardBurstSlotState(0);
        CMenu::LevelComplete_SetRewardBurstSlotState(1);
        CMenu::LevelComplete_SetRewardBurstSlotState(2);
        CMenu::LevelComplete_SetRewardBurstSlotState(3);
        g_LevelCompleteStateTimer = 0;
      }
      if ((g_CollectedSketchPieceMask4 & 0xf) != 0xf) {
        PlayAudioById(0x3e5,(int *)0,(undefined4 *)0);
        _g_LevelCompleteState = 4;
        return;
      }
      PlayAudioById(0xbf,(int *)0,(undefined4 *)0);
      CMenu::LevelComplete_InitRewardBurstSystem(&g_LevelCompleteRewardBurstSystem,&DAT_0053993c);
      _g_LevelCompleteState = 4;
      return;
    case 4:
      if (g_LevelCompleteInputMode == 0) {
        value = g_InputEdgeMask & g_InputCurrentMask & 0x5000;
      }
      else {
        value = g_InputEdgeMask & g_InputCurrentMask & 0x4000;
      }
      if (value != 0) {
        PlayAudioById(0xac,(int *)0,(undefined4 *)0);
        CMenu::LevelComplete_BeginExitTransition(0);
        _g_LevelCompleteState = 5;
      }
    }
  }
  return;
}

