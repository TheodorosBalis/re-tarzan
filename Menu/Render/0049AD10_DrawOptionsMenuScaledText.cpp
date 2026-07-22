#include "tarzan_ghidra_types.hpp"

// Address: 0x0049AD10
// Label: DrawOptionsMenuScaledText
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void DrawOptionsMenuScaledText
               (undefined4 menu,undefined4 menuItem,undefined4 selection,undefined4 inputFlags,
               undefined4 arg5)

{
  int menuIndex;
  undefined4 value;
  undefined4 value2;
  
  value2 = 0xf;
  menuIndex = GetWindowWidth();
  if (menuIndex < 0x280) {
    value2 = 0x60;
  }
  value = GetWindowWidth_Stub(selection,inputFlags,arg5);
  value = GetWindowWidth_stub2(value);
  value2 = GetWindowWidth_Stub(1,value2,value);
  value2 = GetWindowWidth_stub2(value2);
  DrawGraphicsText(menu,menuItem,value2);
  return;
}

