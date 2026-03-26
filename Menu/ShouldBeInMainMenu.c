// Address: 0x004ABC50

undefined4 ShouldBeInMainMenu(void)

{
  if ((g_LevelTransitionContext._2_1_ == '\x16') &&
     (ptrToDecideWhichMenu == &PTR_MainMenu_MainFont_004f1fc0)) {
    return 1;
  }
  return 0;
}


