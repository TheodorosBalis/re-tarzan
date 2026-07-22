#include "tarzan_ghidra_types.hpp"

// Address: 0x0045EB10
// Label: CMenu::LevelComplete_AddSlotSpin
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::LevelComplete_AddSlotSpin(int menu,short menuItem)

{
  *(undefined2 *)(menu + 0xa6) = 0;
  *(ushort *)(menu + 0xa2) =
       ((*(short *)(menu + 0xa2) + menuItem) - 0x400U & 0x7ff) - 0x400 & 0xfff;
  return;
}

