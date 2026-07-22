#include "tarzan_ghidra_types.hpp"

// Address: 0x00447A80
// Label: InitHudExtraLifeMeter
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitHudExtraLifeMeter(void)

{
  undefined4 *dataCursor;
  short shortValue;
  
  _g_HudExtraLifeMeterSegmentSceneRef = g_WorldEntitySceneObjectArrayBase + 0x25c8;
  g_HudExtraLifeMeterEnabled = 0;
  g_HudExtraLifeMeterBaseX = 0x1d0;
  shortValue = 1;
  dataCursor = &g_HudExtraLifeMeterSegment1Sprite;
  do {
    dataCursor[-2] = 0;
    *dataCursor = 0x3058;
    *(undefined2 *)(dataCursor + 2) = 0x10;
    *(undefined2 *)((int)dataCursor + 10) = 0x10;
    *(undefined2 *)(dataCursor + 1) = 0x220;
    *(short *)((int)dataCursor + 6) = shortValue * -0x10 + 0xc2;
    dataCursor[7] = 0x80101010;
    dataCursor[-1] = _g_HudExtraLifeMeterSegmentSceneRef;
    dataCursor = dataCursor + 0xe;
    shortValue = shortValue + 1;
  } while ((int)dataCursor < 0x532668);
  _g_HudExtraLifeMeterSegmentWidth = 0x10;
  _g_HudExtraLifeMeterIconSceneRef = _g_HudExtraLifeMeterSegmentSceneRef;
  _g_HudExtraLifeMeterSegmentColor = 0x80101010;
  _g_HudExtraLifeMeterIconColor = 0x80101010;
  g_HudExtraLifeMeterPartialSegmentQuad = 0;
  _g_HudExtraLifeMeterSegmentSprite = 0x3058;
  _g_HudExtraLifeMeterPartialSegmentWidth = 0;
  g_HudExtraLifeMeterSegment0X = 0x220;
  _g_HudExtraLifeMeterPartialSegmentX = 0xb2;
  g_HudExtraLifeMeterIconQuad = 0;
  _g_HudExtraLifeMeterIconSprite = 0x3059;
  _g_HudExtraLifeMeterIconWidth = 0x40;
  _g_HudExtraLifeMeterIconHeight = 0x20;
  _g_HudExtraLifeMeterIconX = 0x208;
  _g_HudExtraLifeMeterIconY = 0x48;
  g_HudExtraLifeMeterIconV = 0;
  g_HudExtraLifeMeterIconU = 0;
  _g_HudExtraLifeAwardHoldTicks = 0;
  _g_HudTokenCounterHiddenX = 0xfffff800;
  _g_HudExtraLifeAwardHiddenX = 0xfffff800;
  _g_OptionalHudMeterPadding = 0x20;
  _g_HudExtraLifeMeterUnusedBaseXCopy = 0x1d0;
  g_HudExtraLifeMeterPulsePhase = 0x400;
  g_HudExtraLifeMeterPulseAmplitude = 0x20;
  g_ExtraLifeMeterProgress = 0;
  g_ExtraLifeMeterThreshold = 0xc;
  g_HudExtraLifeMeterDisplayedProgress = 0;
  g_HudExtraLifeAwardTriggered = 0;
  return;
}

