// Address: 0x004AC130

undefined4 GetAssetPayloadSizeByPath(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (((param_1 != 0) && (pcVar1 = *(char **)(param_1 + 8), pcVar1 != (char *)0x0)) &&
     (*pcVar1 != '\0')) {
    uVar2 = GetVirtualGameFileSizeByPath(pcVar1);
    return uVar2;
  }
  return 0xffffffff;
}


