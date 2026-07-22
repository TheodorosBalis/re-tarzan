#include "tarzan_ghidra_types.hpp"

// Address: 0x00453180
// Label: CMenu::EnterGameMenuRequest
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::EnterGameMenuRequest(void)

{
  _g_GameMenuRequestState = 2;
  g_GameplayRuntimeFlags = g_GameplayRuntimeFlags | 0x80000000;
  return;
}

