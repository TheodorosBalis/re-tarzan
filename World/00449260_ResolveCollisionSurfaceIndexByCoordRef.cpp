#include "tarzan_ghidra_types.hpp"

// Address: 0x00449260
// Label: ResolveCollisionSurfaceIndexByCoordRef
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ResolveCollisionSurfaceIndexByCoordRef(undefined4 arg1)

{
  int value;
  
  value = FindCollisionSurfaceIndexByCoordRef(arg1);
  if (value < 0) {
    value = -1;
  }
  return value;
}

