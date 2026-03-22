/* Address: 0x0045F180 */

void CMenu::LevelComplete_CommitProgressAndAdvanceLevel(void)

{
  byte bVar1;
  
  g_LevelTransitionContext._3_1_ =
       g_LevelTransitionContext._3_1_ + (char)(gCurrentCoinsCollected / 100);
  gCurrentCoinsCollected = gCurrentCoinsCollected + (short)(gCurrentCoinsCollected / 100) * -100;
  if ((g_LevelTransitionRewardMask6 & 0x3f) == 0x3f) {
    *(byte *)((int)&DAT_00534030 + (int)g_LevelTransitionContext._2_1_) =
         *(byte *)((int)&DAT_00534030 + (int)g_LevelTransitionContext._2_1_) |
         '\x01' << (g_LevelTransitionContext._1_1_ & 0x1f);
  }
  bVar1 = g_SelectedLevelIndex + 1;
  if (((bVar1 & 1) != 0) && ((g_LevelTransitionRewardMask4 & 0xf) != 0xf)) {
    g_SelectedLevelIndex = g_SelectedLevelIndex + 2;
    bVar1 = g_SelectedLevelIndex;
  }
  g_SelectedLevelIndex = bVar1;
  return;
}

