#include "tarzan_ghidra_types.hpp"

// Address: 0x0043148E
// Label: CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles_ForwardFacing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles_ForwardFacing(void)

{
  ushort incomingValue;
  int savedEsi;
  bool incomingValue2;
  
  if (!incomingValue2) {
    *(ushort *)(savedEsi + 0xa0) = *(short *)(savedEsi + 0x130) - 0x400U & 0xfff;
    return;
  }
  *(ushort *)(savedEsi + 0xa2) = incomingValue ^ 0x800;
  *(ushort *)(savedEsi + 0xa0) = 0x400U - *(short *)(savedEsi + 0x130) & 0xfff;
  return;
}

