#include "tarzan_ghidra_types.hpp"

// Address: 0x00452C90
// Label: CMenu::RenderActiveMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::RenderActiveMenu(void)

{
  PrepareWorldAndMenuRenderState();
  if (g_CurrentMenu != 0) {
    SetFadeBrightnessAndTint((int)FadeBrightness,0);
    if (*(code **)(g_CurrentMenu + 0xc) != (code *)0x0) {
      (**(code **)(g_CurrentMenu + 0xc))(g_CurrentMenu);
    }
  }
  return;
}

