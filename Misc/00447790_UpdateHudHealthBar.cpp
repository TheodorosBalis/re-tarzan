#include "tarzan_ghidra_types.hpp"

// Address: 0x00447790
// Label: UpdateHudHealthBar
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateHudHealthBar(void)

{
  undefined4 *dataCursor;
  uint value3;
  uint value4;
  int value;
  int value2;
  bool flagByte;
  undefined2 localState;
  
  if (g_HudHealthBarEnabled == '\0') {
    return;
  }
  value3 = (uint)g_PlayerMaxHealth;
  flagByte = (int)(g_HudDisplayedHealthMax - value3) < 0;
  if ((int)g_HudDisplayedHealthMax < (int)value3) {
    g_HudDisplayedHealthMax = g_HudDisplayedHealthMax + 2;
    if ((int)value3 < (int)g_HudDisplayedHealthMax) {
      flagByte = false;
      g_HudDisplayedHealthMax = value3;
      goto LAB_004477c7;
    }
  }
  else {
LAB_004477c7:
    if ((g_HudDisplayedHealthMax != value3 && SBORROW4(g_HudDisplayedHealthMax,value3) == flagByte) &&
       (g_HudDisplayedHealthMax = g_HudDisplayedHealthMax - 2,
       (int)g_HudDisplayedHealthMax < (int)value3)) {
      g_HudDisplayedHealthMax = value3;
    }
  }
  value3 = g_HudDisplayedHealthMax;
  value4 = (uint)g_PlayerHealth;
  flagByte = (int)(g_HudDisplayedHealth - value4) < 0;
  if ((int)g_HudDisplayedHealth < (int)value4) {
    g_HudDisplayedHealth = g_HudDisplayedHealth + 2;
    if ((int)g_HudDisplayedHealth <= (int)value4) goto LAB_0044781c;
    flagByte = false;
    g_HudDisplayedHealth = value4;
  }
  if ((g_HudDisplayedHealth != value4 && SBORROW4(g_HudDisplayedHealth,value4) == flagByte) &&
     (g_HudDisplayedHealth = g_HudDisplayedHealth - 2, (int)g_HudDisplayedHealth < (int)value4)) {
    g_HudDisplayedHealth = value4;
  }
LAB_0044781c:
  value4 = g_HudDisplayedHealth;
  if ((int)g_HudDisplayedHealthMax < (int)g_HudDisplayedHealth) {
    value4 = g_HudDisplayedHealthMax;
  }
  value = 0;
  value2 = (int)g_HudDisplayedHealthMax >> 6;
  if (0 < value2) {
    dataCursor = &g_HudHealthSegment0Color;
    do {
      if (value < (int)value4 >> 6) {
        dataCursor[-9] = 0x800c;
        *dataCursor = 0x80005000;
      }
      else {
        dataCursor[-9] = 0x800a;
        *dataCursor = 0x80000050;
      }
      *(undefined2 *)(dataCursor + -5) = 0x40;
      value = value + 1;
      dataCursor = dataCursor + 0xe;
    } while (value < value2);
  }
  value3 = value3 & 0x3f;
  value2 = value;
  if (value3 != 0) {
    localState = (undefined2)value3;
    value2 = value + 1;
    (&g_HudHealthSegmentQuads)[value * 0xe] = 0x802c;
    (&g_HudHealthSegment0Color)[value * 0xe] = 0x80000050;
    (&g_HudHealthSegment0Width)[value * 0x1c] = localState;
    (&g_HudHealthSegment0UWidth)[value * 0x38] = (char)value3;
    (&g_HudHealthSegment0ClippedUWidth)[value * 0x38] = (char)value3;
  }
  if (value2 < 0xc) {
    dataCursor = &g_HudHealthSegmentQuads + value2 * 0xe;
    do {
      *dataCursor = 0;
      dataCursor = dataCursor + 0xe;
    } while ((int)dataCursor < 0x5324a0);
  }
  value3 = value4 & 0x3f;
  if (value3 != 0) {
    value = ((int)value4 >> 6) << 0xf;
    g_HudPartialHealthFillQuad = 0x802c;
    g_HudPartialHealthFillColor = 0x80005000;
    *( undefined2 *)((int)&g_HudPartialHealthFillWidth + 0) = (undefined2)value3;
    *( undefined1 *)((int)&g_HudPartialHealthFillUWidth + 0) = (undefined1)value3;
    g_HudPartialHealthFillX =
         ((short)((ulonglong)((longlong)value * 0x66666667) >> 0x28) + 0x40) -
         ((short)(char)((char)(value / 0x2800000) + (char)(value >> 0x1f)) >> 0xf);
    *( undefined1 *)((int)&g_HudPartialHealthFillClippedUWidth + 0) = (undefined1)g_HudPartialHealthFillUWidth;
    if (0x13f < g_HudPartialHealthFillX) {
      g_HudPartialHealthFillX = g_HudPartialHealthFillX + -1;
    }
  }
  return;
}

