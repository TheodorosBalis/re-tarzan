#include "tarzan_ghidra_types.hpp"

// Address: 0x004298F0
// Label: EnqueueModelLoadRequest
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void EnqueueModelLoadRequest
               (undefined4 arg1,undefined4 arg2,undefined4 arg3,undefined4 arg4,
               undefined4 arg5,undefined4 arg6)

{
  int value;
  
  value = (g_ModelLoadQueuePendingCount + g_ModelLoadQueueHeadIndex & 0xfU) * 0x18;
  *(undefined4 *)(&g_ModelLoadQueueAssetRef + value) = arg1;
  *(undefined4 *)(&g_ModelLoadQueueSourceOffsetBytes + value) = arg2;
  *(undefined4 *)(&g_ModelLoadQueueBindMode + value) = arg6;
  *(undefined4 *)(&g_ModelLoadQueueLoadSizeBytes + value) = arg3;
  *(undefined4 *)(&g_ModelLoadQueueOnLoaded + value) = arg4;
  *(undefined4 *)(&g_ModelLoadQueueTargetOrCallbackContext + value) = arg5;
  g_ModelLoadQueuePendingCount = g_ModelLoadQueuePendingCount + 1;
  return;
}

