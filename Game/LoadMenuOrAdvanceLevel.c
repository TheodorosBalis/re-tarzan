/* Address: 0x0047EE70 */

void LoadMenuOrAdvanceLevel(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar2 = &g_LevelCompleteTextAnchor;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  MenuState = 0;
  LoadFonts(&PTR_DAT_0050df58,&DAT_00c46024);
  GetUserInputsAndZeroGlobals();
  FUN_00453b40();
  if (((g_SelectedLevelIndex < '\0') || ((&DAT_004f26a4)[g_SelectedLevelIndex * 0xf] != -1)) ||
     ((short)g_LoadTransitionFlags != -0x7fff)) {
    uVar3 = 0x16;
  }
  else {
    uVar3 = 0x15;
  }
  FUN_004ac8d0(uVar3);
  DAT_00533fe8 = 0;
  SetActiveMenuContext(&g_MenuSceneContext);
  InitLevelIconSet(&PTR_DAT_004f1e88);
  LoadNecessaryGSXFontsAndModels(&PTR_DAT_004f1e88);
  InitLevelIconSet(&PTR_DAT_004ed398);
  LoadNecessaryGSXFontsAndModels(&PTR_DAT_004ed398);
  ShowMenuGraphicBlock(&PTR_DAT_0050df38);
  FUN_004abcc0();
  ptrToDecideWhichMenu = 0;
  if (-1 < g_SelectedLevelIndex) {
    if (((&DAT_004f26a4)[g_SelectedLevelIndex * 0xf] == -1) &&
       ((short)g_LoadTransitionFlags == -0x7fff)) {
      g_SelectedLevelIndex = -1;
      ProcessMovieClipOrLogo(0x4020,0x1fe,0,0x1000);
      ProcessMovieClipOrLogo(0x4022,0x1fc,0,0x1000);
      ProcessMovieClipOrLogo(0x4023,0x1f7,0,0x1000);
      ProcessMovieClipOrLogo(0x401c,0x1ef,0,0x1000);
      ProcessMovieClipOrLogo(0x401d,0x1ea,0,0x1000);
      ProcessMovieClipOrLogo(0x401e,500,0,0x1000);
      ProcessMovieClipOrLogo(0x4030,0x1ea,0,0x1000);
      ProcessMovieClipOrLogo(0x4031,0x1ea,0,0x1000);
      ProcessMovieClipOrLogo(0x4024,500,0,0x1000);
      ProcessMovieClipOrLogo(0x4025,500,0,0x1000);
      ProcessMovieClipOrLogo(0x4029,500,0,0x1000);
      ProcessMovieClipOrLogo(0x402a,500,0,0x1000);
      ProcessMovieClipOrLogo(0x402f,500,0,0x1000);
      ProcessMovieClipOrLogo(0x402d,500,0,0x1000);
      ProcessMovieClipOrLogo(0x402e,500,0,0x1000);
      ProcessMovieClipOrLogo(0x401f,1000,0,0x1000);
    }
    if ((-1 < g_SelectedLevelIndex) && ((short)g_LoadTransitionFlags == -0x7fff)) {
      g_LevelCompleteInputMode = (int)g_SelectedLevelIndex & 1;
      ptrToDecideWhichMenu = 0;
      ptrToDecideWhichMenu2 = &g_MenuDescriptor_LevelComplete;
      CMenu::LevelComplete_Enter();
      return;
    }
  }
  g_LevelTransitionContext._2_1_ = 0x16;
  ptrToDecideWhichMenu2 = &PTR_PTR_004f1fc0;
  EnterLoadGameMenu();
  return;
}

