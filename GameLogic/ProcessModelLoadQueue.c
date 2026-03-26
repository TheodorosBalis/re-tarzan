// Address: 0x00429660

int ProcessModelLoadQueue(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (g_ModelLoadQueueCooldownTicks != 0) {
    g_ModelLoadQueueCooldownTicks = g_ModelLoadQueueCooldownTicks + -1;
    return g_ModelLoadQueuePendingCount + 1;
  }
  if (g_ModelLoadQueueInFlightBlock != 0) {
    iVar1 = PollModelLoadQueueIoStatus_Stub();
    if (0 < iVar1) {
      return g_ModelLoadQueuePendingCount + 1;
    }
    if (iVar1 < 0) {
      FreeModelHeapBlock(g_ModelLoadQueueInFlightBlock,&g_ModelLoadHeapState);
    }
    else {
      iVar1 = g_ModelLoadQueueHeadIndex * 0x18;
      if (*(int *)(&g_ModelLoadQueueAssetRef + g_ModelLoadQueueHeadIndex * 0x18) == 0) {
        FreeModelHeapBlock(g_ModelLoadQueueInFlightBlock,&g_ModelLoadHeapState);
      }
      else if (*(code **)(&g_ModelLoadQueueOnLoaded + iVar1) == (code *)0x0) {
        **(int **)(&g_ModelLoadQueueTargetOrCallbackContext + iVar1) = g_ModelLoadQueueInFlightBlock
        ;
        if (*(int *)(&g_ModelLoadQueueBindMode + iVar1) == 1) {
          BindModelHeapBlockHandle
                    (g_ModelLoadQueueInFlightBlock,
                     *(undefined4 *)(&g_ModelLoadQueueTargetOrCallbackContext + iVar1));
        }
        else {
          **(int **)(&g_ModelLoadQueueTargetOrCallbackContext + iVar1) =
               g_ModelLoadQueueInFlightBlock;
        }
      }
      else {
        (**(code **)(&g_ModelLoadQueueOnLoaded + iVar1))
                  (g_ModelLoadQueueInFlightBlock,
                   *(undefined4 *)(&g_ModelLoadQueueTargetOrCallbackContext + iVar1));
      }
      g_ModelLoadQueueInFlightBlock = 0;
      g_ModelLoadQueueCooldownTicks = 0xc;
      g_ModelLoadQueueHeadIndex = g_ModelLoadQueueHeadIndex + 1 & 0xf;
      g_ModelLoadQueuePendingCount = g_ModelLoadQueuePendingCount + -1;
      if ((g_ModelLoadQueuePendingCount == 0) && (g_ModelLoadQueueStreamHandle != 0)) {
        ResetModelLoadQueueStream(g_ModelLoadQueueStreamHandle,0);
      }
    }
  }
  if (g_ModelLoadQueuePendingCount != 0) {
    iVar1 = g_ModelLoadQueueHeadIndex * 0x18;
    if (*(int *)(&g_ModelLoadQueueAssetRef + g_ModelLoadQueueHeadIndex * 0x18) == 0) {
      g_ModelLoadQueuePendingCount = g_ModelLoadQueuePendingCount + -1;
      g_ModelLoadQueueHeadIndex = g_ModelLoadQueueHeadIndex + 1 & 0xf;
      return g_ModelLoadQueuePendingCount;
    }
    if (g_ModelLoadQueuePendingCount != 0) {
      if (*(int *)(&g_ModelLoadQueueBindMode + iVar1) == 0) {
        g_ModelLoadQueueInFlightBlock =
             CompactAndAllocModelHeapBlock
                       (((int)(*(int *)(&g_ModelLoadQueueLoadSizeBytes + iVar1) + 0x7ff +
                              (*(int *)(&g_ModelLoadQueueLoadSizeBytes + iVar1) + 0x7ff >> 0x1f &
                              0x7ffU)) >> 0xb) << 0xb,&g_ModelLoadHeapState);
      }
      else {
        iVar3 = ((int)(*(int *)(&g_ModelLoadQueueLoadSizeBytes + iVar1) + 0x7ff +
                      (*(int *)(&g_ModelLoadQueueLoadSizeBytes + iVar1) + 0x7ff >> 0x1f & 0x7ffU))
                >> 0xb) * 0x800 + 3 >> 2;
        iVar2 = FindModelHeapFreeBlockAtLeastWords(iVar3,g_ModelHeapFreeListHead);
        if ((iVar2 == 0) &&
           (iVar2 = FindModelHeapFreeBlockAtLeastWords(iVar3,g_ModelHeapFreeListHead), iVar2 == 0))
        {
          CompactModelHeapForAllocation(&g_ModelLoadHeapState);
          iVar2 = FindModelHeapFreeBlockAtLeastWords(iVar3,g_ModelHeapFreeListHead);
          if (iVar2 == 0) {
            return g_ModelLoadQueuePendingCount + 1;
          }
        }
        g_ModelLoadQueueInFlightBlock =
             AllocModelHeapBlock(((int)(*(int *)(&g_ModelLoadQueueLoadSizeBytes + iVar1) + 0x7ff +
                                       (*(int *)(&g_ModelLoadQueueLoadSizeBytes + iVar1) + 0x7ff >>
                                        0x1f & 0x7ffU)) >> 0xb) << 0xb,&g_ModelLoadHeapState);
      }
      iVar1 = ReadAssetPayloadRangeIntoModelHeapBlock
                        (*(undefined4 *)(&g_ModelLoadQueueAssetRef + iVar1),
                         (int)(*(int *)(&g_ModelLoadQueueSourceOffsetBytes + iVar1) +
                              (*(int *)(&g_ModelLoadQueueSourceOffsetBytes + iVar1) >> 0x1f & 0x7ffU
                              )) >> 0xb,g_ModelLoadQueueInFlightBlock,
                         (int)(*(int *)(&g_ModelLoadQueueLoadSizeBytes + iVar1) + 0x7ff +
                              (*(int *)(&g_ModelLoadQueueLoadSizeBytes + iVar1) + 0x7ff >> 0x1f &
                              0x7ffU)) >> 0xb);
      if (iVar1 < 0) {
        FreeModelHeapBlock(g_ModelLoadQueueInFlightBlock,&g_ModelLoadHeapState);
        g_ModelLoadQueueInFlightBlock = 0;
      }
    }
  }
  return (uint)(g_ModelLoadQueueInFlightBlock != 0) + g_ModelLoadQueuePendingCount +
         g_ModelLoadQueueCooldownTicks;
}


