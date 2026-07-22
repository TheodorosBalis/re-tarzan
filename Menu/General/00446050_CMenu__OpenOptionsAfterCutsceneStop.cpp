#include "tarzan_ghidra_types.hpp"

// Address: 0x00446050
// Label: CMenu::OpenOptionsAfterCutsceneStop
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::OpenOptionsAfterCutsceneStop(undefined4 menu)

{
  func_0x004ac400(menu);
  CMenu::Options(&PTR_Options_OptionsSelections_004f0210);
  return;
}

