// Address: 0x0040A950

void InitSceneAnchorTransform(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  DAT_0051c4c0 = 0;
  param_1[0x31] = param_2;
  *(undefined2 *)(param_1 + 0x14) = 0;
  *(undefined2 *)((int)param_1 + 0x52) = 0;
  *(undefined2 *)(param_1 + 0x15) = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0x16] = 0x1000;
  param_1[0x17] = 0x1000;
  param_1[0x18] = 0x1000;
  param_1[5] = 0x300;
  param_1[8] = 0x140;
  *(undefined2 *)((int)param_1 + 0x56) = 0;
  param_1[0x19] = 0;
  FUN_0040a900(param_1);
  iVar1 = param_1[0x16] * 4 * param_1[8];
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  *(undefined2 *)(param_1 + 0xc) = 0;
  *(undefined2 *)((int)param_1 + 0x32) = 0;
  *(undefined2 *)(param_1 + 0xd) = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[5] = (int)(iVar1 + (iVar1 >> 0x1f & 0xfffU)) >> 0xc;
  param_1[0x2c] = 0x1000;
  return;
}


