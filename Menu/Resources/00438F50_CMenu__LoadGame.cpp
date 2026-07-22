#include "tarzan_ghidra_types.hpp"

// Address: 0x00438F50
// Label: CMenu::LoadGame
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::LoadGame(void)

{
  CMenu::LoadGame_ProcessInput();
  if (_g_LoadGameExitPending == 0) {
    if (_g_LoadGameState == 5) {
      _g_LoadGameTimer = _g_LoadGameTimer + -1;
      if ((_g_LoadGameTimer < 1) || ((g_InputCurrentMask & g_InputEdgeMask & 0x1000) != 0)) {
        _g_LoadGameState = 0;
      }
    }
    else {
      _g_LoadGameSelectionTemp = 0xffffffff;
      if (_g_LoadGameState == 4) {
        _g_LoadGameTimer = 0x78;
        _g_LoadGameState = 5;
        return;
      }
      _g_LoadGameState = 0;
      if ((g_InputCurrentMask & g_InputEdgeMask & 0x1000) != 0) {
        CMenu::LoadGame_BeginExitTransition(0);
        return;
      }
    }
  }
  else {
    _g_LoadGameTimer = _g_LoadGameTimer + -1;
    if (_g_LoadGameTimer == 0) {
      CMenu::LoadGame_ReleaseResources();
      if ((-1 < g_SelectedLevelIndex) && ((short)g_LevelTransitionRequestFlags == -0x7fff)) {
        CMenu::RequestMenuChangeWithFade(&g_MenuDescriptor_LevelComplete);
        return;
      }
      CMenu::RequestMenuChangeWithFade(&g_MainMenuMainFontMenuEntry);
      return;
    }
  }
  return;
}

