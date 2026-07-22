#include "tarzan_ghidra_types.hpp"

// Address: 0x00438F30
// Label: EnterLoadGameMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EnterLoadGameMenu(void)

{
  InitLoadGamePreviewScene();
  _g_LoadGameState = 0;
  _g_LoadGameExitPending = 0;
  return;
}

