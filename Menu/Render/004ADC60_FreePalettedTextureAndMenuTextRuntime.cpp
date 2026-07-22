#include "tarzan_ghidra_types.hpp"

// Address: 0x004ADC60
// Label: FreePalettedTextureAndMenuTextRuntime
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void FreePalettedTextureAndMenuTextRuntime(int menu)

{
  if (menu != 0) {
    FreePalettedTextureBlockRuntime(menu);
    if (*(int *)(menu + 4) != 0) {
      FreeModelHeapBlock(*(int *)(menu + 4),&g_ModelLoadHeapState);
    }
    *(undefined4 *)(menu + 4) = 0;
    if (*(int *)(menu + 8) != 0) {
      FreeModelHeapBlock(*(int *)(menu + 8),&g_ModelLoadHeapState);
    }
    *(undefined4 *)(menu + 8) = 0;
  }
  return;
}

