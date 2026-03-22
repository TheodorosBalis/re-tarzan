/* Address: 0x00429370 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitiateFade(ushort param_1,undefined2 param_2)

{
  fadeIntensity._0_2_ = param_2;
  fadeIntensity._2_2_ = param_1 | 0x8000;
  FadeStatus = 0;
  if (((param_1 & 0x10) != 0) && ((param_1 & 3) != 0)) {
    FadeBrightness = (-(ushort)((param_1 & 1) != 0) & 0xf001) + 0x1000;
  }
  _DAT_0051c57c = 0;
  _DAT_0051c580 = 0;
  _DAT_0051c584 = 0;
  _DAT_0051c4ac = 0;
  _DAT_0051c4b0 = 0;
  _DAT_0051c4b4 = 0;
  DAT_0051c578 = (int)FadeBrightness;
  _DAT_0051c4a8 = (int)FadeBrightness;
  return;
}

