#include "tarzan_ghidra_types.hpp"

// Address: 0x00431462
// Label: CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles_CommitXZDelta
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles_CommitXZDelta(void)

{
  int savedEsi;
  
  *(int *)(savedEsi + 0x14) = *(int *)(savedEsi + 0x14) + *(int *)(savedEsi + 0x54);
  *(int *)(savedEsi + 0x1c) = *(int *)(savedEsi + 0x1c) + *(int *)(savedEsi + 0x5c);
  *(ushort *)(savedEsi + 0xa2) = *(ushort *)(savedEsi + 0x132);
  if (*(char *)(savedEsi + 0x75) != '\0') {
    *(ushort *)(savedEsi + 0xa0) = *(short *)(savedEsi + 0x130) - 0x400U & 0xfff;
    return;
  }
  *(ushort *)(savedEsi + 0xa2) = *(ushort *)(savedEsi + 0x132) ^ 0x800;
  *(ushort *)(savedEsi + 0xa0) = 0x400U - *(short *)(savedEsi + 0x130) & 0xfff;
  return;
}

