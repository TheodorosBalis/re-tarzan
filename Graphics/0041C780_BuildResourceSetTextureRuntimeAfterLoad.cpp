#include "tarzan_ghidra_types.hpp"

// Address: 0x0041C780
// Label: BuildResourceSetTextureRuntimeAfterLoad
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BuildResourceSetTextureRuntimeAfterLoad(undefined4 graphicsObject,undefined4 *source2)

{
  int value;
  undefined4 value2;
  
  value = ComputePalettedTextureCellRuntimeSize(graphicsObject);
  value = FindModelHeapFreeBlockAtLeastWords(value + 3 >> 2,g_ModelHeapFreeListHead);
  if (value == 0) {
    FreeModelHeapBlock(graphicsObject,&g_ModelLoadHeapState);
    source2[2] = 0xffffffff;
    RequestResourceSetLoad(source2);
    return;
  }
  InitializePalettedTextureBlockFromAsset(source2 + 4,graphicsObject);
  BuildPalettedTextureBlockRuntime(source2 + 4);
  QueueModelHeapDeferredFree(graphicsObject,&g_ModelLoadHeapState,2);
  source2[6] = 0;
  value2 = EnqueueAssetPayloadLoadRequest(*source2,BuildQueuedModelBitmapCellRuntime,source2);
  source2[2] = value2;
  return;
}

