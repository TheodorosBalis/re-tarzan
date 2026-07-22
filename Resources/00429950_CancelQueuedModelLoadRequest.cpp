#include "tarzan_ghidra_types.hpp"

// Address: 0x00429950
// Label: CancelQueuedModelLoadRequest
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CancelQueuedModelLoadRequest(int arg1)

{
  *(undefined4 *)(&g_ModelLoadQueueAssetRef + arg1 * 0x18) = 0;
  return;
}

