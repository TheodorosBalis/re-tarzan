#include "tarzan_ghidra_types.hpp"

// Address: 0x0047EF5E
// Label: Show_Credits
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Show_Credits(void)

{
  undefined4 savedEsi;
  short savedDi;
  
  g_SelectedLevelIndex = -1;
  ProcessMovieClipOrLogo(0x4020,0x1fe);
  ProcessMovieClipOrLogo(0x4022,0x1fc);
  ProcessMovieClipOrLogo(0x4023,0x1f7);
  ProcessMovieClipOrLogo(0x401c,0x1ef);
  ProcessMovieClipOrLogo(0x401d,0x1ea);
  ProcessMovieClipOrLogo(0x401e,500);
  ProcessMovieClipOrLogo(0x4030,0x1ea);
  ProcessMovieClipOrLogo(0x4031,0x1ea);
  ProcessMovieClipOrLogo(0x4024,500);
  ProcessMovieClipOrLogo(0x4025,500);
  ProcessMovieClipOrLogo(0x4029,500);
  ProcessMovieClipOrLogo(0x402a,500);
  ProcessMovieClipOrLogo(0x402f,500);
  ProcessMovieClipOrLogo(0x402d,500);
  ProcessMovieClipOrLogo(0x402e,500);
  ProcessMovieClipOrLogo(0x401f,1000);
  if ((-1 < g_SelectedLevelIndex) && ((short)g_LevelTransitionRequestFlags == savedDi)) {
    g_LevelCompleteInputMode = (int)g_SelectedLevelIndex & 1;
    g_NextMenu = &g_MenuDescriptor_LevelComplete;
    g_CurrentMenu = savedEsi;
    CMenu::LevelComplete_Enter();
    return;
  }
  *( undefined1 *)((int)&g_LevelTransitionContext + 2) = 0x16;
  g_NextMenu = &g_MainMenuMainFontMenuEntry;
  EnterGameMenu();
  return;
}

