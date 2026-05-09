int GetJungleSurfaceLateralLimit(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    return 0;
  }
  if ((*(uint *)(param_2 + 0x14) & 0x2000) != 0) {
    return (int)*(short *)(param_2 + 0x10);
  }
  iVar1 = *(int *)(param_2 + 0x28) - *(int *)(param_2 + 0xc);
  if (iVar1 == 0) {
    return (int)*(short *)(param_2 + 0x10);
  }
  return (((int)*(short *)(param_2 + 0x2c) - (int)*(short *)(param_2 + 0x10)) *
         (param_1 - *(int *)(param_2 + 0xc))) / iVar1 + (int)*(short *)(param_2 + 0x10);
}