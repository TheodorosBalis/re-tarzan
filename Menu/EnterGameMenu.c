// Address: 0x00452AC0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EnterGameMenu(void)

{
  InitSceneAnchorTransform
            (&g_TransitionSceneAnchorPrimary,*(undefined4 *)(g_ActiveMenuContext + 0x1c));
  if ((DAT_00534010 & 0x80000000) != 0) {
    FUN_00453180();
  }
  ShowLoadGameHeaderGraphics();
  DrawMainMenuSelections();
  RequestOptionsGraphicsBlocks();
  _g_LoadGameMenuEntryFlag = 0;
  _g_LoadGameMenuProfileValue =
       *(undefined4 *)(&g_LoadGameMenuProfileTable + g_LoadGameProfileIndex * 4);
  InitPorterMenuScene();
  PTR_PTR_004f1fc8 = (undefined *)&PTR_MainMenu_Selections_004f1f98;
  ptrToDecideWhichMenu = &PTR_MainMenu_MainFont_004f1fc0;
  ptrToDecideWhichMenu2 = &PTR_MainMenu_MainFont_004f1fc0;
  FUN_004413f0();
  InitiateFade(1,0x100);
  return;
}


