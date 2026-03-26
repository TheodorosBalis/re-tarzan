// Address: 0x00429540

undefined4 LoadAssetPayload(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = GetAssetPayloadSizeByPath(param_1);
  if (iVar1 == -1) {
    return 0;
  }
  uVar2 = LoadAssetPayloadRange(param_1,0,iVar1);
  return uVar2;
}


