// Address: 0x00439310

ushort * GetModelHeapCompactionCandidate_FrameFiltered(undefined4 param_1)

{
  ushort *puVar1;
  
  puVar1 = (ushort *)GetModelHeapCompactionCandidate_Stub(param_1);
  if (((puVar1 != (ushort *)0x0) && ((*puVar1 & 2) != 0)) && ((*puVar1 & 1) == (FrameCount & 1))) {
    puVar1 = (ushort *)0x0;
  }
  return puVar1;
}


