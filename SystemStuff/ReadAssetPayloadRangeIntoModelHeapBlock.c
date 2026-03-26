// Address: 0x004AC160

undefined4 ReadAssetPayloadRangeIntoModelHeapBlock(int param_1,int param_2,int param_3,int param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if ((((param_1 != 0) && (param_3 != 0)) &&
      (pcVar1 = *(char **)(param_1 + 8), pcVar1 != (char *)0x0)) && (*pcVar1 != '\0')) {
    uVar2 = CopyVirtualGameFileRangeIntoBuffer(pcVar1,param_3,param_2 << 0xb,param_4 << 0xb);
    return uVar2;
  }
  return 0xffffffff;
}


