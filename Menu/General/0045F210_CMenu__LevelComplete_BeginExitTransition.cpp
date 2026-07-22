#include "tarzan_ghidra_types.hpp"

// Address: 0x0045F210
// Label: CMenu::LevelComplete_BeginExitTransition
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::LevelComplete_BeginExitTransition(void)

{
  ResetBackgroundMusicPlaybackStateThunk(&DAT_00c46070);
  InitiateFade(2,0x100);
  MenuState = 2;
  return;
}

