#include "tarzan_ghidra_types.hpp"

// Address: 0x004390A0
// Label: CMenu::LoadGame_Render
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::LoadGame_Render(void)

{
  undefined4 scratchBuffer2;
  undefined4 scratchBuffer;
  
  scratchBuffer2 = 0;
  scratchBuffer = 0;
  RenderMenuUiBlockEntry
            (0x4ed37c,&scratchBuffer2,(_g_LoadGameMenuEntryFlag != 0) + '\b',
             *(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
  RenderMenuUiBlockEntry(0x4ed37c,&scratchBuffer2,0x1b,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
  RenderMenuUiBlockEntry(0x4ed35c,&scratchBuffer2,0,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
  UpdateJaneMenuIdleScript();
  RenderSceneHierarchy(&g_JaneMenuScene);
  ReleasePalettedTextureBlockIfUnused(0x4ed37c,2);
  ReleasePalettedTextureBlockIfUnused(0x4ed35c,2);
  if (-1 < g_SelectedLevelIndex) {
    ReleasePalettedTextureBlockIfUnused(&g_LevelCompleteTextAnchor,2);
  }
  RenderLoadGameSelectedLevelPreview();
  return;
}

