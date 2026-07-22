#include "tarzan_ghidra_types.hpp"

// Address: 0x00447BD0
// Label: UpdateHudExtraLifeMeter
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateHudExtraLifeMeter(void)

{
  short shortValue;
  int value;
  int value2;
  undefined2 *dataCursor;
  short *value5;
  int value3;
  uint value4;
  
  if (g_HudExtraLifeMeterEnabled != '\0') {
    value = (g_ExtraLifeMeterProgress * 0x60) / g_ExtraLifeMeterThreshold;
    if ((int)g_HudExtraLifeMeterDisplayedProgress < value) {
      g_HudExtraLifeMeterDisplayedProgress = g_HudExtraLifeMeterDisplayedProgress + 1;
    }
    if ((g_HudExtraLifeAwardTriggered == 0) && (0x5e < value)) {
      g_HudExtraLifeAwardTriggered = 1;
      g_HudExtraLifeMeterEnabled = '\0';
      TriggerHudExtraLifeAward();
    }
    value4 = g_HudExtraLifeMeterDisplayedProgress;
    shortValue = (short)((short)(&g_SinCosTable12Bit)[g_HudExtraLifeMeterPulsePhase - 0x400 & 0xfff] *
                    g_HudExtraLifeMeterPulseAmplitude >> 0xc) + (short)g_HudExtraLifeMeterBaseX;
    g_HudExtraLifeMeterPulsePhase = g_HudExtraLifeMeterPulsePhase + 0x200 & 0xfff;
    if (g_HudExtraLifeMeterPulsePhase == 0) {
      g_HudExtraLifeMeterPulseAmplitude = g_HudExtraLifeMeterPulseAmplitude >> 1;
    }
    if (g_HudExtraLifeMeterPulseAmplitude < 4) {
      g_HudExtraLifeMeterPulseAmplitude = 0;
    }
    _g_HudExtraLifeMeterIconX = shortValue + -0x18;
    g_HudExtraLifeMeterIconQuad = 0x8022;
    value5 = &g_HudExtraLifeMeterSegment0X;
    do {
      *value5 = shortValue;
      value5 = value5 + 0x1c;
    } while ((int)value5 < 0x53266c);
    value2 = (int)value4 >> 4;
    value = value2 + 1;
    value3 = 1;
    if (1 < value) {
      dataCursor = &g_HudExtraLifeMeterSegment1Width;
      do {
        *(undefined4 *)(dataCursor + -9) = 0x8002;
        *dataCursor = 0x10;
        dataCursor = dataCursor + 0x1c;
        value2 = value2 + -1;
        value3 = value;
      } while (value2 != 0);
    }
    value4 = value4 & 0xf;
    if (value4 != 0) {
      _g_HudExtraLifeMeterPartialSegmentWidth = (short)value4;
      _g_HudExtraLifeMeterPartialSegmentX =
           (0xd2 - (short)(value3 << 4)) - _g_HudExtraLifeMeterPartialSegmentWidth;
      g_HudExtraLifeMeterPartialSegmentV = '\x0f' - (char)value4;
      g_HudExtraLifeMeterPartialSegmentQuad = 0x8022;
      g_HudExtraLifeMeterPartialSegmentU = 0;
    }
    if (value3 < 7) {
      dataCursor = (undefined2 *)(&g_HudExtraLifeMeterPartialSegmentWidth + value3 * 0x38);
      do {
        *(undefined4 *)(dataCursor + -9) = 0x802b;
        *dataCursor = 0x10;
        dataCursor = dataCursor + 0x1c;
      } while ((int)dataCursor < 0x532672);
    }
  }
  return;
}

