#include "tarzan_ghidra_types.hpp"

// Address: 0x0043F1F0
// Label: UpdateEntitySceneObjectCollisionSurfaceRef
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int UpdateEntitySceneObjectCollisionSurfaceRef(int arg1,undefined4 arg2,int arg3)

{
  int entry;
  
  if (*(int *)(arg3 + 0x108) != 1) {
    return 0;
  }
  if (*(int *)(arg3 + 0x110) == -1) {
    return 2;
  }
  if (arg1 == 0) {
    entry = RefreshEntitySceneObjectCurrentJungleSurfaceSegment();
    *(int *)(arg3 + 0x114) = entry;
    return (-(uint)(entry != 0) & 0xfffffffc) + 4;
  }
  if (0 < arg1) {
    entry = RefreshEntitySceneObjectNextJungleSurfaceSegment();
    *(int *)(arg3 + 0x114) = entry;
    return (-(uint)(entry != 0) & 0xfffffffc) + 4;
  }
  entry = RefreshEntitySceneObjectPreviousJungleSurfaceSegment(arg3);
  *(int *)(arg3 + 0x114) = entry;
  return (-(uint)(entry != 0) & 0xfffffffc) + 4;
}

