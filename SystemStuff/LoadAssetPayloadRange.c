// Address: 0x004294F0

undefined4 LoadAssetPayloadRange(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  g_AssetPayloadLoadResultBlock = 0;
  EnqueueModelLoadRequest(param_1,param_2,param_3,0,&g_AssetPayloadLoadResultBlock,0);
  iVar1 = ProcessModelLoadQueue();
  while (iVar1 != 0) {
    CompactModelHeapFully(&g_ModelLoadHeapState);
    iVar1 = ProcessModelLoadQueue();
  }
  return g_AssetPayloadLoadResultBlock;
}


