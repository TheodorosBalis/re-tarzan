#include "tarzan_ghidra_types.hpp"

// Address: 0x00441420
// Label: DrawEntitySpriteFontString
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DrawEntitySpriteFontString(ushort arg1,short arg2,char *arg3,undefined4 arg4)

{
  char resultFlag;
  int entry;
  int entry2;
  short shortValue;
  uint value;
  
  value = (uint)arg1;
  if ((short)arg1 < 0) {
    entry2 = MeasureEntitySpriteFontStringWidth(arg3);
    value = (g_TextLayoutScreenWidth - entry2) / 2;
  }
  g_HudTextCurrentGlyphX = (ushort)value;
  _g_HudTextCursorX = CONCAT22(arg2 << 1,g_HudTextCurrentGlyphX);
  resultFlag = *arg3;
  entry2 = g_HudTextRendererState;
  do {
    entry = (int)resultFlag;
    if (entry == 0) {
      return;
    }
    arg3 = arg3 + 1;
    shortValue = (short)value;
    if (entry == 9) {
      value = (uint)(ushort)(shortValue + 0x30);
LAB_00441513:
      _g_HudTextCursorX = CONCAT22(_g_HudTextCursorY,(short)value);
    }
    else {
      if (entry != 0xd) {
        if (entry == 0x20) {
          value = (uint)(ushort)(shortValue + 0xc);
        }
        else if ((int)(short)(&g_HudGlyphMissingWidthTable)[entry2 * 0x100 + entry] == 0xffffffff) {
          value = (uint)(ushort)(shortValue + 4);
        }
        else {
          DrawSceneSpriteQuad(g_EntitySpriteFontGlyphQuadTable +
                              ((int)(short)(&g_HudGlyphMissingWidthTable)[entry2 * 0x100 + entry] &
                              0xfffU) * 0x26,_g_HudTextCursorX,0,arg4);
          value = (uint)(ushort)(g_HudTextCursorX +
                                (ushort)(byte)(&g_HudGlyphWidthTable)
                                              [entry + g_HudTextRendererState * 0x100]);
          entry2 = g_HudTextRendererState;
        }
        goto LAB_00441513;
      }
      value = (uint)g_HudTextCurrentGlyphX;
      _g_HudTextCursorY = (short)((uint)_g_HudTextCursorX >> 0x10);
      _g_HudTextCursorY = _g_HudTextCursorY + 0x12;
      _g_HudTextCursorX = CONCAT22(_g_HudTextCursorY,g_HudTextCurrentGlyphX);
    }
    resultFlag = *arg3;
  } while( true );
}

