// Address: 0x00439170

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitJaneMenuScene(void)

{
  InitMenuSceneRoot(&g_JaneMenuScene);
  DAT_0051d008 = (uint)CONCAT11(0xbe,(char)DAT_0051d008);
  DAT_0051d00c = DAT_0051d00c & 0xff;
  _DAT_0051cfc0 = &ModelJane;
  _DAT_0051cfbc = 0;
  _DAT_0051d056 = 0;
  _DAT_0051cfc8 = 0x80;
  _DAT_0051cfcc = 0x40;
  _DAT_0051d052 = 0;
  InitMenuIdleScriptCursor(&DAT_0051d0f8,&DAT_004ed280);
  DAT_0051c4dc = 0x280;
  return;
}


