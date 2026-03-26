// Address: 0x004ABDF0

void ResetMenuTextureAtlasAndFontState(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  DAT_00c467fc = 0;
  puVar2 = (undefined4 *)&g_MenuTextureAtlasPixels;
  for (iVar1 = 0x8000; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  iVar1 = 0;
  do {
    UpdateTexturesReference(iVar1,0,0,0x100,0x100);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xf);
  puVar2 = &DAT_00c4607c;
  for (iVar1 = 0x1e0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}


