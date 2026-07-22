#include "tarzan_ghidra_types.hpp"

// Address: 0x004460B0
// Label: CMenu::Options_Render
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::Options_Render(undefined4 menu)

{
  RenderMenuFontBlockAndChildText(menu);
  CMenu::Options_UpdateIdleBehavior(menu);
  CMenu::SelectMovie_NoOp();
  RenderSceneHierarchy(&g_PorterMenuScene);
  return;
}

