#include "tarzan_ghidra_types.hpp"

// Address: 0x00431450
// Label: CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(int entry,undefined4 sceneObject)

{
  ComputeEntitySceneObjectCollisionMoveDelta(sceneObject,0,entry);
  *(int *)(entry + 0x14) = *(int *)(entry + 0x14) + *(int *)(entry + 0x54);
  *(int *)(entry + 0x1c) = *(int *)(entry + 0x1c) + *(int *)(entry + 0x5c);
  *(ushort *)(entry + 0xa2) = *(ushort *)(entry + 0x132);
  if (*(char *)(entry + 0x75) != '\0') {
    *(ushort *)(entry + 0xa0) = *(short *)(entry + 0x130) - 0x400U & 0xfff;
    return;
  }
  *(ushort *)(entry + 0xa2) = *(ushort *)(entry + 0x132) ^ 0x800;
  *(ushort *)(entry + 0xa0) = 0x400U - *(short *)(entry + 0x130) & 0xfff;
  return;
}

