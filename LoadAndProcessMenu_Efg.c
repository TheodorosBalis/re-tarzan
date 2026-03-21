/* Address: 0x0049E720 */

void __fastcall LoadAndProcessMenu_Efg(undefined4 param_1)

{
  float fVar1;
  short *psVar2;
  int iVar3;
  
  SetupAndLoadMenuEfgFile(s_t::win_grafix_menu_egf_00517588,param_1);
  CopyEfgFiletoMem(0,&DAT_0077e7b0);
  FUN_00498930();
  psVar2 = &DAT_0077e7b0;
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
    FUN_0049e630(iVar3,0xda,0,8,0,0,0,0,fVar1,0);
    FUN_0049e630(iVar3,0xe1,0,8,0,fVar1,0,0,0,0);
  } while (iVar3 < 0x20);
  UpdateTexturesReference(0xf,0,0,0x100,0x100);
  return;
}

