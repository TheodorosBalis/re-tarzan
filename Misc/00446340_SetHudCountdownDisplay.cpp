#include "tarzan_ghidra_types.hpp"

// Address: 0x00446340
// Label: SetHudCountdownDisplay
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SetHudCountdownDisplay(uint windowHandle,uint messageId)

{
  undefined4 *dataCursor;
  short *value;
  undefined2 *dataCursor2;
  undefined4 *dataCursor3;
  undefined4 *dataCursor4;
  int count;
  short shortValue;
  
  if (g_HudCountdownScene != 0) {
    if ((short)windowHandle == -1) {
      windowHandle = g_HudCountdownBcdTime >> 8;
    }
    if ((short)messageId == -1) {
      messageId = g_HudCountdownFlags;
    }
    g_HudCountdownFlags = CONCAT22(*( undefined2 *)((int)&g_HudCountdownFlags + 2),(short)messageId);
    g_HudCountdownBcdTime = (windowHandle & 0xffff) << 8;
    *(int *)(g_HudCountdownScene + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x68;
    *(undefined2 *)(g_HudCountdownScene + 0xc) = 0x2019;
    *(undefined **)(g_HudCountdownScene + 0x38) = &DAT_005328e8;
    *(undefined2 *)(g_HudCountdownScene + 0xe) = 0x100;
    *(ushort *)(g_HudCountdownScene + 0xe) =
         *(ushort *)(g_HudCountdownScene + 0xe) | (ushort)((~messageId & 0xfffe) << 0xe);
    count = g_HudCountdownScene;
    *(undefined4 *)(g_HudCountdownScene + 0x14) = g_HudCountdownPosX;
    *(undefined4 *)(count + 0x18) = g_HudCountdownPosY;
    *(undefined4 *)(count + 0x1c) = g_HudCountdownPosZ;
    count = g_HudCountdownScene;
    _g_HudCountdownDigitCount = 4;
    dataCursor = (undefined4 *)(g_HudCountdownScene + 0x20);
    value = &DAT_005328f8;
    dataCursor3 = &DAT_004f0258;
    do {
      shortValue = (short)(windowHandle & 0xf);
      if (9 < (windowHandle & 0xf)) {
        shortValue = 0;
      }
      *(undefined4 *)(value + 2) = *(undefined4 *)(count + 0x10);
      *value = shortValue + 0x200f;
      dataCursor4 = dataCursor3 + 1;
      value[1] = *(ushort *)(count + 0xe) & 0x7fff;
      *(undefined4 *)(value + 4) = *dataCursor3;
      value[6] = 0;
      value[7] = 0;
      value[8] = 0;
      value[9] = 0;
      windowHandle = windowHandle >> 4 & 0xfff;
      *(undefined4 *)(value + 10) = *dataCursor;
      *(undefined4 *)(value + 0xc) = *(undefined4 *)(count + 0x24);
      *(undefined4 *)(value + 0xe) = *(undefined4 *)(count + 0x28);
      *(undefined4 *)(value + 0x10) = *(undefined4 *)(count + 0x2c);
      value = value + 0x14;
      dataCursor3 = dataCursor4;
    } while ((int)dataCursor4 < 0x4f0268);
    count = (-(uint)((g_HudCountdownFlags & 4) != 0) & 0xfffffffe) + 4;
    if (0 < count) {
      dataCursor2 = &g_HudCountdownFirstDigitFlags;
      do {
        *(byte *)((int)dataCursor2 + 1) = *(byte *)((int)dataCursor2 + 1) | 0x80;
        dataCursor2 = dataCursor2 + 0x14;
        count = count + -1;
      } while (count != 0);
    }
  }
  return 0;
}

