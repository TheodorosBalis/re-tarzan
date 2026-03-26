// Address: 0x004A2B10

void ScaleBasisAxesClamped(short *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if (iVar1 < 0x4000) {
    if (iVar1 < -0x3fff) {
      iVar1 = -0x3fff;
    }
  }
  else {
    iVar1 = 0x3fff;
  }
  *param_1 = (short)(*param_1 * iVar1 >> 0xc);
  param_1[1] = (short)(param_1[1] * iVar1 >> 0xc);
  param_1[2] = (short)(param_1[2] * iVar1 >> 0xc);
  iVar1 = param_2[1];
  if (iVar1 < 0x4000) {
    if (iVar1 < -0x3fff) {
      iVar1 = -0x3fff;
    }
  }
  else {
    iVar1 = 0x3fff;
  }
  param_1[3] = (short)(param_1[3] * iVar1 >> 0xc);
  param_1[4] = (short)(param_1[4] * iVar1 >> 0xc);
  param_1[5] = (short)(param_1[5] * iVar1 >> 0xc);
  iVar1 = param_2[2];
  if (iVar1 < 0x4000) {
    if (iVar1 < -0x3fff) {
      iVar1 = -0x3fff;
    }
  }
  else {
    iVar1 = 0x3fff;
  }
  param_1[6] = (short)(param_1[6] * iVar1 >> 0xc);
  param_1[7] = (short)(param_1[7] * iVar1 >> 0xc);
  param_1[8] = (short)(param_1[8] * iVar1 >> 0xc);
  return;
}


