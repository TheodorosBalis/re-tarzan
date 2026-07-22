#include "tarzan_ghidra_types.hpp"

// Address: 0x00430240
// Label: CEntities::MoveSurfaceEntityFromMotionFlags
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
CEntities::MoveSurfaceEntityFromMotionFlags(int entry,undefined4 sceneObject,int attachment,int flags)

{
  ushort stateFlags;
  
  stateFlags = *(ushort *)(entry + 0x4a);
  if ((stateFlags & 0x20) == 0) {
    if ((stateFlags & 2) != 0) {
      CEntities::MoveEntityForwardOnSurface(entry,attachment);
      return 0;
    }
    if ((stateFlags & 1) != 0) {
      CEntities::MoveEntityForwardOnSurface(entry,flags);
      return 0;
    }
  }
  else {
    if ((stateFlags & 2) != 0) {
      CEntities::MoveEntityForwardOnSurface(entry,-attachment);
      return 0;
    }
    if ((stateFlags & 1) != 0) {
      CEntities::MoveEntityForwardOnSurface(entry,-flags);
      return 0;
    }
  }
  CEntities::MoveEntityForwardOnSurface(entry,0);
  return 0;
}

