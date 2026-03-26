// Address: 0x00439240

void RelocateModelHeapBlockIntoFreeGap(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  UnlinkModelHeapFreeBlock(param_1,param_2);
  iVar2 = param_1[2];
  puVar6 = param_1 + 6;
  puVar1 = param_1 + iVar2 + 6;
  iVar3 = puVar1[2];
  puVar7 = puVar1 + 6;
  uVar4 = param_1[3];
  puVar8 = puVar1;
  puVar9 = param_1;
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  param_1[3] = uVar4;
  *(undefined4 **)param_1[1] = puVar6;
  for (iVar5 = iVar3; iVar5 != 0; iVar5 = iVar5 + -1) {
    uVar4 = *puVar7;
    puVar7 = puVar7 + 1;
    *puVar6 = uVar4;
    puVar6 = puVar6 + 1;
  }
  puVar6 = param_1 + param_1[2] + 6;
  puVar1[iVar3 + 9] = puVar6;
  puVar6[2] = iVar2;
  puVar6[1] = 0xffffffff;
  *(undefined2 *)puVar6 = 0;
  puVar6[3] = param_1;
  if (param_1 == *(undefined4 **)(param_2 + 8)) {
    uVar4 = FindNextModelHeapCompactionCursor(puVar6);
    *(undefined4 *)(param_2 + 8) = uVar4;
  }
  FreeModelHeapBlock(puVar6 + 6,param_2);
  return;
}


