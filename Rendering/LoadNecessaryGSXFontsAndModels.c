/* Address: 0x0041C840 */

void LoadNecessaryGSXFontsAndModels(undefined4 param_1)

{
  int iVar1;
  
  LoadFontTexture_stub(param_1);
  iVar1 = RequestModels();
  while (iVar1 != 0) {
    FUN_00439430(&DAT_0051d280);
    iVar1 = RequestModels();
  }
  FUN_00439360(&DAT_0051d280);
  FUN_00439360(&DAT_0051d280);
  FUN_00439360(&DAT_0051d280);
  FUN_00439360(&DAT_0051d280);
  FUN_00439360(&DAT_0051d280);
  return;
}

