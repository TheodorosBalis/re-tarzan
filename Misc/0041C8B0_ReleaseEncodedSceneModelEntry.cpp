#include "tarzan_ghidra_types.hpp"

// Address: 0x0041C8B0
// Label: ReleaseEncodedSceneModelEntry
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseEncodedSceneModelEntry(int arg1,int arg2)

{
  Entity *entity = (Entity *)arg1;
  int entry;
  
  entry = *(int *)(arg1 + 0x30 + arg2 * 8);
  if (entry != 0) {
    FreeModelHeapBlock(entry,&g_ModelLoadHeapState);
    *(undefined4 *)(arg1 + 0x2c + arg2 * 8) = 0xffffffff;
    return;
  }
  entry = *(int *)(arg1 + 0x2c + arg2 * 8);
  if (entry != -1) {
    CancelQueuedModelLoadRequest(entry);
    *(undefined4 *)(arg1 + 0x2c + arg2 * 8) = 0xffffffff;
  }
  return;
}

