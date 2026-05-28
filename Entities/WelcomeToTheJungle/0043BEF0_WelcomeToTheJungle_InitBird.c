
void WelcomeToTheJungle__InitBird(int param_1)

{
  int iVar1;
  int iVar2;
  
  WelcomeToTheJungle__InitBirdCommon(param_1);
  iVar1 = FindRuntimeEntityAttachmentByFlags(param_1,0x10000000);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x16) = 10;
    *(undefined2 *)(iVar1 + 0x10) = 0x28;
    *(undefined2 *)(iVar1 + 0x14) = 0x28;
    *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) | 1;
    iVar2 = RandomModulo(0xfa);
    *(int *)(param_1 + 0x4c) = iVar2 + 100;
    if ((*(byte *)(param_1 + 0x4a) & 0x20) != 0) {
      *(undefined2 *)(iVar1 + 0x16) = 0;
    }
    if ((*(byte *)(param_1 + 0x4b) & 2) != 0) {
      *(undefined4 *)(iVar1 + 0x24) = 10;
      *(undefined2 *)(iVar1 + 0x22) = 1000;
    }
    if ((*(int *)(param_1 + 0x34) != 0) &&
       (*(int *)(*(int *)(*(int *)(param_1 + 0x34) + 0x10) + 4) == 0x10)) {
      *(undefined2 *)(iVar1 + 0x10) = 0x32;
      *(undefined2 *)(iVar1 + 0x14) = 0x32;
    }
  }
  return;
}

