#include "tarzan_ghidra_types.hpp"

// Address: 0x00452E30
// Label: CMenu::UpdateMenuInput
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::UpdateMenuInput(int menu)

{
  code *selectedCallback;
  undefined **selectedSubMenu;
  int selectionSoundId;
  uint pressedMenuInput;
  
  if ((ram0x00534026 & 0x8000) == 0) {
    if (FadeBrightness != 0) goto LAB_00452e63;
  }
  else if (FadeBrightness != 0) {
    return;
  }
  if (3 < FadeStatus) {
    return;
  }
LAB_00452e63:
  pressedMenuInput = g_InputCurrentMask & g_InputEdgeMask;
  if ((pressedMenuInput & 0x50) == 0) {
    TimeIDLEinMenu = TimeIDLEinMenu + 1;
    if (((pressedMenuInput & 0x1000) != 0) && (*(int *)(menu + 0x14) != 0)) {
      PlayAudioById(0xaa,(int *)0,(undefined4 *)0);
      (**(code **)(menu + 0x14))(*(undefined4 *)(menu + 0x18));
    }
    if ((g_InputCurrentMask & g_InputEdgeMask & 0x4008) != 0) {
      selectedCallback = *(code **)(*(int *)(menu + 8) + 0x10 + *(int *)(menu + 0x24) * 0x18);
      if (selectedCallback != (code *)0x0) {
        selectedSubMenu = *(undefined ***)(*(int *)(menu + 8) + *(int *)(menu + 0x24) * 0x18 + 0x14);
        if ((((selectedSubMenu != &PTR_Options_Difficulty_004eff98) &&
             (selectedSubMenu != &PTR_Options_Controller_004efff8)) &&
            (selectedSubMenu != &PTR_Options_Sound_004f00d8)) &&
           ((selectedSubMenu != &PTR_Options_SFXunused_004f0130 &&
            (selectedSubMenu != &PTR_Options_OptionsSelections_004f0188)))) {
          PlayAudioById(0xac,(int *)0,(undefined4 *)0);
        }
        selectionSoundId = *(int *)(*(int *)(menu + 8) + 0xc + *(int *)(menu + 0x24) * 0x18);
        if (selectionSoundId != -1) {
          PlayAudioById(selectionSoundId,(int *)0,(undefined4 *)0);
        }
        (*selectedCallback)(*(undefined4 *)(*(int *)(menu + 8) + 0x14 + *(int *)(menu + 0x24) * 0x18));
      }
    }
  }
  else {
    if (0 < TimeIDLEinMenu) {
      TimeIDLEinMenu = 0;
    }
    if ((((pressedMenuInput & 0x40) != 0) && (*(int *)(menu + 0x24) < *(int *)(menu + 4) + -1)) &&
       (*(int *)(*(int *)(menu + 8) + 0x1c + *(int *)(menu + 0x24) * 0x18) != -1)) {
      PlayAudioById(0xaa,(int *)0,(undefined4 *)0);
      *(int *)(menu + 0x24) = *(int *)(menu + 0x24) + 1;
    }
    if (((g_InputCurrentMask & g_InputEdgeMask & 0x10) != 0) && (0 < *(int *)(menu + 0x24))) {
      PlayAudioById(0xaa,(int *)0,(undefined4 *)0);
      *(int *)(menu + 0x24) = *(int *)(menu + 0x24) + -1;
      return;
    }
  }
  return;
}

