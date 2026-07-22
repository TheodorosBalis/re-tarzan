#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABC30
// Label: ApplyAnchorProjectionParams
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ApplyAnchorProjectionParams(int arg1)

{
  SetProjectionScreenOrigin(*(undefined4 *)(arg1 + 0x18),*(undefined4 *)(arg1 + 0x1c));
  SetProjectionDepthScale(*(undefined4 *)(arg1 + 0x20));
  return;
}

