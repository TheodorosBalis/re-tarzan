// Address: 0x00439400

void CompactModelHeapForAllocation(int param_1)

{
  int iVar1;
  
  iVar1 = GetModelHeapCompactionCandidate_Immediate(param_1);
  while (iVar1 != 0) {
    RelocateModelHeapBlockIntoFreeGap(*(undefined4 *)(param_1 + 8),param_1);
    iVar1 = GetModelHeapCompactionCandidate_FrameFiltered(param_1);
  }
  return;
}


