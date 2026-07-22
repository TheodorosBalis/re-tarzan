#include "tarzan_ghidra_types.hpp"

// Address: 0x0049E630
// Label: FillMenuTextureColorRampSpan
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void FillMenuTextureColorRampSpan(char menu,char menuItem,int selection,int inputFlags)

{
  bool flagByte;
  ushort value;
  bool flagByte2;
  ushort value2;
  ushort value3;
  ushort value4;
  
  flagByte = 0 < selection;
  flagByte2 = !flagByte;
  if (flagByte2) {
    selection = inputFlags;
  }
  if (-1 < selection + -1) {
    do {
      value2 = ConvertFpuTopToInt64();
      value3 = ConvertFpuTopToInt64();
      value4 = ConvertFpuTopToInt64();
      value = CONCAT11(menuItem,menu);
      menu = menu + flagByte;
      (&g_MenuTextureAtlasPixels)[value] = ((value2 & 0x1f) << 5 | value3 & 0x1f) << 5 | value4 & 0x1f;
      menuItem = menuItem + flagByte2;
      selection = selection + -1;
    } while (selection != 0);
  }
  return;
}

