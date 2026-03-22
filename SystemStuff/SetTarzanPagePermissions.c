/* Address: 0x004A2050 */

void SetTarzanPagePermissions(void)

{
  char cVar1;
  int iVar2;
  UINT UVar3;
  HMODULE pHVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  CHAR local_8;
  char local_7 [7];
  
  if (DAT_0077c780 == 0) {
    DAT_0077c780 = 1;
    GetModuleFileNameA((HMODULE)0x0,&local_8,2);
    uVar6 = 0xffffffff;
    pcVar9 = &DAT_005175ec;
    do {
      pcVar10 = pcVar9;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar10 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar10;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar9 = pcVar10 + -uVar6;
    pcVar10 = local_7;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar10 = pcVar10 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar10 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar10 = pcVar10 + 1;
    }
    UVar3 = GetDriveTypeA(&local_8);
    if ((UVar3 == 3) && (pHVar4 = GetModuleHandleA((LPCSTR)0x0), ((uint)pHVar4 & 0x80000000) == 0))
    {
      iVar2 = pHVar4[0xf].unused;
      SetPageProtectionsForTarzan(pHVar4,*(undefined4 *)((int)&pHVar4[0x15].unused + iVar2));
      uVar6 = 0;
      if (*(short *)((int)&pHVar4[1].unused + iVar2 + 2) != 0) {
        iVar8 = 0;
        do {
          iVar5 = (uint)*(ushort *)((int)&pHVar4[5].unused + iVar2) + iVar8;
          SetPageProtectionsForTarzan
                    ((int)&pHVar4->unused + *(int *)((int)&pHVar4[9].unused + iVar2 + iVar5),
                     *(undefined4 *)((int)&pHVar4[8].unused + iVar2 + iVar5));
          uVar6 = uVar6 + 1;
          iVar8 = iVar8 + 0x28;
        } while (uVar6 < *(ushort *)((int)&pHVar4[1].unused + iVar2 + 2));
      }
    }
  }
  return;
}

