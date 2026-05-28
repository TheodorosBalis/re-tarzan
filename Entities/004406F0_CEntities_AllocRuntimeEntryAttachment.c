
undefined4 *
CEntities__AllocRuntimeEntryAttachment
          (int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = param_2 + 3U & 0xfffffffc;
  uVar7 = param_2 + 0x1bU & 0xfffffffc;
  iVar1 = g_RuntimeEntryAttachmentFreeBlockHead;
  while( true ) {
    if (iVar1 == 0) {
      *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 1;
      return (undefined4 *)0x0;
    }
    uVar6 = *(uint *)(iVar1 + 0x10) & 0xfffffffc;
    if ((int)uVar8 <= (int)uVar6) break;
    iVar1 = *(int *)(iVar1 + 0xc);
  }
  if ((int)(uVar7 + 8) < (int)uVar6) {
    puVar2 = *(undefined4 **)(iVar1 + 4);
    piVar5 = (int *)(iVar1 + uVar7);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = piVar5;
    }
    piVar5[1] = (int)puVar2;
    *piVar5 = iVar1;
    *(int **)(iVar1 + 4) = piVar5;
    *(uint *)(iVar1 + 0x10) = uVar8;
    piVar5[4] = uVar6 - uVar7 | 1;
    iVar3 = *(int *)(iVar1 + 8);
    piVar5[2] = iVar3;
    if (iVar3 != 0) {
      *(int **)(iVar3 + 0xc) = piVar5;
    }
    iVar3 = *(int *)(iVar1 + 0xc);
    piVar5[3] = iVar3;
    if (iVar3 != 0) {
      *(int **)(iVar3 + 8) = piVar5;
    }
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  else {
    *(uint *)(iVar1 + 0x10) = uVar6;
    *(undefined4 *)(*(int *)(iVar1 + 8) + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    if (*(int *)(*(int *)(iVar1 + 8) + 0xc) != 0) {
      *(int *)(*(int *)(iVar1 + 0xc) + 8) = *(int *)(iVar1 + 8);
    }
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  *(int *)(iVar1 + 0x14) = param_1;
  iVar3 = *(int *)(param_1 + 8);
  while (iVar4 = iVar3, iVar4 != 0) {
    param_1 = iVar4;
    iVar3 = *(int *)(iVar4 + 8);
  }
  puVar2 = (undefined4 *)(iVar1 + 0x18);
  if (param_4 == (undefined4 *)0x0) {
    *puVar2 = param_3;
    *(int *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 **)(param_1 + 8) = puVar2;
    return puVar2;
  }
  *param_4 = param_3;
  param_4[1] = param_1;
  *(undefined4 **)(param_1 + 8) = puVar2;
  return puVar2;
}

