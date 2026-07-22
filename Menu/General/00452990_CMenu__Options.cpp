#include "tarzan_ghidra_types.hpp"

// Address: 0x00452990
// Label: CMenu::Options
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::Options(undefined **menu)

{
  if (menu == &PTR_Options_Difficulty_004eff98) {
    SetOptionsMenu(6);
    return;
  }
  if (menu == &PTR_Options_Controller_004efff8) {
    SetOptionsMenu(4);
    return;
  }
  if (menu == &PTR_Options_Sound_004f00d8) {
    SetOptionsMenu(7);
    return;
  }
  if (menu == &PTR_Options_SFXunused_004f0130) {
    SetOptionsMenu(7);
    return;
  }
  if (menu == &PTR_Options_OptionsSelections_004f0188) {
    SetOptionsMenu(7);
    return;
  }
  if ((code *)menu[3] != (code *)0x0) {
    (*(code *)menu[3])(menu);
  }
  *(undefined ***)(g_CurrentMenu + 8) = menu;
  return;
}

