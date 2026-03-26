// Address: 0x004A2540

void BuildBasisMatrixFromEulerAngles(short *param_1,short *param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short sVar9;
  int iVar10;
  
  sVar1 = (&DAT_0077c788)[(int)*param_1 - 0x400U & 0xfff];
  iVar8 = (int)sVar1;
  sVar2 = (&DAT_0077c788)[(int)*param_1 & 0xfff];
  iVar10 = (int)sVar2;
  sVar3 = (&DAT_0077c788)[(int)param_1[1] & 0xfff];
  iVar7 = (int)sVar3;
  sVar4 = (&DAT_0077c788)[(int)param_1[1] - 0x400U & 0xfff];
  iVar5 = (int)(short)(&DAT_0077c788)[(int)param_1[2] & 0xfff];
  iVar6 = (int)(short)(&DAT_0077c788)[(int)param_1[2] - 0x400U & 0xfff];
  param_2[5] = (short)(-(iVar7 * iVar8) >> 0xc);
  param_2[2] = sVar4;
  param_2[8] = (short)(iVar7 * iVar10 >> 0xc);
  sVar9 = (short)(sVar4 * iVar8 >> 0xc);
  param_2[3] = sVar9;
  sVar4 = (short)(-(sVar4 * iVar10) >> 0xc);
  param_2[6] = sVar4;
  if (param_1[2] == 0) {
    param_2[4] = sVar2;
    *param_2 = sVar3;
    param_2[1] = 0;
    param_2[7] = sVar1;
    return;
  }
  *param_2 = (short)(iVar5 * iVar7 >> 0xc);
  param_2[1] = (short)(-(iVar6 * iVar7) >> 0xc);
  param_2[4] = (short)(iVar5 * iVar10 - sVar9 * iVar6 >> 0xc);
  param_2[3] = (short)(sVar9 * iVar5 + iVar6 * iVar10 >> 0xc);
  param_2[7] = (short)(iVar5 * iVar8 - sVar4 * iVar6 >> 0xc);
  param_2[6] = (short)(sVar4 * iVar5 + iVar6 * iVar8 >> 0xc);
  return;
}


