// Address: 0x00429600

undefined4 LoadAssetPayloadIntoBoundHandle(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = GetAssetPayloadSizeByPath(param_1);
  LoadAssetPayloadRangeIntoBoundHandle(param_1,0,param_2,uVar1);
  return uVar1;
}


