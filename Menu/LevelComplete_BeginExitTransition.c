/* Address: 0x0045F210 */

void CMenu::LevelComplete_BeginExitTransition(void)

{
  InitCinematic_stub(&DAT_00c46070);
  InitiateFade(2,0x100);
  MenuState = 2;
  return;
}

