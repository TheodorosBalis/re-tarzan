// Address: 0x00439340

byte * GetModelHeapCompactionCandidate_Immediate(undefined4 param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)GetModelHeapCompactionCandidate_Stub(param_1);
  if ((pbVar1 != (byte *)0x0) && ((*pbVar1 & 2) != 0)) {
    pbVar1 = (byte *)0x0;
  }
  return pbVar1;
}


