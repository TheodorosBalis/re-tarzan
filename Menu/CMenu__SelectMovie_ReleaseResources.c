// Address: 0x0043F7C0

void CMenu__SelectMovie_ReleaseResources(void)

{
  FreeMenuModelSet(&g_SelectMovieIconSet);
  HideMenuGraphicBlock(&g_SelectMovieHeaderGraphicBlock);
  return;
}


