/* Address: 0x00429430 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ManageFades(void)

{
  int iVar1;
  
  iVar1 = (int)FadeBrightness;
  if ((fadeIntensity._2_2_ & 0x8000) == 0) {
    DAT_0051c578 = 0x1000;
  }
  else {
    if ((fadeIntensity._2_2_ & 3) != 0) {
      if ((fadeIntensity._2_2_ & 1) == 0) {
        iVar1 = iVar1 - (uint)(ushort)fadeIntensity;
        if (iVar1 < 0) {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = iVar1 + (uint)(ushort)fadeIntensity;
        if (0xfff < iVar1) {
          FUN_004293f0();
        }
      }
    }
    FadeBrightness = (short)iVar1;
    DAT_0051c578 = iVar1;
  }
  if (FadeBrightness == 0) {
    FadeStatus = FadeStatus + 1;
  }
  _DAT_0051c4a8 = DAT_0051c578;
  return;
}

