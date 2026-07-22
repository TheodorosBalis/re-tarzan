#include "tarzan_ghidra_types.hpp"

// Address: 0x0041CA00
// Label: LoadMenuGraphicBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void LoadMenuGraphicBlock(undefined4 *menu)

{
  RockinTheBoat::LoadAndAttachAssetPayload(*menu,menu + 1);
  return;
}

