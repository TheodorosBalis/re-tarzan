#include "tarzan_ghidra_types.hpp"

// Address: 0x00441530
// Label: MeasureEntitySpriteFontStringWidth
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int MeasureEntitySpriteFontStringWidth(char *arg1)

{
  int entry;
  int entry2;
  
  entry2 = 0;
  entry = (int)*arg1;
  if (entry == 0) {
    return 0;
  }
  do {
    arg1 = arg1 + 1;
    if (entry == 9) {
      g_HudTextCursorX = g_HudTextCursorX + 0x30;
    }
    else if (entry != 0xd) {
      if (entry == 0x20) {
        entry2 = entry2 + 0xc;
      }
      else if ((&g_HudGlyphMissingWidthTable)[g_HudTextRendererState * 0x100 + entry] == -1) {
        entry2 = entry2 + 4;
      }
      else {
        entry2 = entry2 + (uint)(byte)(&g_HudGlyphWidthTable)[entry + g_HudTextRendererState * 0x100];
      }
    }
    entry = (int)*arg1;
  } while (entry != 0);
  return entry2;
}

