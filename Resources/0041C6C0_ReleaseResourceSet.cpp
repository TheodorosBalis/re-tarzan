#include "tarzan_ghidra_types.hpp"

// Address: 0x0041C6C0
// Label: ReleaseResourceSet
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseResourceSet(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int *intCursor;
  int value;
  
  if (entity->previous != 0) {
    value = 0;
    intCursor = (int *)(arg1 + 0x2c);
    do {
      if ((intCursor[1] != 0) || (*intCursor != -1)) {
        ReleaseEncodedSceneModelEntry(arg1,value);
      }
      value = value + 1;
      intCursor = intCursor + 2;
    } while (value < 7);
    ReleaseResourceSetPalettedTextureRuntime(entity->previous);
    FreeModelHeapBlock(entity->previous,&g_ModelLoadHeapState);
    FreePalettedTextureAndMenuTextRuntime(arg1 + 0x10);
    *(undefined4 *)(arg1 + 8) = 0xffffffff;
    return;
  }
  if (*(int *)(arg1 + 8) != -1) {
    if (*(int *)(arg1 + 0x14) != 0) {
      FreePalettedTextureAndMenuTextRuntime(arg1 + 0x10);
    }
    CancelQueuedModelLoadRequest(*(undefined4 *)(arg1 + 8));
    *(undefined4 *)(arg1 + 8) = 0xffffffff;
  }
  return;
}

