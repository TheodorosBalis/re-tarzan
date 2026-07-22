#include "tarzan_ghidra_types.hpp"

// Address: 0x00449050
// Label: RefreshEntitySceneObjectCurrentJungleSurfaceSegment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int RefreshEntitySceneObjectCurrentJungleSurfaceSegment(int arg1)

{
  int entry;
  
  g_JungleSurfaceTraceProbeSpan = 0x20;
  entry = GetJungleSurfaceSegment(*(undefined4 *)(arg1 + 0x110),*(undefined4 *)(arg1 + 0x10c))
  ;
  if (entry != 0) {
    SampleJungleSurfacePointWithFloorOffset(*(undefined4 *)(entry + 0xc),entry,arg1 + 0x120);
  }
  return entry;
}

