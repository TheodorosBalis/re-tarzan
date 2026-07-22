#include "tarzan_ghidra_types.hpp"

// Address: 0x00438D00
// Label: CMenu::LoadGame_ProcessInput
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::LoadGame_ProcessInput(void)

{
  int menuIndex;
  
  if (_g_LoadGameSelectionState == 0) {
    if (((ram0x00534026 & 0x8000) == 0) || (FadeBrightness == 0)) {
      if (((g_InputCurrentMask & g_InputEdgeMask & 0x80) != 0) && (0 < (int)_CurrentSelectedLevel))
      {
        PlayAudioById(0xab,(int *)0,(undefined4 *)0);
        _CurrentSelectedLevel = _CurrentSelectedLevel - 1;
      }
      if (((g_InputCurrentMask & g_InputEdgeMask & 0x20) != 0) && (_CurrentSelectedLevel < 0xc)) {
        PlayAudioById(0xab,(int *)0,(undefined4 *)0);
        _CurrentSelectedLevel = _CurrentSelectedLevel + 1;
      }
      if ((g_InputCurrentMask & g_InputEdgeMask & 0x4000) != 0) {
        menuIndex = IsCfgLevelUnlockedForDifficulty
                          (*(undefined4 *)(&g_LevelBitIndexTable + _CurrentSelectedLevel * 0xc),
                           (int)*( undefined1 *)((int)&g_LevelTransitionContext + 1));
        if (menuIndex != 0) {
          PlayAudioById(0xac,(int *)0,(undefined4 *)0);
          _g_LoadGameSelectionState = 1;
          InitiateFade(2,0x100);
          ResetBackgroundMusicPlaybackStateThunk(&DAT_00c46070);
          return;
        }
        PlayAudioById(0xaa,(int *)0,(undefined4 *)0);
      }
      return;
    }
  }
  else if (_g_LoadGameSelectionState == 1) {
    if ((FadeBrightness == 0) && (3 < FadeStatus)) {
      _g_LoadGameSelectionState = 0;
      SelectLevelAndStartWorldTransition
                (*(undefined4 *)(&g_LevelBitIndexTable + _CurrentSelectedLevel * 0xc),0);
      return;
    }
  }
  else if (((_g_LoadGameSelectionState == 2) && (FadeBrightness == 0)) && (3 < FadeStatus)) {
    _g_LoadGameSelectionState = 3;
    return;
  }
  return;
}

