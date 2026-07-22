#include "tarzan_ghidra_types.hpp"

// Address: 0x00445FF0
// Label: CMenu::OpenOptionsFromIntroMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::OpenOptionsFromIntroMenu(undefined1 menu)

{
  g_IntroMenuStartFlag = menu;
  CMenu::Options(&PTR_Options_OptionsSelections_004f0210);
  PlayAudioById(0xac,(int *)0,(undefined4 *)0);
  return;
}

