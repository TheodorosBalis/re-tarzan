#include "tarzan_ghidra_types.hpp"

// Address: 0x004530EA
// Label: TriggerGameplayClip
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall TriggerGameplayClip(undefined4 arg1,undefined4 arg2)

{
  _ClipPlaybackID = _ClipPlaybackID + 1;
  if (2 < _ClipPlaybackID) {
    _ClipPlaybackID = 0;
  }
  _IDLECutsceneHasPlayed = arg1;
  g_SelectedLevelIndex =
       FindLevelTransitionEntryIndex
                 (*(undefined4 *)(&g_GameplayClipLevelIdTable + _ClipPlaybackID * 0xc),arg1);
  g_CurrentCheckpointId = *(undefined4 *)(&g_GameplayClipCheckpointIdTable + _ClipPlaybackID * 0xc);
  g_PendingTransitionPayload =
       *(undefined4 *)(&g_GameplayClipTransitionPayloadTable + _ClipPlaybackID * 0xc);
  ResetBackgroundMusicPlaybackStateThunk(&DAT_00c46070);
  InitiateFade(2,0x100);
  MenuState = 2;
  CMenu::RunSubMenuInputHandler(arg2);
  return;
}

