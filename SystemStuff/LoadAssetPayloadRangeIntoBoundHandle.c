// Address: 0x004295A0

undefined4
LoadAssetPayloadRangeIntoBoundHandle
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  g_BoundAssetPayloadLoadResultBlock = 0;
  EnqueueModelLoadRequest(param_1,param_2,param_4,0,&g_BoundAssetPayloadLoadResultBlock,1);
  iVar1 = ProcessModelLoadQueue();
  while (iVar1 != 0) {
    CompactModelHeapFully(&g_ModelLoadHeapState);
    iVar1 = ProcessModelLoadQueue();
  }
  BindModelHeapBlockHandle(g_BoundAssetPayloadLoadResultBlock,param_3);
  return 0;
}


