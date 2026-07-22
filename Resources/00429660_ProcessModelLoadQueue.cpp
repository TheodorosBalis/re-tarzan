#include "tarzan_ghidra_types.hpp"

// Address: 0x00429660
// Label: ProcessModelLoadQueue
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ProcessModelLoadQueue(void)

{
  int value;
  int value2;
  int value3;
  
  if (g_ModelLoadQueueCooldownTicks != 0) {
    g_ModelLoadQueueCooldownTicks = g_ModelLoadQueueCooldownTicks + -1;
    return g_ModelLoadQueuePendingCount + 1;
  }
  if (g_ModelLoadQueueInFlightBlock != 0) {
    value = PollModelLoadQueueIoStatus_Stub();
    if (0 < value) {
      return g_ModelLoadQueuePendingCount + 1;
    }
    if (value < 0) {
      FreeModelHeapBlock(g_ModelLoadQueueInFlightBlock,&g_ModelLoadHeapState);
    }
    else {
      value = g_ModelLoadQueueHeadIndex * 0x18;
      if (*(int *)(&g_ModelLoadQueueAssetRef + g_ModelLoadQueueHeadIndex * 0x18) == 0) {
        FreeModelHeapBlock(g_ModelLoadQueueInFlightBlock,&g_ModelLoadHeapState);
      }
      else if (*(code **)(&g_ModelLoadQueueOnLoaded + value) == (code *)0x0) {
        **(int **)(&g_ModelLoadQueueTargetOrCallbackContext + value) = g_ModelLoadQueueInFlightBlock
        ;
        if (*(int *)(&g_ModelLoadQueueBindMode + value) == 1) {
          BindModelHeapBlockHandle
                    (g_ModelLoadQueueInFlightBlock,
                     *(undefined4 *)(&g_ModelLoadQueueTargetOrCallbackContext + value));
        }
        else {
          **(int **)(&g_ModelLoadQueueTargetOrCallbackContext + value) =
               g_ModelLoadQueueInFlightBlock;
        }
      }
      else {
        (**(code **)(&g_ModelLoadQueueOnLoaded + value))
                  (g_ModelLoadQueueInFlightBlock,
                   *(undefined4 *)(&g_ModelLoadQueueTargetOrCallbackContext + value));
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
    value = g_ModelLoadQueueHeadIndex * 0x18;
    if (*(int *)(&g_ModelLoadQueueAssetRef + g_ModelLoadQueueHeadIndex * 0x18) == 0) {
      g_ModelLoadQueuePendingCount = g_ModelLoadQueuePendingCount + -1;
      g_ModelLoadQueueHeadIndex = g_ModelLoadQueueHeadIndex + 1 & 0xf;
      return g_ModelLoadQueuePendingCount;
    }
    if (g_ModelLoadQueuePendingCount != 0) {
      if (*(int *)(&g_ModelLoadQueueBindMode + value) == 0) {
        g_ModelLoadQueueInFlightBlock =
             CompactAndAllocModelHeapBlock
                       (((int)(*(int *)(&g_ModelLoadQueueLoadSizeBytes + value) + 0x7ff +
                              (*(int *)(&g_ModelLoadQueueLoadSizeBytes + value) + 0x7ff >> 0x1f &
                              0x7ffU)) >> 0xb) << 0xb,&g_ModelLoadHeapState);
      }
      else {
        value3 = ((int)(*(int *)(&g_ModelLoadQueueLoadSizeBytes + value) + 0x7ff +
                      (*(int *)(&g_ModelLoadQueueLoadSizeBytes + value) + 0x7ff >> 0x1f & 0x7ffU))
                >> 0xb) * 0x800 + 3 >> 2;
        value2 = FindModelHeapFreeBlockAtLeastWords(value3,g_ModelHeapFreeListHead);
        if ((value2 == 0) &&
           (value2 = FindModelHeapFreeBlockAtLeastWords(value3,g_ModelHeapFreeListHead), value2 == 0))
        {
          CompactModelHeapForAllocation(&g_ModelLoadHeapState);
          value2 = FindModelHeapFreeBlockAtLeastWords(value3,g_ModelHeapFreeListHead);
          if (value2 == 0) {
            return g_ModelLoadQueuePendingCount + 1;
          }
        }
        g_ModelLoadQueueInFlightBlock =
             AllocModelHeapBlock(((int)(*(int *)(&g_ModelLoadQueueLoadSizeBytes + value) + 0x7ff +
                                       (*(int *)(&g_ModelLoadQueueLoadSizeBytes + value) + 0x7ff >>
                                        0x1f & 0x7ffU)) >> 0xb) << 0xb,&g_ModelLoadHeapState);
      }
      value = ReadAssetPayloadRangeIntoModelHeapBlock
                        (*(undefined4 *)(&g_ModelLoadQueueAssetRef + value),
                         (int)(*(int *)(&g_ModelLoadQueueSourceOffsetBytes + value) +
                              (*(int *)(&g_ModelLoadQueueSourceOffsetBytes + value) >> 0x1f & 0x7ffU
                              )) >> 0xb,g_ModelLoadQueueInFlightBlock,
                         (int)(*(int *)(&g_ModelLoadQueueLoadSizeBytes + value) + 0x7ff +
                              (*(int *)(&g_ModelLoadQueueLoadSizeBytes + value) + 0x7ff >> 0x1f &
                              0x7ffU)) >> 0xb);
      if (value < 0) {
        FreeModelHeapBlock(g_ModelLoadQueueInFlightBlock,&g_ModelLoadHeapState);
        g_ModelLoadQueueInFlightBlock = 0;
      }
    }
  }
  return (uint)(g_ModelLoadQueueInFlightBlock != 0) + g_ModelLoadQueuePendingCount +
         g_ModelLoadQueueCooldownTicks;
}

