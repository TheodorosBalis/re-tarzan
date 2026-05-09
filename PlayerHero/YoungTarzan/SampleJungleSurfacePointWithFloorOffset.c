// 0x00448960

void SampleJungleSurfacePointWithFloorOffset(int param_1,int *param_2,int *param_3)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = param_2[3];
  if (iVar8 == param_1) {
    *param_3 = *param_2;
    param_3[1] = param_2[1];
    param_3[2] = param_2[2];
    if (*(short *)((int)param_2 + 0x12) != 0) {
      param_3[3] = param_2[1] - (int)*(short *)((int)param_2 + 0x12);
      goto LAB_00448a3d;
    }
  }
  else {
    iVar7 = param_1 - iVar8;
    iVar8 = param_2[10] - iVar8;
    iVar6 = ((param_2[8] - param_2[1]) * iVar7) / iVar8;
    iVar3 = param_2[2];
    iVar4 = param_2[9];
    sVar1 = *(short *)((int)param_2 + 0x12);
    sVar2 = *(short *)((int)param_2 + 0x2e);
    *param_3 = ((param_2[7] - *param_2) * iVar7) / iVar8 + *param_2;
    param_3[1] = param_2[1] + iVar6;
    param_3[2] = ((iVar4 - iVar3) * iVar7) / iVar8 + param_2[2];
    if ((*(short *)((int)param_2 + 0x12) != 0) && (*(short *)((int)param_2 + 0x2e) != 0)) {
      param_3[3] = ((param_2[1] - (int)*(short *)((int)param_2 + 0x12)) -
                   (((int)sVar2 - (int)sVar1) * iVar7) / iVar8) + iVar6;
      goto LAB_00448a3d;
    }
  }
  param_3[3] = -0x7fffffff;
LAB_00448a3d:
  uVar5 = param_2[5];
  if (((uVar5 & 0x100) != 0) &&
     (((uVar5 & 0xc000) == 0x4000 ||
      ((((uVar5 & 0xc000) == 0x8000 && ((uVar5 & 0x80) == 0)) || (param_1 != param_2[3])))))) {
    param_3[1] = 0x3ffffffe;
  }
  return;
}