#include "tarzan_ghidra_types.hpp"

// Address: 0x00494CB0
// Label: ShutdownTarzanCFGAndSave
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ShutdownTarzanCFGAndSave(void)

{
  if (g_TarzanCfgInitialized != 0) {
    CopyRuntimeProgressToTarzanCFG();
    if (g_InternalErrorActive == 0) {
      g_TarzanCfgUncleanShutdownFlag = 0;
    }
    SaveTarzanCFGFile();
    g_TarzanCfgInitialized = 0;
  }
  return;
}

