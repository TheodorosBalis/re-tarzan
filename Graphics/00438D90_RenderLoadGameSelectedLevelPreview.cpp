#include "tarzan_ghidra_types.hpp"

// Address: 0x00438D90
// Label: RenderLoadGameSelectedLevelPreview
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RenderLoadGameSelectedLevelPreview(void)

{
  int value;
  int value2;
  
  if ((-1 < _g_LoadGameSelectionState) && (_g_LoadGameSelectionState < 3)) {
    value = _CurrentSelectedLevel * 0xc;
    value2 = IsCfgLevelUnlockedForDifficulty
                      (*(undefined4 *)(&g_LevelBitIndexTable + _CurrentSelectedLevel * 0xc),
                       (int)*( undefined1 *)((int)&g_LevelTransitionContext + 1));
    if (value2 != 0) {
      _g_LoadGamePreviewCurrentPoseId = *(undefined2 *)(value + 0x4ecaf0);
      RenderSceneHierarchy(&g_LoadGamePreviewState);
      return;
    }
    _g_LoadGamePreviewCurrentPoseId = *(undefined2 *)(value + 0x4ecaec);
    RenderSceneHierarchy(&g_LoadGamePreviewState);
  }
  return;
}

