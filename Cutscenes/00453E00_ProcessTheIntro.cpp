#include "tarzan_ghidra_types.hpp"

// Address: 0x00453E00
// Label: ProcessTheIntro
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ProcessTheIntro(void)

{
  int value;
  undefined4 *dataCursor;
  
  InitializeIntroRenderAndMenuState();
  ResetIntroMenuSelectionState();
  InitModelLoadHeap(&g_ModelLoadHeapState,&DAT_00a43a24,0x200000);
  ResetModelLoadQueue();
  LoadFonts(&PTR_DAT_00502d48,&DAT_00c46020);
  ResetInputMasksAndCaptureKeyboardState();
  ResetIntroGameplayState();
  dataCursor = &g_RuntimeCompletionFlagsByLevel;
  for (value = 6; value != 0; value = value + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  ProcessMovieClipOrLogo(0x8000,0x3c,0,0xffff);
  ProcessMovieClipOrLogo(0x8001,0x3c,0,0xffff);
  ProcessMovieClipOrLogo(0x8010,0x3c,0,0xffff);
  SetActiveMenuContext(&g_MenuSceneContext);
  ProcessLevelLogo(&DAT_004e57c8);
  TransitionToWorldOrMenu(0);
  return;
}

