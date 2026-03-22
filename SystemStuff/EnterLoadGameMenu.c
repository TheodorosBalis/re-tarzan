/* Address: 0x00452AC0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EnterLoadGameMenu(void)

{
  FUN_0040a950(&DAT_0051c4c8,*(undefined4 *)(DAT_00a439d4 + 0x1c));
  if ((DAT_00534010 & 0x80000000) != 0) {
    FUN_00453180();
  }
  ShowLoadGameHeaderGraphics();
  ShowLoadGameIcons();
  FUN_00445d80();
  _g_LoadGameMenuEntryFlag = 0;
  _g_LoadGameMenuProfileValue =
       *(undefined4 *)(&g_LoadGameMenuProfileTable + g_LoadGameProfileIndex * 4);
  FUN_00445e30();
  PTR_PTR_004f1fc8 = (undefined *)&PTR_PTR_004f1f98;
  ptrToDecideWhichMenu = &PTR_PTR_004f1fc0;
  ptrToDecideWhichMenu2 = &PTR_PTR_004f1fc0;
  FUN_004413f0();
  InitiateFade(1,0x100);
  return;
}

