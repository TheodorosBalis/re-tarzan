
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitOptionalHudMeter(void)

{
  g_OptionalHudMeterScene = 1;
  g_OptionalHudMeterValue = 1;
  g_OptionalHudMeterMax = 1;
  g_OptionalHudMeterDisplayedFill = 0;
  _g_OptionalHudMeterFrameQuad = 0x800b;
  _g_OptionalHudMeterFrameColor = 0x80003000;
  _g_OptionalHudMeterFrameWidth = 0xc;
  _g_OptionalHudMeterFrameHeight = 0x80;
  _g_OptionalHudMeterFrameX = 0x1e8;
  _g_OptionalHudMeterFrameY = 0x40;
  _g_OptionalHudMeterFillQuad = 0x800b;
  _g_OptionalHudMeterFillColor = 0x80000030;
  _g_OptionalHudMeterFillWidth = 0xc;
  _g_OptionalHudMeterFillClipWidth = 0x80;
  _g_OptionalHudMeterFillX = 0x1e8;
  _g_OptionalHudMeterFillY = 0x40;
  return;
}

