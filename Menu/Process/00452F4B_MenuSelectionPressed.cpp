#include "tarzan_ghidra_types.hpp"

// Address: 0x00452F4B
// Label: MenuSelectionPressed
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void MenuSelectionPressed(void)

{
  code *stringCursor;
  undefined **dataCursor;
  int menuIndex;
  int savedEsi;
  
  stringCursor = *(code **)(*(int *)(savedEsi + 8) + 0x10 + *(int *)(savedEsi + 0x24) * 0x18);
  if (stringCursor != (code *)0x0) {
    dataCursor = *(undefined ***)(*(int *)(savedEsi + 8) + *(int *)(savedEsi + 0x24) * 0x18 + 0x14);
    if ((((dataCursor != &PTR_Options_Difficulty_004eff98) &&
         (dataCursor != &PTR_Options_Controller_004efff8)) && (dataCursor != &PTR_Options_Sound_004f00d8))
       && ((dataCursor != &PTR_Options_SFXunused_004f0130 &&
           (dataCursor != &PTR_Options_OptionsSelections_004f0188)))) {
      PlayAudioById(0xac,(int *)0,(undefined4 *)0);
    }
    menuIndex = *(int *)(*(int *)(savedEsi + 8) + 0xc + *(int *)(savedEsi + 0x24) * 0x18);
    if (menuIndex != -1) {
      PlayAudioById(menuIndex,(int *)0,(undefined4 *)0);
    }
    (*stringCursor)(*(undefined4 *)(*(int *)(savedEsi + 8) + 0x14 + *(int *)(savedEsi + 0x24) * 0x18));
  }
  return;
}

