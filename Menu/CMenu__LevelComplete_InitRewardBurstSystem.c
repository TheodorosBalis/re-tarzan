// Address: 0x0045E550

void CMenu__LevelComplete_InitRewardBurstSystem(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  *param_1 = 300;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1 = param_1 + 7;
  iVar3 = 0x30;
  do {
    InitLoadGamePreviewTransform(param_1);
    *(undefined2 *)((int)param_1 + 0xe) = 0x8521;
    param_1[4] = &LevelCompleteObjects;
    *(undefined2 *)(param_1 + 3) = 0x200c;
    param_1[0x15] = *param_2;
    param_1[0x16] = param_2[1];
    param_1[0x17] = param_2[2];
    iVar1 = RandomModulo(0x400);
    param_1[0x51] = iVar1 + -0x200;
    iVar1 = RandomModulo(0x280);
    param_1[0x52] = 0x80 - iVar1;
    iVar1 = RandomModulo(0x400);
    param_1[0x53] = iVar1 + -0x200;
    iVar1 = RandomModulo(0x200);
    param_1[0x54] = iVar1 + 0x80;
    iVar1 = RandomModulo(0xc00);
    param_1[0x55] = iVar1 + 0x400;
    uVar2 = RandomModulo(0x1000);
    param_1[0x56] = uVar2;
    uVar2 = RandomModulo(0x200);
    param_1[0x57] = uVar2;
    param_1[0xc] = param_1[0x55];
    iVar1 = RandomModulo(0x100);
    param_1[5] = iVar1 + -0x80;
    iVar1 = RandomModulo(0x100);
    param_1[6] = iVar1 + -0x80;
    iVar1 = RandomModulo(0x100);
    *(undefined2 *)((int)param_1 + 0xa6) = 0;
    param_1[7] = iVar1 + 0x80;
    uVar2 = param_1[0x54];
    *(undefined2 *)(param_1 + 0x28) = 0;
    *(undefined2 *)((int)param_1 + 0xa2) = 0;
    *(undefined2 *)(param_1 + 0x29) = 0;
    param_1[0x2d] = 1;
    param_1[0x2a] = uVar2;
    param_1[0x2b] = uVar2;
    param_1[0x2c] = uVar2;
    param_1 = param_1 + 0x58;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


