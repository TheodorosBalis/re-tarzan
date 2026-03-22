/* Address: 0x00445D80 */

void InitSharedMenuIconSets(void)

{
  ShowMenuGraphicBlock(&PTR_DAT_004ef5d0);
  ShowMenuGraphicBlock(&PTR_DAT_004ef5f0);
  ShowMenuGraphicBlock(&PTR_DAT_004ef610);
  ShowMenuGraphicBlock(&PTR_DAT_004ef630);
  ShowMenuGraphicBlock(&PTR_DAT_004ef650);
  ShowMenuGraphicBlock(&PTR_DAT_004ef670);
  InitLevelIconSet(&PTR_DAT_004efee8);
  LoadNecessaryGSXFontsAndModels(&PTR_DAT_004efee8);
  return;
}

