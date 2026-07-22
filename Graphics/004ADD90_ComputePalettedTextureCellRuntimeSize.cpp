#include "tarzan_ghidra_types.hpp"

// Address: 0x004ADD90
// Label: ComputePalettedTextureCellRuntimeSize
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ComputePalettedTextureCellRuntimeSize(int graphicsObject)

{
  return (uint)*(ushort *)(graphicsObject + 8) * 0x26 + 0x30;
}

