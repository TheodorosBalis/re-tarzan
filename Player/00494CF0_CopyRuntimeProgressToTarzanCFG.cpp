#include "tarzan_ghidra_types.hpp"

// Address: 0x00494CF0
// Label: CopyRuntimeProgressToTarzanCFG
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CopyRuntimeProgressToTarzanCFG(void)

{
  int value;
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  
  if ((g_TarzanCfgLoaded != 0) && (g_TarzanCfgProgressDirty != 0)) {
    _g_GameDifficulty = (int)*( undefined1 *)((int)&g_LevelTransitionContext + 1);
    dataCursor = &g_RuntimeCompletionFlagsByLevel;
    dataCursor2 = &g_CfgCompletionFlagsByLevel;
    for (value = 6; value != 0; value = value + -1) {
      *dataCursor2 = *dataCursor;
      dataCursor = dataCursor + 1;
      dataCursor2 = dataCursor2 + 1;
    }
  }
  return;
}

