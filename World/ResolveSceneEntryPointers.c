void ResolveSceneEntryPointers(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1;
  iVar3 = *(int *)(*(int *)(iVar2 + 0xc) + 0xc) + 0xc + *(int *)(iVar2 + 0xc);
  param_1[7] = iVar3;
  iVar1 = param_1[6] * 4 + 4;
  iVar3 = *(int *)(iVar1 + iVar3) + iVar1 + iVar3;
  param_1[8] = iVar3;
  param_1[9] = *(int *)(iVar3 + 0x34) + 0x34 + iVar3;
  param_1[10] = *(int *)(iVar3 + 0xc) + 0xc + iVar3;
  param_1[0xf] = *(int *)(iVar3 + 0x10) + 0x10 + iVar3;
  param_1[0xb] = *(int *)(iVar3 + 0x18) + 0x18 + iVar3;
  param_1[0xc] = *(int *)(*(int *)(iVar2 + 0xc) + 0x10) + 0x10 + *(int *)(iVar2 + 0xc);
  param_1[0xd] = *(int *)(*(int *)(iVar2 + 0xc) + 8) + 0x10 + *(int *)(iVar2 + 0xc);
  iVar1 = *(int *)(*(int *)(iVar2 + 0xc) + 0x24) + 0x28 + *(int *)(iVar2 + 0xc);
  param_1[0xe] = iVar1;
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar2 + 0xc);
  return;
}