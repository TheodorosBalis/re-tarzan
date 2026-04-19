// 004acbf0

void UpdateSceneEntryFrameIndexAnimation(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_2 + 4) + *param_1 * 0x26;
  uVar2 = param_1[2] + param_1[1];
  param_1[2] = uVar2;
  if (param_1[1] < 1) {
    if (-1 < (int)(uVar2 & 0xffffff00)) goto LAB_004acc54;
    uVar3 = (uint)*(ushort *)(iVar1 + 4) * 0x100 + (uVar2 & 0xffffff00);
  }
  else {
    if ((int)uVar2 >> 8 < (int)(uint)*(ushort *)(iVar1 + 4)) goto LAB_004acc54;
    uVar3 = (uVar2 & 0xffffff00) + (uint)*(ushort *)(iVar1 + 4) * -0x100;
  }
  param_1[2] = uVar3 ^ uVar2 & 0xff;
LAB_004acc54:
  *(char *)(iVar1 + 0x15) = (char)((uint)param_1[2] >> 8);
  return;
}