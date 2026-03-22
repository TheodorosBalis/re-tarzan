/* Address: 0x0043F7C0 */

void CMenu::SelectMovie_ReleaseResources(void)

{
  FreeLevelIconSet(&g_SelectMovieIconSet);
  HideMenuGraphicBlock(&g_SelectMovieHeaderGraphicBlock);
  return;
}

