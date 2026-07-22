#include "tarzan_ghidra_types.hpp"

// Address: 0x004530B1
// Label: TriggerCutsceneWhenIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TriggerCutsceneWhenIdle(undefined4 arg1)

{
  _IDLECutsceneHasPlayed = 1;
  ResetBackgroundMusicPlaybackStateThunk(&DAT_00c46070);
  InitiateFade(2,0x100);
  MenuState = 3;
  CMenu::RunSubMenuInputHandler(arg1);
  return;
}

