#include "tarzan_ghidra_types.hpp"

// Address: 0x004476A0
// Label: InitHudHealthBar
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitHudHealthBar(void)

{
  undefined4 *dataCursor;
  int value;
  
  g_HudHealthBarEnabled = 1;
  g_HudDisplayedHealth = 0;
  g_HudDisplayedHealthMax = 0x100;
  value = 0;
  dataCursor = &DAT_00532208;
  do {
    dataCursor[-2] = 0;
    *dataCursor = 0x3017;
    *(undefined2 *)(dataCursor + 2) = 0x40;
    *(undefined2 *)((int)dataCursor + 10) = 0x10;
    *(short *)(dataCursor + 1) =
         ((short)((ulonglong)((longlong)value * 0x66666667) >> 0x28) + 0x40) -
         ((short)(char)((char)(value / 0x2800000) + (char)(value >> 0x1f)) >> 0xf);
    *(undefined2 *)((int)dataCursor + 6) = 0xd7;
    dataCursor[7] = 0x80303030;
    *(short *)((int)dataCursor + 10) = *(short *)((int)dataCursor + 10) + -1;
    if (0x13f < *(short *)(dataCursor + 1)) {
      *(short *)(dataCursor + 1) = *(short *)(dataCursor + 1) + -1;
    }
    dataCursor = dataCursor + 0xe;
    value = value + 0x8000;
  } while ((int)dataCursor < 0x5324a8);
  *( undefined2 *)((int)&g_HudPartialHealthFillWidth + 0) = 0x40;
  g_HudPartialHealthFillX = 0x40;
  g_HudPartialHealthFillQuad = 0;
  *( undefined1 *)((int)&g_HudPartialHealthFillQuad_Field1C + 0) = 0;
  *( undefined1 *)((int)&g_HudPartialHealthFillQuad_Field1C + 1) = 0;
  *( undefined1 *)((int)&g_HudPartialHealthFillUWidth + 1) = 0;
  *( undefined1 *)((int)&g_HudPartialHealthFillQuad_Field20 + 0) = 0;
  g_HudPartialHealthFillQuad_Field08 = 0x3017;
  *( undefined2 *)((int)&g_HudPartialHealthFillWidth + 2) = 0xf;
  _g_HudPartialHealthFillQuad_Field0E = 0xd7;
  *( undefined1 *)((int)&g_HudPartialHealthFillUWidth + 0) = 0x3f;
  *( undefined1 *)((int)&g_HudPartialHealthFillQuad_Field20 + 1) = 0xf;
  *( undefined1 *)((int)&g_HudPartialHealthFillClippedUWidth + 0) = 0x3f;
  *( undefined1 *)((int)&g_HudPartialHealthFillClippedUWidth + 1) = 0xf;
  return;
}

