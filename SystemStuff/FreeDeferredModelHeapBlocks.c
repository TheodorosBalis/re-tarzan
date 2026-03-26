// Address: 0x00439360

void FreeDeferredModelHeapBlocks(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *(int *)(param_1 + 0xc);
  while (iVar1 != 0) {
    *(short *)(iVar1 + 2) = *(short *)(iVar1 + 2) + -1;
    if (*(short *)(iVar1 + 2) < 1) {
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar1 + 0x14);
      }
      else {
        *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
      }
      FreeModelHeapBlock(iVar1 + 0x18,&g_ModelLoadHeapState);
      if (iVar2 == 0) break;
      iVar1 = *(int *)(iVar2 + 0x14);
    }
    else {
      iVar2 = iVar1;
      iVar1 = *(int *)(iVar1 + 0x14);
    }
  }
  iVar1 = GetModelHeapCompactionCandidate_FrameFiltered(param_1);
  iVar2 = 0x70;
  while( true ) {
    if (iVar1 == 0) {
      return;
    }
    iVar2 = iVar2 - *(int *)(iVar1 + 8);
    if (iVar2 < 1) break;
    g_ModelHeapCompactedWordsThisTick = g_ModelHeapCompactedWordsThisTick + *(int *)(iVar1 + 8);
    RelocateModelHeapBlockIntoFreeGap(*(undefined4 *)(param_1 + 8),param_1);
    iVar1 = GetModelHeapCompactionCandidate_FrameFiltered(param_1);
  }
  return;
}


