#include "tarzan_ghidra_types.hpp"

// Address: 0x0045E6C0
// Label: CMenu::LevelComplete_UpdateRewardBurstSystem
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::LevelComplete_UpdateRewardBurstSystem(int *menu)

{
  int menuIndex;
  int menuIndex2;
  uint value;
  int menuIndex3;
  uint value2;
  int *menuEntry;
  
  menuEntry = menu + 7;
  if (0 < *menu) {
    *menu = *menu + -1;
    menuIndex = menu[3];
    menuIndex2 = menu[1] + 0xa0;
    menu[2] = menu[2] + (short)(&g_SinCosTable12Bit)[menu[1] & 0xfff] + 0x300;
    menu[3] = menuIndex + 0xc;
    menu[1] = menuIndex2;
    if (0x3ff < menuIndex2) {
      menu[1] = 0x400;
    }
    menuIndex2 = menu[2] >> 3;
    value2 = 0;
    do {
      if ((*(byte *)((int)menuEntry + 0xf) & 0x80) != 0) {
        menuIndex3 = menuEntry[0x55] + (value2 & 0x1f) * -4 + -0x40;
        menuEntry[0x55] = menuIndex3;
        if (menuIndex3 < 1) {
          *(ushort *)((int)menuEntry + 0xe) = *(ushort *)((int)menuEntry + 0xe) & 0x7fff;
        }
        menuIndex3 = menuEntry[0x52];
        value = menuIndex + 0xc + menuEntry[0x56];
        menuEntry[0x52] = menuIndex3 + 9;
        menuEntry[5] = ((short)(&g_SinCosTable12Bit)[value - 0x400 & 0xfff] * menuIndex2 >> 0xc) *
                    menuEntry[0x57] >> 0xc;
        menuEntry[6] = (menuIndex3 + 9) * menuIndex2 >> 0xc;
        menuEntry[7] = ((short)(&g_SinCosTable12Bit)[value & 0xfff] * menuIndex2 >> 0xc) * menuEntry[0x57] >>
                    0xc;
        *(ushort *)(menuEntry + 0x29) = (short)menuEntry[0x29] + ((ushort)value2 & 0x1f) * 8 + -0x40;
        menuEntry[0xc] = menuEntry[0x55] + -1;
        RenderSceneHierarchy(menuEntry);
      }
      menuEntry = menuEntry + 0x58;
      value2 = value2 + 1;
    } while ((int)value2 < 0x30);
  }
  return;
}

