#include "tarzan_ghidra_types.hpp"

// Address: 0x004949C0
// Label: EnsureTarzanCFGLoaded
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 EnsureTarzanCFGLoaded(void)

{
  if (g_TarzanCfgInitialized == 0) {
    g_TarzanCfgLoaded = 0;
    g_TarzanCfgProgressDirty = 0;
    SetCurrentDirectoryToExePath();
    LoadAndVerifyTarzanCFG();
    g_TarzanCfgLoadCounter = g_TarzanCfgLoadCounter + 1;
    if (g_TarzanCfgUncleanShutdownFlag != 0) {
      bLastTimeCrashed = 1;
      g_TarzanCfgInitialized = 1;
      return 1;
    }
    g_TarzanCfgUncleanShutdownFlag = 1;
    SaveTarzanCFGFile();
    g_TarzanCfgInitialized = 1;
  }
  return 1;
}

