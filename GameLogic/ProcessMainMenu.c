// Address: 0x0047EDA0

undefined4 ProcessMainMenu(void)

{
  switch(MenuState) {
  case 0:
  case 1:
    MenuMainEntry();
    return 1;
  case 2:
    if ((FadeBrightness == 0) && (3 < FadeStatus)) {
      LoadGameLevel();
      return 1;
    }
    break;
  case 3:
    if ((FadeBrightness == 0) && (3 < FadeStatus)) {
      RemoveOptionsGraphicsBlocks();
      RemoveMainMenuSelections();
      HideLoadGameHeaderGraphics();
      LoadAndHandleECM(0x8010,0);
      SetActiveMenuContext(&g_MenuSceneContext);
      ShowLoadGameHeaderGraphics();
      DrawMainMenuSelections();
      RequestOptionsGraphicsBlocks();
      SelectECMfileAndInitAudio(0);
      InitiateFade(1,0x200);
      FUN_004ac410(&DAT_00c46070);
      MenuState = 0;
    }
  }
  return 1;
}


