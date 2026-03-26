// Address: 0x004A2420

void TransformVectorByBasis(short *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_004a22d0(param_1);
  iVar1 = *param_2;
  iVar2 = param_2[1];
  iVar3 = param_2[2];
  *param_3 = param_1[2] * iVar3 + param_1[1] * iVar2 + *param_1 * iVar1 >> 0xc;
  param_3[1] = param_1[5] * iVar3 + param_1[4] * iVar2 + param_1[3] * iVar1 >> 0xc;
  param_3[2] = param_1[8] * iVar3 + param_1[7] * iVar2 + param_1[6] * iVar1 >> 0xc;
  return;
}


