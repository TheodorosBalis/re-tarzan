#include "tarzan_ghidra_types.hpp"

// Address: 0x0043F750
// Label: SnapEntitySceneObjectVerticalPositionToCurrentSurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SnapEntitySceneObjectVerticalPositionToCurrentSurface(int arg1)

{
  undefined4 value;
  
  value = CEntities::ComputeSignedSurfaceOffsetFromSegmentCoord(arg1);
  MoveEntitySceneObjectAlongJungleSurface
            (arg1 + 0x108,arg1 + 0x14,*(undefined1 *)(arg1 + 0x75),value,
             (undefined4 *)(arg1 + 0x54));
  *(undefined4 *)(arg1 + 0x54) = 0;
  *(undefined4 *)(arg1 + 0x5c) = 0;
  return;
}

