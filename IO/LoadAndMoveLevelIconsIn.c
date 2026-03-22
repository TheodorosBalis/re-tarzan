/* Address: 0x00438E00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LoadAndMoveLevelIconsIn(void)

{
  InitLevelIconSet(&g_LoadGameIconSet);
  LoadNecessaryGSXFontsAndModels(&g_LoadGameIconSet);
  _g_LoadGameSelectionState = 0;
  _CurrentSelectedLevel = 0;
  InitLoadGamePreviewTransform(&g_LoadGamePreviewState);
  _DAT_0051d1c0 = 0x400;
  _DAT_0051d1c4 = 0x400;
  _DAT_0051d1c8 = 0x400;
  _DAT_0051d174 = _DAT_0051d174 & 0xff;
  _DAT_0051d170 = (uint)CONCAT11(100,(char)_DAT_0051d170);
  uRam0051d12c = 0;
  uRam0051d130 = 0;
  puRam0051d128 = &g_LoadGameIconSet;
  uRam0051d126 = 0x9521;
  uRam0051d148 = 0x990;
  puRam0051d218 = &DAT_0051c4c8;
  _DAT_0051d134 = 900;
  _DAT_0051d1cc = 1;
  _DAT_0051d16c =
       ((uint)(((int)(_DAT_0051d16c & 0xff | 0x19400) >> 8) << 9) / 0x280) * 0x100 |
       _DAT_0051d16c & 0xff;
  return;
}

