#include "tarzan_ghidra_types.hpp"

// Address: 0x0045E490
// Label: CMenu::LevelComplete_SetThreeDigitCounterSprites
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::LevelComplete_SetThreeDigitCounterSprites(int menu,int menuItem,short selection)

{
  int menuIndex;
  int menuIndex2;
  
  menuIndex = menuItem / 100;
  menuIndex2 = 2;
  if (0 < menuIndex) {
    menuIndex2 = 1;
    menuItem = menuItem % 100;
    *(byte *)(menu + 0xf) = *(byte *)(menu + 0xf) | 0x80;
    *(short *)(menu + 0xc) = (short)menuIndex + selection;
    menu = menu + 0x144;
  }
  if ((0 < menuItem / 10) || (menuIndex2 != 2)) {
    *(byte *)(menu + 0xf) = *(byte *)(menu + 0xf) | 0x80;
    *(short *)(menu + 0xc) = (short)(menuItem / 10) + selection;
    menu = menu + 0x144;
    menuItem = menuItem % 10;
    menuIndex2 = menuIndex2 + -1;
  }
  *(byte *)(menu + 0xf) = *(byte *)(menu + 0xf) | 0x80;
  menuIndex = menu + 0xe;
  *(short *)(menu + 0xc) = (short)menuItem + selection;
  for (; menuIndex2 != 0; menuIndex2 = menuIndex2 + -1) {
    *(ushort *)(menuIndex + 0x144) = *(ushort *)(menuIndex + 0x144) & 0x7fff;
    menuIndex = menuIndex + 0x144;
  }
  return;
}

