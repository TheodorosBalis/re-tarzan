// Address: 0x00438D90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RenderLoadGameSelectedLevelPreview(void)

{
  int iVar1;
  int iVar2;
  
  if ((-1 < _g_LoadGameSelectionState) && (_g_LoadGameSelectionState < 3)) {
    iVar1 = _CurrentSelectedLevel * 0xc;
    iVar2 = TestBitInWordArray(*(undefined4 *)(&g_LevelBitIndexTable + _CurrentSelectedLevel * 0xc),
                               (int)g_LevelTransitionContext._1_1_);
    if (iVar2 != 0) {
      _DAT_0051d124 = *(undefined2 *)(iVar1 + 0x4ecaf0);
      RenderMenuSceneHierarchy(&g_LoadGamePreviewState);
      return;
    }
    _DAT_0051d124 = *(undefined2 *)(iVar1 + 0x4ecaec);
    RenderMenuSceneHierarchy(&g_LoadGamePreviewState);
  }
  return;
}


