#include "tarzan_ghidra_types.hpp"

// Address: 0x00452E7B
// Label: MenuNavigate
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void __thiscall MenuNavigate(uint menu,undefined4 menuItem,undefined4 selection,int inputFlags)

{
  uint inputEax;
  
  if (0 < TimeIDLEinMenu) {
    TimeIDLEinMenu = 0;
  }
  if ((((inputEax & 0x40) != 0) && (*(int *)(inputFlags + 0x24) < *(int *)(inputFlags + 4) + -1)) &&
     (*(int *)(*(int *)(inputFlags + 8) + 0x1c + *(int *)(inputFlags + 0x24) * 0x18) != -1)) {
    PlayAudioById(0xaa,(int *)0,(undefined4 *)0);
    *(int *)(inputFlags + 0x24) = *(int *)(inputFlags + 0x24) + 1;
    menu = g_InputCurrentMask;
  }
  if (((menu & g_InputEdgeMask & 0x10) != 0) && (0 < *(int *)(inputFlags + 0x24))) {
    PlayAudioById(0xaa,(int *)0,(undefined4 *)0);
    *(int *)(inputFlags + 0x24) = *(int *)(inputFlags + 0x24) + -1;
    return;
  }
  return;
}

