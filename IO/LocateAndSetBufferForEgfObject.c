/* Address: 0x0049A480 */

int LocateAndSetBufferForEgfObject(undefined4 param_1,undefined4 param_2)

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
  
  if (DAT_007222d4 != 0) {
    uVar2 = LocateMenuEgfFile(param_1);
    uVar3 = AppendMenuEgfPath(uVar2);
    iVar6 = DAT_007222d0 >> 1;
    uVar1 = (&TarzanFSDBuffer)[iVar6 * 3];
    iVar4 = 0;
    iVar8 = DAT_007222d0;
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
      uVar1 = (&TarzanFSDBuffer)[iVar6 * 3];
      iVar4 = iVar5;
    }
    if (uVar3 != (&TarzanFSDBuffer)[iVar6 * 3]) {
      DrawGraphicsTextinMem_2(local_400,s_FSYS_fopen_::s::_00515c08,param_1);
      InternalError(local_400);
    }
    (&DAT_0071feb0)[iVar6] = 0;
    return iVar6 + 1;
  }
  iVar4 = FetchAndGetHwdForGameFile(param_1,param_2);
  if (iVar4 == 0) {
    DrawGraphicsTextinMem_2(local_400,s_FSYS_fopen_::s::_00515c08,param_1);
    InternalError(local_400);
  }
  return iVar4;
}

