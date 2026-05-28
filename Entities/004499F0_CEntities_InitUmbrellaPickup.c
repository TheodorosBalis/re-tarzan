
void CEntities__InitUmbrellaPickup(int param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x34) == 0) {
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x34) + 0x10) + 8)
    ;
  }
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    iVar3 = CEntities__CreateRuntimeEntryAttachment(param_1,0x18,0x80000058);
    if (iVar3 != 0) {
      if ((*(int *)(iVar1 + 0x108) == 1) && (*(int *)(g_PlayerSceneEntry + 0x108) == 1)) {
        MoveSceneEntryWithCollision(0,0,iVar1);
        *(ushort *)(iVar1 + 0xa2) = *(ushort *)(iVar1 + 0x132) ^ 0x800;
        *(undefined2 *)(iVar3 + 0x10) = 0;
      }
      else {
        *(undefined2 *)(iVar3 + 0x10) = *(undefined2 *)(param_1 + 0x50);
        *(undefined4 *)(param_1 + 0x50) = 0;
      }
      *(undefined4 *)(param_1 + 0x4c) = 0x3c;
      iVar4 = g_WorldSceneEntryArrayBase + 0x3a8;
      *(undefined2 *)(iVar1 + 0xc) = 0x2009;
      *(int *)(iVar1 + 0x10) = iVar4;
      *(undefined2 *)(param_1 + 0x48) = 1;
      *(undefined2 *)(iVar1 + 0xa6) = 1;
      uVar2 = *(ushort *)(iVar1 + 0x132) ^ 0x800;
      *(ushort *)(iVar1 + 0xa2) = uVar2;
      *(ushort *)(iVar3 + 0x14) = uVar2;
      iVar3 = (int)(short)(uVar2 + 0x400 & 0xfff);
      *(int *)(iVar1 + 0x3c) =
           (int)(short)(&g_SinCosTable12Bit)[iVar3 - 0x400U & 0xfff] * *(int *)(param_1 + 0x50) >>
           0xc;
      *(int *)(iVar1 + 0x44) =
           (int)(short)(&g_SinCosTable12Bit)[iVar3] * *(int *)(param_1 + 0x50) >> 0xc;
    }
  }
  if ((*(byte *)(param_1 + 0x44) & 1) != 0) {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

