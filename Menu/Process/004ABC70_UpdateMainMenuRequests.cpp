#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABC70
// Label: UpdateMainMenuRequests
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 UpdateMainMenuRequests(void)

{
  int menuIndex;
  
  menuIndex = IsMainMenuActive();
  if (menuIndex != 0) {
    ApplyTarzanCfgProgressToRuntime();
  }
  if (g_PendingMainMenuRuntimeRequest != 0) {
    if (g_PendingMainMenuRuntimeRequest == 1) {
      _g_MainMenuRuntimeRequestState = 1;
    }
    else if (g_PendingMainMenuRuntimeRequest == 2) {
      _g_MainMenuRuntimeRequestState = 3;
      g_PendingMainMenuRuntimeRequest = 0;
      return 0;
    }
    g_PendingMainMenuRuntimeRequest = 0;
  }
  return 0;
}

