#include "tarzan_ghidra_types.hpp"

// Address: 0x004ADDB0
// Label: ReleasePalettedTextureBlockIfUnused
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleasePalettedTextureBlockIfUnused(int graphicsObject,int source2)

{
  if (source2 <= FrameCount - *(int *)(graphicsObject + 0x18)) {
    FreePalettedTextureBlockRuntime(graphicsObject);
    *(undefined4 *)(graphicsObject + 0x18) = 0;
  }
  return;
}

