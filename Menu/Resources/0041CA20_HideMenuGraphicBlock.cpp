#include "tarzan_ghidra_types.hpp"

// Address: 0x0041CA20
// Label: HideMenuGraphicBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void HideMenuGraphicBlock(int menu)

{
  FreePalettedTextureAndMenuTextRuntime(menu + 4);
  return;
}

