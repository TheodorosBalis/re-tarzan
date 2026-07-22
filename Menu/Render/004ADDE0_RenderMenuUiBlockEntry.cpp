#include "tarzan_ghidra_types.hpp"

// Address: 0x004ADDE0
// Label: RenderMenuUiBlockEntry
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderMenuUiBlockEntry
               (int menu,undefined4 menuItem,int selection,undefined4 inputFlags,undefined4 arg5)

{
  undefined4 localState;
  undefined4 localState4;
  undefined4 localState3;
  undefined4 localState2;
  
  if (selection < *(int *)(menu + 0x10)) {
    if (*(int *)(menu + 0x18) == 0) {
      BuildPalettedTextureBlockRuntime(menu);
    }
    *(undefined4 *)(menu + 0x18) = FrameCount;
    localState = 0;
    localState4 = 0;
    localState3 = 0;
    localState2 = 0;
    SetFadeBrightnessAndTint((int)FadeBrightness,&localState);
    g_RenderBlendMode = 0;
    SetDrawWindow(inputFlags,arg5);
    RenderBitmapCellGrid(*(int *)(menu + 0x14) + selection * 0x72,menuItem);
  }
  return;
}

