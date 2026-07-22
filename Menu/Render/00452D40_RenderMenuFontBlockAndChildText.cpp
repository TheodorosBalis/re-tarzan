#include "tarzan_ghidra_types.hpp"

// Address: 0x00452D40
// Label: RenderMenuFontBlockAndChildText
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderMenuFontBlockAndChildText(int *menu)

{
  int menuIndex;
  undefined4 localState;
  undefined4 localState4;
  undefined4 localState3;
  undefined4 localState2;
  
  menuIndex = menu[2];
  if ((menuIndex != 0) && (*(code **)(menuIndex + 0x20) != (code *)0x0)) {
    (**(code **)(menuIndex + 0x20))(menuIndex);
  }
  localState = 0;
  localState4 = 0;
  localState3 = 0;
  localState2 = 0;
  SetFadeBrightnessAndTint((int)FadeBrightness,&localState);
  g_RenderBlendMode = 0;
  if (*(int *)(*menu + 0xc) != 0) {
    if (menu[1] != -1) {
      RenderMenuUiBlockEntry
                (*menu + 4,&DAT_00533bd8,menu[1],*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0
                );
    }
    ReleasePalettedTextureBlockIfUnused(*menu + 4,2);
  }
  return;
}

