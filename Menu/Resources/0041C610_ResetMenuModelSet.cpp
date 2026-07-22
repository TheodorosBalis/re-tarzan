#include "tarzan_ghidra_types.hpp"

// Address: 0x0041C610
// Label: ResetMenuModelSet
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetMenuModelSet(int menu)

{
  Entity *entity = (Entity *)menu;
  undefined4 *dataCursor;
  int menuIndex;
  
  menuIndex = 7;
  *(undefined4 *)(menu + 8) = 0xffffffff;
  entity->previous = 0;
  dataCursor = (undefined4 *)(menu + 0x2c);
  do {
    dataCursor[1] = 0;
    *dataCursor = 0xffffffff;
    dataCursor = dataCursor + 2;
    menuIndex = menuIndex + -1;
  } while (menuIndex != 0);
  *(undefined4 *)(menu + 100) = 0;
  ResetBitmapCellRuntimeDescriptor(menu + 0x10);
  return;
}

