// Address: 0x0049A480

int OpenVirtualGameFileByPath(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 local_400 [1024];
  
  if (g_IsTarzanFsdArchiveActive != 0) {
    uVar2 = NormalizeVirtualGamePath(param_1);
    uVar3 = HashVirtualGamePath(uVar2);
    iVar6 = g_TarzanFsdEntryCount >> 1;
    uVar1 = (&g_TarzanFsdEntryTable)[iVar6 * 3];
    iVar4 = 0;
    iVar8 = g_TarzanFsdEntryCount;
    while ((uVar3 != uVar1 && (iVar4 < iVar8 + -1))) {
      if (uVar3 < uVar1) {
        iVar7 = iVar6 - iVar4;
        iVar5 = iVar4;
        iVar8 = iVar6;
      }
      else {
        iVar7 = iVar8 - iVar4;
        iVar5 = iVar6;
      }
      iVar6 = (iVar7 >> 1) + iVar4;
      uVar1 = (&g_TarzanFsdEntryTable)[iVar6 * 3];
      iVar4 = iVar5;
    }
    if (uVar3 != (&g_TarzanFsdEntryTable)[iVar6 * 3]) {
      DrawGraphicsTextinMem_2(local_400,s_FSYS_fopen___s___00515c08,param_1);
      InternalError(local_400);
    }
    (&g_TarzanFsdHandleOffsets)[iVar6] = 0;
    return iVar6 + 1;
  }
  iVar4 = FetchAndGetHwdForGameFile(param_1,param_2);
  if (iVar4 == 0) {
    DrawGraphicsTextinMem_2(local_400,s_FSYS_fopen___s___00515c08,param_1);
    InternalError(local_400);
  }
  return iVar4;
}


