// Address: 0x0049E720

void __fastcall LoadAndPatchMenuTextureAtlas(undefined4 param_1)

{
  float fVar1;
  short *psVar2;
  int iVar3;
  
  OpenMenuEgfAndIndexChunks(s_t__win_grafix_menu_egf_00517588,param_1);
  LoadMenuEgfChunkToTextureAtlas(0,&g_MenuTextureAtlasPixels);
  ResetMenuEgfState();
  psVar2 = &g_MenuTextureAtlasPixels;
  do {
    if ((*psVar2 == 0x3e0) || (*psVar2 == 0x1f)) {
      *psVar2 = 0;
    }
    psVar2 = psVar2 + 1;
  } while ((int)psVar2 < 0x79e7b0);
  UpdateTexturesReference(0xf,0,0,0x100,0x100);
  iVar3 = 0;
  do {
    fVar1 = (float)iVar3;
    iVar3 = iVar3 + 1;
    FillMenuTextureColorRampSpan(iVar3,0xda,0,8,0,0,0,0,fVar1,0);
    FillMenuTextureColorRampSpan(iVar3,0xe1,0,8,0,fVar1,0,0,0,0);
  } while (iVar3 < 0x20);
  UpdateTexturesReference(0xf,0,0,0x100,0x100);
  return;
}


