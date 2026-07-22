#include "tarzan_ghidra_types.hpp"

// Address: 0x004490A0
// Label: RefreshEntitySceneObjectNextJungleSurfaceSegment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int RefreshEntitySceneObjectNextJungleSurfaceSegment(int arg1)

{
  int entry;
  
  entry = FindNextJungleSurfaceSegmentFromCoordRef
                    (arg1 + 0x10c,*(undefined4 *)(arg1 + 0x18),0x20);
  if (entry != 0) {
    SampleJungleSurfacePointWithFloorOffset(*(undefined4 *)(entry + 0xc),entry,arg1 + 0x120);
  }
  return entry;
}

