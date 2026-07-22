#include "tarzan_ghidra_types.hpp"

// Address: 0x004475D0
// Label: UpdateHudCollectedTARZANLettersPanel
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateHudCollectedTARZANLettersPanel(void)

{
  int value;
  ushort *dataCursor;
  uint value3;
  int value2;
  
  value2 = g_HudCollectedTARZANslotScene;
  if (g_HudCollectedTARZANslotScene != 0) {
    dataCursor = &g_HudTARZANLetterQuad0Flags;
    value3 = (uint)g_CollectedTARZANLetterMask6;
    do {
      if ((value3 & 1) == 0) {
        *dataCursor = *dataCursor | 0x421;
      }
      else {
        *dataCursor = *dataCursor & 0xfbde;
      }
      dataCursor = dataCursor + 0x14;
      value3 = (int)value3 >> 1;
    } while ((int)dataCursor < 0x532812);
    if (((byte)g_GameplayStateFlags & 1) == 0) {
      value = *(int *)(value2 + 0x1c);
      if (g_HudCollectedTARZANslotSlideTicks < 0) {
        if (-0x800 < value) {
          *(int *)(value2 + 0x1c) = value + -0x100;
          value2 = g_HudCollectedTARZANslotScene;
        }
      }
      else {
        if (value < 0) {
          *(int *)(value2 + 0x1c) = value + 0x100;
        }
        else {
          *(undefined4 *)(value2 + 0x1c) = 0;
        }
        g_HudCollectedTARZANslotSlideTicks = g_HudCollectedTARZANslotSlideTicks + -1;
        value2 = g_HudCollectedTARZANslotScene;
      }
    }
    else if (*(int *)(value2 + 0x1c) < 0) {
      *(int *)(value2 + 0x1c) = *(int *)(value2 + 0x1c) + 0x100;
      value2 = g_HudCollectedTARZANslotScene;
    }
    else {
      *(undefined4 *)(value2 + 0x1c) = 0;
      value2 = g_HudCollectedTARZANslotScene;
    }
    if (*(int *)(value2 + 0x1c) < -0x7ff) {
      *(undefined4 *)(value2 + 0x38) = 0;
    }
    else {
      *(undefined **)(value2 + 0x38) = &g_HudTARZANLetterQuads;
    }
    *(ushort *)(g_HudCollectedTARZANslotScene + 0xa4) =
         (ushort)(*(int *)(g_HudCollectedTARZANslotScene + 0x1c) >> 1) & 0xfff;
  }
  return;
}

