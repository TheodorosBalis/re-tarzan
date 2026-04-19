// 0x004acc60

void UpdateSceneEntryFramePointerAnimation(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_2 + 4);
  uVar2 = param_1[4] + param_1[3];
  param_1[4] = uVar2;
  if (param_1[3] < 0) {
    if (-1 < (int)(uVar2 & 0xffffff00)) goto LAB_004accc0;
    uVar3 = param_1[2] * 0x100 + (uVar2 & 0xffffff00);
  }
  else {
    if ((int)uVar2 >> 8 < param_1[2]) goto LAB_004accc0;
    uVar3 = (uVar2 & 0xffffff00) + param_1[2] * -0x100;
  }
  param_1[4] = uVar3 ^ uVar2 & 0xff;
LAB_004accc0:
  *(undefined4 *)(iVar1 + param_1[1] * 0x26 + 0x1e) =
       *(undefined4 *)(*param_1 + (param_1[4] >> 8) * 4 + (int)param_1);
  return;
}