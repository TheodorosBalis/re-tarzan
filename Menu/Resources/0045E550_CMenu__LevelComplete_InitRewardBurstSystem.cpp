#include "tarzan_ghidra_types.hpp"

// Address: 0x0045E550
// Label: CMenu::LevelComplete_InitRewardBurstSystem
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::LevelComplete_InitRewardBurstSystem(undefined4 *menu,undefined4 *menuItem)

{
  int menuIndex;
  undefined4 value;
  int menuIndex2;
  
  *menu = 300;
  menu[1] = 0;
  menu[2] = 0;
  menu[3] = 0;
  menu = menu + 7;
  menuIndex2 = 0x30;
  do {
    InitLoadGamePreviewTransform(menu);
    *(undefined2 *)((int)menu + 0xe) = 0x8521;
    menu[4] = &LevelCompleteObjects;
    *(undefined2 *)(menu + 3) = 0x200c;
    menu[0x15] = *menuItem;
    menu[0x16] = menuItem[1];
    menu[0x17] = menuItem[2];
    menuIndex = RandomModulo(0x400);
    menu[0x51] = menuIndex + -0x200;
    menuIndex = RandomModulo(0x280);
    menu[0x52] = 0x80 - menuIndex;
    menuIndex = RandomModulo(0x400);
    menu[0x53] = menuIndex + -0x200;
    menuIndex = RandomModulo(0x200);
    menu[0x54] = menuIndex + 0x80;
    menuIndex = RandomModulo(0xc00);
    menu[0x55] = menuIndex + 0x400;
    value = RandomModulo(0x1000);
    menu[0x56] = value;
    value = RandomModulo(0x200);
    menu[0x57] = value;
    menu[0xc] = menu[0x55];
    menuIndex = RandomModulo(0x100);
    menu[5] = menuIndex + -0x80;
    menuIndex = RandomModulo(0x100);
    menu[6] = menuIndex + -0x80;
    menuIndex = RandomModulo(0x100);
    *(undefined2 *)((int)menu + 0xa6) = 0;
    menu[7] = menuIndex + 0x80;
    value = menu[0x54];
    *(undefined2 *)(menu + 0x28) = 0;
    *(undefined2 *)((int)menu + 0xa2) = 0;
    *(undefined2 *)(menu + 0x29) = 0;
    menu[0x2d] = 1;
    menu[0x2a] = value;
    menu[0x2b] = value;
    menu[0x2c] = value;
    menu = menu + 0x58;
    menuIndex2 = menuIndex2 + -1;
  } while (menuIndex2 != 0);
  return;
}

