#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC080
// Label: SelectLevelAndStartWorldTransition
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SelectLevelAndStartWorldTransition(int arg1,int arg2)

{
  int value;
  undefined4 *dataCursor;
  int value2;
  
  if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\x16') {
    value2 = 0;
    if (g_LevelTransitionEntries != -1) {
      dataCursor = &g_LevelTransitionEntries;
      value = g_LevelTransitionEntries;
      do {
        if ((value == arg1) && (dataCursor[1] == arg2)) break;
        value = dataCursor[0xf];
        dataCursor = dataCursor + 0xf;
        value2 = value2 + 1;
      } while (value != -1);
    }
    if ((&g_LevelTransitionEntries)[value2 * 0xf] != -1) {
      g_SelectedLevelIndex = (undefined1)value2;
      *( undefined1 *)((int)&g_LevelTransitionContext + 3) =
           (&g_LevelTransitionTypeBySlot)[*( undefined1 *)((int)&g_LevelTransitionContext + 1) * 2];
      *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = 0;
      gCurrentTokensCollected = 0;
      ResetBackgroundMusicPlaybackStateThunk(&DAT_00c46070);
      InitiateFade(2,0x100);
      MenuState = 2;
    }
  }
  return;
}

