#include "tarzan_ghidra_types.hpp"

// Address: 0x0043147E
// Label: CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles_SnapAngles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void __fastcall
CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles_SnapAngles(char entry)

{
  int savedEsi;
  
  *(ushort *)(savedEsi + 0xa2) = *(ushort *)(savedEsi + 0x132);
  if (entry != '\0') {
    *(ushort *)(savedEsi + 0xa0) = *(short *)(savedEsi + 0x130) - 0x400U & 0xfff;
    return;
  }
  *(ushort *)(savedEsi + 0xa2) = *(ushort *)(savedEsi + 0x132) ^ 0x800;
  *(ushort *)(savedEsi + 0xa0) = 0x400U - *(short *)(savedEsi + 0x130) & 0xfff;
  return;
}

