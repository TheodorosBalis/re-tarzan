#include "tarzan_ghidra_types.hpp"

// Address: 0x0047ECE0
// Label: LoadGameLevel
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void LoadGameLevel(void)

{
  int value;
  undefined4 *dataCursor;
  
  dataCursor = (undefined4 *)0x0;
  if (-1 < g_SelectedLevelIndex) {
    value = (int)g_SelectedLevelIndex;
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = *(undefined1 *)(&g_LevelTransitionEntries + value * 0xf);
    dataCursor = &g_LevelTransitionEntries + value * 0xf;
    g_CurrentCheckpointId =
         -(uint)((&DAT_004f266c)[value * 0xf] != 0xffffffff) & (&DAT_004f266c)[value * 0xf];
  }
  *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = 0;
  LoadFonts(&PTR_DAT_0050df58,&DAT_00c46024);
  ResetInputMasksAndCaptureKeyboardState();
  SetActiveMenuContext(&g_MenuSceneContext);
  if (dataCursor != (undefined4 *)0x0) {
    if (g_PendingTransitionPayload == 0) {
      ProcessMovieClipOrLogo(dataCursor[3],10000,0,0x1000);
    }
    if (dataCursor[2] != -1) {
      SetActiveMenuContext(&g_MenuSceneContext);
      ProcessLevelLogo((&g_LevelLogoPointerTable)[dataCursor[2] & 0xffff3fff]);
    }
  }
  TransitionToWorldOrMenu(1);
  return;
}

