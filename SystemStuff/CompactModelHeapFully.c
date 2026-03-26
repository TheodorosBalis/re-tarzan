// Address: 0x00439430

void CompactModelHeapFully(int param_1)

{
  int iVar1;
  
  iVar1 = GetModelHeapCompactionCandidate_Stub(param_1);
  while (iVar1 != 0) {
    RelocateModelHeapBlockIntoFreeGap(*(undefined4 *)(param_1 + 8),param_1);
    iVar1 = GetModelHeapCompactionCandidate_Stub(param_1);
  }
  return;
}


