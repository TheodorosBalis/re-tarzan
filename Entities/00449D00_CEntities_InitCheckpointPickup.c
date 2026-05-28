
void CEntities__InitCheckpointPickup(int param_1)

{
  int iVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x34) == 0) {
    *(undefined4 *)(param_1 + 0x4c) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0x34) + 0x10);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(iVar1 + 8);
  }
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    iVar4 = CEntities__CreateRuntimeEntryAttachment(param_1,0x18,0x80000058);
    if (iVar4 != 0) {
      if (*(int *)(iVar1 + 0x108) == 1) {
        MoveSceneEntryWithCollision(0,0,iVar1);
        *(ushort *)(iVar1 + 0xa2) = *(ushort *)(iVar1 + 0x132) ^ 0x800;
        *(undefined2 *)(iVar4 + 0x12) = 0;
      }
      else {
        *(undefined2 *)(iVar4 + 0x12) = *(undefined2 *)(param_1 + 0x50);
        *(undefined4 *)(param_1 + 0x50) = 0;
      }
      *(int *)(iVar1 + 0x10) = g_WorldSceneEntryArrayBase + 0x3a8;
      if (g_CurrentCheckpointId == *(int *)(param_1 + 0x4c)) {
        *(undefined2 *)(iVar4 + 0xc) = 0;
        *(undefined2 *)(iVar4 + 0xe) = 0;
        *(undefined2 *)(iVar1 + 0xc) = g_CheckpointPickupActivationFrameSequence;
        *(undefined2 *)(param_1 + 0x48) = 9;
      }
      else {
        *(undefined2 *)(iVar1 + 0xc) = 0x1c;
        sVar2 = RandomModulo(0x100);
        *(short *)(iVar4 + 0xc) = sVar2 + 0x20;
        *(undefined2 *)(iVar4 + 0xe) = 0xffff;
        sVar2 = RandomModulo(0x46);
        *(short *)(iVar4 + 0x10) = sVar2 + 0x14;
        *(undefined2 *)(param_1 + 0x48) = 1;
      }
      *(undefined4 *)(iVar1 + 0xb4) = 1;
      uVar3 = *(ushort *)(iVar1 + 0x132) ^ 0x800;
      *(undefined2 *)(iVar1 + 0xa6) = 1;
      *(ushort *)(iVar1 + 0xa2) = uVar3;
      *(ushort *)(iVar4 + 0x16) = uVar3;
      iVar4 = (int)(short)(uVar3 + 0x400 & 0xfff);
      *(int *)(iVar1 + 0x3c) =
           (int)(short)(&g_SinCosTable12Bit)[iVar4 - 0x400U & 0xfff] * *(int *)(param_1 + 0x50) >>
           0xc;
      sVar2 = (&g_SinCosTable12Bit)[iVar4];
      iVar4 = *(int *)(param_1 + 0x50);
      *(short *)(iVar1 + 0xa2) = *(short *)(iVar1 + 0xa2) + -0x555;
      *(int *)(iVar1 + 0x44) = sVar2 * iVar4 >> 0xc;
      *(undefined4 *)(iVar1 + 0x40) = 0xffffff80;
    }
  }
  if ((*(byte *)(param_1 + 0x44) & 1) != 0) {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

