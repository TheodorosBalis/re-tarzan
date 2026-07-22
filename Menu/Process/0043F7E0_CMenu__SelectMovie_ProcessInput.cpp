#include "tarzan_ghidra_types.hpp"

// Address: 0x0043F7E0
// Label: CMenu::SelectMovie_ProcessInput
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::SelectMovie_ProcessInput(void)

{
  if ((g_InputCurrentMask & g_InputEdgeMask & 0x1000) != 0) {
    PlayAudioById(0xaa,(int *)0,(undefined4 *)0);
    _g_SelectMovieState = 2;
    InitiateFade(2,0x80);
  }
  if ((g_InputCurrentMask & g_InputEdgeMask & 0x80) != 0) {
    PlayAudioById(0xab,(int *)0,(undefined4 *)0);
    if ((int)_g_SelectedMovieIndex < 1) {
      _g_SelectedMovieIndex = 0x12;
    }
    else {
      _g_SelectedMovieIndex = _g_SelectedMovieIndex - 1;
    }
  }
  if ((g_InputCurrentMask & g_InputEdgeMask & 0x20) != 0) {
    PlayAudioById(0xab,(int *)0,(undefined4 *)0);
    if (_g_SelectedMovieIndex < 0x12) {
      _g_SelectedMovieIndex = _g_SelectedMovieIndex + 1;
    }
    else {
      _g_SelectedMovieIndex = 0;
    }
  }
  if ((g_InputCurrentMask & g_InputEdgeMask & 0x4000) != 0) {
    if (((*(int *)(&g_SelectMovieEntryRequiredFlagIndex + _g_SelectedMovieIndex * 0x1c) != -1) &&
        ((g_GameplayRuntimeFlags & 0x10000) == 0)) &&
       (((&g_SelectMovieEntryRequiredFlagMask)[_g_SelectedMovieIndex * 0x1c] &
        *(byte *)((int)&g_RuntimeCompletionFlagsByLevel +
                 *(int *)(&g_SelectMovieEntryRequiredFlagIndex + _g_SelectedMovieIndex * 0x1c))) ==
        0)) {
      PlayAudioById(0xaa,(int *)0,(undefined4 *)0);
      return;
    }
    PlayAudioById(0xac,(int *)0,(undefined4 *)0);
    _g_SelectMovieState = 1;
    InitiateFade(2,0x100);
    ResetBackgroundMusicPlaybackStateThunk(&DAT_00c46070);
  }
  return;
}

