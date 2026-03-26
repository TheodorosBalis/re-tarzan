// Address: 0x004A2C00

void MultiplyBasisMatrices(short *param_1,short *param_2,undefined4 *param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  
  iVar5 = (int)param_1[2];
  iVar9 = (int)*param_1;
  iVar13 = (int)param_2[3];
  iVar16 = (int)param_1[1];
  iVar6 = (int)param_2[6];
  iVar17 = (int)param_1[5];
  iVar10 = (int)param_1[4];
  iVar18 = (int)param_1[3];
  sVar1 = *param_2;
  iVar11 = (int)param_1[8];
  iVar12 = (int)param_1[7];
  iVar2 = (int)param_1[6];
  iVar14 = (int)param_2[4];
  iVar3 = (int)param_2[1];
  iVar7 = (int)param_2[7];
  iVar15 = (int)param_2[5];
  iVar8 = (int)param_2[8];
  iVar4 = (int)param_2[2];
  *param_3 = CONCAT22((short)(iVar3 * iVar9 + iVar14 * iVar16 + iVar7 * iVar5 >> 0xc),
                      (short)(*param_2 * iVar9 + iVar13 * iVar16 + iVar6 * iVar5 >> 0xc));
  param_3[1] = CONCAT22((short)(iVar18 * sVar1 + iVar10 * iVar13 + iVar17 * iVar6 >> 0xc),
                        (short)(iVar4 * iVar9 + iVar15 * iVar16 + iVar8 * iVar5 >> 0xc));
  param_3[2] = CONCAT22((short)(iVar4 * iVar18 + iVar15 * iVar10 + iVar8 * iVar17 >> 0xc),
                        (short)(iVar3 * iVar18 + iVar14 * iVar10 + iVar7 * iVar17 >> 0xc));
  param_3[3] = CONCAT22((short)(iVar3 * iVar2 + iVar14 * iVar12 + iVar7 * iVar11 >> 0xc),
                        (short)(iVar2 * sVar1 + iVar12 * iVar13 + iVar11 * iVar6 >> 0xc));
  *(short *)(param_3 + 4) = (short)(iVar4 * iVar2 + iVar15 * iVar12 + iVar8 * iVar11 >> 0xc);
  return;
}


