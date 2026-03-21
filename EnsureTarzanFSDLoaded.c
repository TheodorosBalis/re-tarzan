/* Address: 0x0049A2D0 */

void EnsureTarzanFSDLoaded(void)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  uint *puVar4;
  DWORD DVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  char *pcVar12;
  CHAR local_400 [1024];
  
  if (DAT_007222d8 == 0) {
    puVar8 = &TarzanFSDBuffer;
    for (iVar6 = 0x1800; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    DAT_007222d4 = 0;
    puVar8 = &DAT_0071feb0;
    for (iVar6 = 0x800; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar8 = 0xffffffff;
      puVar8 = puVar8 + 1;
    }
    DAT_007222cc = 0;
    DAT_007222d0 = 0;
    DVar5 = GetModuleFileNameA((HMODULE)0x0,local_400,0x400);
    if (DVar5 == 0) {
      InternalError(s_FSYS_Init_1__00515bf8);
    }
    uVar7 = 0xffffffff;
    pcVar12 = local_400;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    local_400[~uVar7 - 4] = 'f';
    uVar7 = 0xffffffff;
    pcVar12 = local_400;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    local_400[~uVar7 - 3] = 's';
    uVar7 = 0xffffffff;
    pcVar12 = local_400;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    local_400[~uVar7 - 2] = 'd';
    DAT_007222cc = FetchAndGetHwdForGameFile(local_400,&DAT_005156bc);
    if (DAT_007222cc != 0) {
      DAT_007222d4 = 1;
      iVar6 = LoadGameFileInBuffer(&TarzanFSDBuffer,0x6000,1,DAT_007222cc);
      if (iVar6 != 1) {
        InternalError(s_FSYS_Init_2__00515be8);
      }
      iVar6 = 0;
      DAT_007222d0 = 0;
      if (TarzanFSDBuffer != 0) {
        puVar8 = &TarzanFSDBuffer;
        do {
          DAT_007222d0 = iVar6;
          if (0x71feaf < (int)puVar8) break;
          piVar1 = puVar8 + 3;
          puVar8 = puVar8 + 3;
          iVar6 = iVar6 + 1;
          DAT_007222d0 = iVar6;
        } while (*piVar1 != 0);
      }
      if (0 < DAT_007222d0) {
        puVar10 = (uint *)&TarzanFSDBuffer;
        iVar6 = DAT_007222d0;
        iVar9 = 1;
        do {
          iVar11 = iVar9;
          puVar4 = puVar10;
          if (iVar9 < iVar6) {
            do {
              if (puVar4[3] <= *puVar10) {
                InternalError(s_FSYS_Init_3__00515bd8);
                iVar6 = DAT_007222d0;
              }
              iVar11 = iVar11 + 1;
              puVar4 = puVar4 + 3;
            } while (iVar11 < iVar6);
          }
          puVar10 = puVar10 + 3;
          bVar3 = iVar9 < iVar6;
          iVar9 = iVar9 + 1;
        } while (bVar3);
      }
    }
    DAT_007222d8 = 1;
  }
  return;
}

