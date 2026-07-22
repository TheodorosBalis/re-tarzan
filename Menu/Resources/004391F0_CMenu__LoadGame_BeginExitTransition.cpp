#include "tarzan_ghidra_types.hpp"

// Address: 0x004391F0
// Label: CMenu::LoadGame_BeginExitTransition
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::LoadGame_BeginExitTransition(void)

{
  int menuIndex;
  
  PlayAudioById(0xaa,(int *)0,(undefined4 *)0);
  _g_LoadGameExitPending = 1;
  _g_LoadGameTimer = 0x5a;
  _g_LoadGameState = 0;
  menuIndex = RandomModulo(4,0,0);
  PlayAudioById(*(undefined4 *)(&g_LoadGameExitSfxTable + menuIndex * 4));
  return;
}

