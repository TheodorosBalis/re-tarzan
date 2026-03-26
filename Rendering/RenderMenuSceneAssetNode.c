// Address: 0x004450A0

void RenderMenuSceneAssetNode(ushort *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)*param_1;
  if ((uVar1 & 0x7000) == 0x5000) {
    iVar2 = *(int *)(*(int *)(param_1 + 2) + 0xc);
    iVar2 = FUN_0043a2d0(*(int *)(iVar2 + 0x10) + (uVar1 & 0xfff) * 8 + 0x14 + iVar2);
    if (iVar2 != 0) {
      FUN_004aa830(iVar2,param_1[1]);
      return;
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 2) + 0xc);
    if ((int)(uVar1 & 0xfff) < *(int *)(iVar2 + 0x30)) {
      FUN_004aa830((uVar1 & 0xfff) * 0x30 + 0x34 + iVar2,param_1[1]);
    }
  }
  return;
}


