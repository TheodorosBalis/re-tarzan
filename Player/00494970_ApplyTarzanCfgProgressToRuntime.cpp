#include "tarzan_ghidra_types.hpp"

// Address: 0x00494970
// Label: ApplyTarzanCfgProgressToRuntime
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ApplyTarzanCfgProgressToRuntime(void)

{
  int value;
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  
  if (g_TarzanCfgLoaded != 0) {
    g_TarzanCfgProgressDirty = 1;
    if (g_PendingCfgProgressRestore != 0) {
      g_PendingCfgProgressRestore = 0;
      dataCursor = &g_CfgCompletionFlagsByLevel;
      dataCursor2 = &g_RuntimeCompletionFlagsByLevel;
      for (value = 6; value != 0; value = value + -1) {
        *dataCursor2 = *dataCursor;
        dataCursor = dataCursor + 1;
        dataCursor2 = dataCursor2 + 1;
      }
    }
    *( undefined1 *)((int)&g_LevelTransitionContext + 1) = g_GameDifficulty;
  }
  return;
}

