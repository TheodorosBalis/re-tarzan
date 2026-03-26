// Address: 0x00445DE0

void RemoveOptionsGraphicsBlocks(void)

{
  HideMenuGraphicBlock(&Options_MainFont);
  HideMenuGraphicBlock(&Options_OptionsSelections);
  HideMenuGraphicBlock(&Options_Difficulty);
  HideMenuGraphicBlock(&Options_Controller);
  HideMenuGraphicBlock(&Options_Sound);
  HideMenuGraphicBlock(&Options_SFXunused);
  FreeMenuModelSet(&ModelPorter);
  return;
}


