#include "tarzan_ghidra_types.hpp"

// Address: 0x004531E0
// Label: UpdateMenuButtonSequenceDetector
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateMenuButtonSequenceDetector(undefined4 *menu)

{
  int menuIndex;
  uint value;
  
  menuIndex = menu[2];
  value = menu[menuIndex + 4];
  if ((value != 0) && ((g_InputCurrentMask & g_InputEdgeMask & 0xffff) != 0)) {
    if ((g_InputCurrentMask & g_InputEdgeMask & value) == value) {
      if (menuIndex == 0) {
        menu[3] = FrameCount;
      }
      menu[2] = menuIndex + 1;
      if (menu[menuIndex + 5] != 0) {
        return;
      }
      if ((uint)(FrameCount - menu[3]) <= (uint)menu[1]) {
        PlayAudioById(0xac,(int *)0,(undefined4 *)0);
        (*(code *)*menu)();
        return;
      }
    }
    menu[2] = 0;
  }
  return;
}

