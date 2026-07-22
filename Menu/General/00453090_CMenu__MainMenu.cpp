#include "tarzan_ghidra_types.hpp"

// Address: 0x00453090
// Label: CMenu::MainMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::MainMenu(undefined4 menu)

{
  if (1000 < TimeIDLEinMenu) {
    TimeIDLEinMenu = 0;
    if (_IDLECutsceneHasPlayed == 0) {
      _IDLECutsceneHasPlayed = 1;
      ResetBackgroundMusicPlaybackStateThunk(&DAT_00c46070);
      InitiateFade(2,0x100);
      MenuState = 3;
      CMenu::RunSubMenuInputHandler(menu);
      return;
    }
    _IDLECutsceneHasPlayed = 0;
    _ClipPlaybackID = _ClipPlaybackID + 1;
    if (2 < _ClipPlaybackID) {
      _ClipPlaybackID = 0;
    }
    g_SelectedLevelIndex =
         FindLevelTransitionEntryIndex
                   (*(undefined4 *)(&g_GameplayClipLevelIdTable + _ClipPlaybackID * 0xc),0);
    g_CurrentCheckpointId =
         *(undefined4 *)(&g_GameplayClipCheckpointIdTable + _ClipPlaybackID * 0xc);
    g_PendingTransitionPayload =
         *(undefined4 *)(&g_GameplayClipTransitionPayloadTable + _ClipPlaybackID * 0xc);
    ResetBackgroundMusicPlaybackStateThunk(&DAT_00c46070);
    InitiateFade(2,0x100);
    MenuState = 2;
  }
  CMenu::RunSubMenuInputHandler(menu);
  return;
}

