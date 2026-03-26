// Address: 0x00439660

undefined2 * AllocModelHeapBlock(undefined4 param_1,undefined4 param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)AllocModelHeapBlockHeader(param_1,param_2);
  if (puVar1 == (undefined2 *)0x0) {
    CompactModelHeapForAllocation(param_2);
    puVar1 = (undefined2 *)AllocModelHeapBlockHeader(param_1,param_2);
    if (puVar1 == (undefined2 *)0x0) {
      InternalError(s_mal_perm___004ed428);
      UpdateModelHeapStats();
      return (undefined2 *)0x0;
    }
  }
  *(undefined4 *)(puVar1 + 2) = 0xffffffff;
  *puVar1 = 0;
  return puVar1 + 0xc;
}


