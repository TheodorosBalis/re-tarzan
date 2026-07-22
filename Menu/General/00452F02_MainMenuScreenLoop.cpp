#include "tarzan_ghidra_types.hpp"

// Address: 0x00452F02
// Label: MainMenuScreenLoop
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void __thiscall MainMenuScreenLoop(uint menu,undefined4 menuItem,undefined4 selection,int inputFlags)

{
  code *stringCursor;
  undefined **dataCursor;
  int menuIndex;
  uint inputEax;
  
  TimeIDLEinMenu = TimeIDLEinMenu + 1;
  if (((inputEax & 0x1000) != 0) && (*(int *)(inputFlags + 0x14) != 0)) {
    PlayAudioById(0xaa,(int *)0,(undefined4 *)0);
    (**(code **)(inputFlags + 0x14))(*(undefined4 *)(inputFlags + 0x18));
    menu = g_InputCurrentMask;
  }
  if ((menu & g_InputEdgeMask & 0x4008) != 0) {
    stringCursor = *(code **)(*(int *)(inputFlags + 8) + 0x10 + *(int *)(inputFlags + 0x24) * 0x18);
    if (stringCursor != (code *)0x0) {
      dataCursor = *(undefined ***)(*(int *)(inputFlags + 8) + *(int *)(inputFlags + 0x24) * 0x18 + 0x14);
      if ((((dataCursor != &PTR_Options_Difficulty_004eff98) &&
           (dataCursor != &PTR_Options_Controller_004efff8)) &&
          (dataCursor != &PTR_Options_Sound_004f00d8)) &&
         ((dataCursor != &PTR_Options_SFXunused_004f0130 &&
          (dataCursor != &PTR_Options_OptionsSelections_004f0188)))) {
        PlayAudioById(0xac,(int *)0,(undefined4 *)0);
      }
      menuIndex = *(int *)(*(int *)(inputFlags + 8) + 0xc + *(int *)(inputFlags + 0x24) * 0x18);
      if (menuIndex != -1) {
        PlayAudioById(menuIndex,(int *)0,(undefined4 *)0);
      }
      (*stringCursor)(*(undefined4 *)(*(int *)(inputFlags + 8) + 0x14 + *(int *)(inputFlags + 0x24) * 0x18));
    }
  }
  return;
}

