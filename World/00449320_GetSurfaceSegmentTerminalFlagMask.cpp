#include "tarzan_ghidra_types.hpp"

// Address: 0x00449320
// Label: GetSurfaceSegmentTerminalFlagMask
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int GetSurfaceSegmentTerminalFlagMask(int value)

{
  if (*(int *)(value + 0xc) == 0) {
    return 0;
  }
  if ((*(uint *)(value + 0x14) & 0x2000) != 0) {
    return 0x800;
  }
  return (*(uint *)(value + 0x14) & 0x100) << 3;
}

