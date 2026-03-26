// Address: 0x0049A960

undefined * LoadECMfile(char *param_1)

{
  char cVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  undefined4 *puVar9;
  char *pcVar10;
  
  if (DAT_00515ad4 != '\0') {
    puVar9 = (undefined4 *)&DAT_00721eb0;
    for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    DAT_00515ad4 = '\0';
    *(undefined2 *)puVar9 = 0;
    DVar2 = GetLogicalDrives();
    if ((DVar2 & 1) != 0) {
      iVar4 = (int)DAT_007222f1;
      DAT_007222f1 = DAT_007222f1 + '\x01';
      (&DAT_00721eb0)[iVar4] = 0x2e;
    }
  }
  uVar5 = 0xffffffff;
  pcVar8 = &DAT_00515c40;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  uVar6 = 0xffffffff;
  do {
    pcVar8 = param_1;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar8 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar8;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar8 = pcVar8 + -uVar6;
  pcVar10 = &DAT_00515ad7 + ~uVar5;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar10 = pcVar10 + 4;
  }
  DAT_007222f0 = 0x2e;
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar10 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar10 = pcVar10 + 1;
  }
  DAT_00515ad8 = 0x2e;
  iVar4 = GetFileAttributes(&DAT_00515ad8,0);
  if (iVar4 != 0) {
    iVar4 = 0;
    if ('\0' < DAT_007222f1) {
      do {
        DAT_00515ad8 = (&DAT_00721eb0)[iVar4];
        DAT_007222f0 = DAT_00515ad8;
        iVar3 = GetFileAttributes(&DAT_00515ad8,0);
        if (iVar3 == 0) goto LAB_0049aa33;
        iVar4 = iVar4 + 1;
      } while (iVar4 < DAT_007222f1);
    }
    return (undefined *)0x0;
  }
LAB_0049aa33:
  return &DAT_00515ad8;
}


