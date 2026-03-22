/* Address: 0x004ABFD0 */

void TransitionToWorldOrMenu(int param_1)

{
  DAT_00534010 = DAT_00534010 & 0xfffffffb;
  bIsOnTransition = 1;
  if (param_1 != 1) {
    FUN_0049df60(1);
    DAT_00c4604c = 0;
    FUN_0047ee70(0);
    DAT_00c46050 = &ProcessMainMenu;
    DAT_00c46054 = &MainMenu::Render;
    return;
  }
  FUN_0049df60(DAT_00533fe8 != 0);
  DAT_00c4604c = 1;
  FUN_00429260(0);
  DAT_00c46050 = &CWorld::Process;
  DAT_00c46054 = &CWorld::Render;
  if (DAT_00533fe8 == 0) {
    FUN_004947d0((int)DAT_00533fe0._2_1_,(int)DAT_00533fe0._1_1_);
  }
  return;
}

