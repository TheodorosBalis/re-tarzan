// 0x004399c0

int FindNatureTerrainCellIndexAtGridCoords(int *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = *param_2;
  do {
    uVar2 = uVar1 & 3;
    if (uVar2 == 0) {
      return (int)*param_2 >> 2;
    }
    iVar3 = (int)uVar1 >> 2;
    if (uVar2 == 1) {
      if (*param_1 < iVar3) {
LAB_00439a0f:
        param_2 = (uint *)((int)param_2 + param_2[2] + 8);
      }
      else {
        param_2 = (uint *)((int)param_2 + param_2[1] + 4);
      }
    }
    else if (uVar2 == 2) {
      if (param_1[1] < iVar3) goto LAB_00439a0f;
      param_2 = (uint *)((int)param_2 + param_2[1] + 4);
    }
    else if (uVar2 == 3) {
      if (param_1[2] < iVar3) goto LAB_00439a0f;
      param_2 = (uint *)((int)param_2 + param_2[1] + 4);
    }
    uVar1 = *param_2;
  } while( true );
}