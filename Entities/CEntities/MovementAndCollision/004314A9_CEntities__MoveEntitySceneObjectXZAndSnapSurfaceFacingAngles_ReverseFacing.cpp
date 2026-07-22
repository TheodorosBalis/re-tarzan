#include "tarzan_ghidra_types.hpp"

// Address: 0x004314A9
// Label: CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles_ReverseFacing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles_ReverseFacing(void)

{
  ushort incomingValue;
  int savedEsi;
  
  *(ushort *)(savedEsi + 0xa2) = incomingValue ^ 0x800;
  *(ushort *)(savedEsi + 0xa0) = 0x400U - *(short *)(savedEsi + 0x130) & 0xfff;
  return;
}

