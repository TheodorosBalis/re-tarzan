#include "tarzan_ghidra_types.hpp"

// Address: 0x00452AC0
// Label: EnterGameMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EnterGameMenu(void)

{
  InitSceneAnchorTransform(&g_CameraFocusX,*(undefined4 *)(g_ActiveMenuContext + 0x1c));
  if ((g_GameplayRuntimeFlags & 0x80000000) != 0) {
    CMenu::EnterGameMenuRequest();
  }
  BuildLoadGameHeaderGraphics();
  BuildMainMenuSelections();
  BuildOptionsGraphicsBlocks();
  _g_LoadGameMenuEntryFlag = 0;
  _g_LoadGameMenuProfileValue =
       *(undefined4 *)(&g_LoadGameMenuProfileTable + g_LoadGameProfileIndex * 4);
  InitPorterMenuScene();
  g_MainMenuSelectionEntryTablePtr = (undefined *)&PTR_MainMenu_Selections_004f1f98;
  g_CurrentMenu = &g_MainMenuMainFontMenuEntry;
  g_NextMenu = &g_MainMenuMainFontMenuEntry;
  CEntities::ResetHudTextRendererState();
  InitiateFade(1,0x100);
  return;
}

