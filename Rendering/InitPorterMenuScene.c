// Address: 0x00445E30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitPorterMenuScene(void)

{
  InitMenuSceneRoot(&g_PorterMenuScene);
  _DAT_00531e80 = &ModelPorter;
  _DAT_00531e7c = 0;
  InitMenuIdleScriptCursor(&g_SelectMovieIdleScriptCursor,&g_SelectMovieIdleScript);
  _DAT_00531e8c = 0xffffffe0;
  DAT_00531ec8 = (uint)CONCAT11(4,(char)DAT_00531ec8);
  return;
}


