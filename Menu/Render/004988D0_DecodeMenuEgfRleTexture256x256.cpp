#include "tarzan_ghidra_types.hpp"

// Address: 0x004988D0
// Label: DecodeMenuEgfRleTexture256x256
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void DecodeMenuEgfRleTexture256x256(int menu,ushort *menuItem)

{
  ushort value;
  short shortValue;
  int menuIndex;
  int menuIndex2;
  int menuIndex3;
  ushort *dataCursor;
  
  menuIndex2 = 0x100;
  do {
    shortValue = 0;
    dataCursor = menuItem;
    do {
      value = *dataCursor;
      menuItem = dataCursor + 1;
      if ((value & 0x8000) == 0) {
        menuIndex = (int)shortValue;
        shortValue = shortValue + 1;
        *(ushort *)(menu + menuIndex * 2) = value;
      }
      else {
        menuIndex = (short)(ushort)(byte)*menuItem + 1;
        do {
          menuIndex3 = (int)shortValue;
          shortValue = shortValue + 1;
          menuIndex = menuIndex + -1;
          *(ushort *)(menu + menuIndex3 * 2) = value & 0x7fff;
        } while (menuIndex != 0);
        menuItem = (ushort *)((int)dataCursor + 3);
      }
      dataCursor = menuItem;
    } while (shortValue < 0x100);
    menu = menu + 0x200;
    menuIndex2 = menuIndex2 + -1;
  } while (menuIndex2 != 0);
  return;
}

