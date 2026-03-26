// Address: 0x00445D80

void RequestOptionsGraphicsBlocks(void)

{
  LoadMenuGraphicBlock(&Options_MainFont);
  LoadMenuGraphicBlock(&Options_OptionsSelections);
  LoadMenuGraphicBlock(&Options_Difficulty);
  LoadMenuGraphicBlock(&Options_Controller);
  LoadMenuGraphicBlock(&Options_Sound);
  LoadMenuGraphicBlock(&Options_SFXunused);
  ResetMenuModelSet(&ModelPorter);
  LoadNecessaryGSXFontsAndModels(&ModelPorter);
  return;
}


