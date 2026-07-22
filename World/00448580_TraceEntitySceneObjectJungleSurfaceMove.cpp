#include "tarzan_ghidra_types.hpp"

// Address: 0x00448580
// Label: TraceEntitySceneObjectJungleSurfaceMove
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
TraceEntitySceneObjectJungleSurfaceMove(int arg1,int arg2,int arg3,undefined4 *arg4)

{
  uint *dataCursor;
  ushort value;
  int entry;
  uint value2;
  int entry2;
  int entry3;
  
  g_JungleSurfaceTraceSurfaceIndex = *(undefined4 *)(arg3 + 8);
  _g_JungleSurfaceTraceDistance = arg1;
  g_JungleSurfaceTraceSegment =
       GetJungleSurfaceSegment(g_JungleSurfaceTraceSurfaceIndex,*(undefined4 *)(arg3 + 4));
  g_JungleSurfaceTraceTargetCoord = *(int *)(arg3 + 4) + arg1;
  do {
    value2 = StepJungleSurfaceTraceToTargetCoord
                      (&g_JungleSurfaceTraceSurfaceIndex,arg2,(int)*(short *)(arg3 + 0x3a));
  } while (value2 == 0);
  if ((value2 & 8) != 0) {
    *arg4 = 2;
    arg4[1] = *(int *)(*(int *)(g_NatureTerrainDataBlock + 0x14) + 0x18 +
                         g_NatureTerrainDataBlock) + *(int *)(g_NatureTerrainDataBlock + 0x14) +
                 0x18 + g_NatureTerrainDataBlock;
    return 2;
  }
  arg4[2] = g_JungleSurfaceTraceSurfaceIndex;
  arg4[1] = g_JungleSurfaceTraceTargetCoord;
  entry = g_JungleSurfaceTraceSegment;
  dataCursor = (uint *)(g_JungleSurfaceTraceSegment + 0x14);
  if ((((*(uint *)(g_JungleSurfaceTraceSegment + 0x14) & 0x2000) == 0) &&
      ((*(uint *)(g_JungleSurfaceTraceSegment + 0x14) & 0x100) != 0)) &&
     (entry2 = InterpolateJungleSurfaceHeightAtCoord
                        (g_JungleSurfaceTraceTargetCoord,g_JungleSurfaceTraceSegment),
     entry3 = g_CollisionSurfaceTable, entry2 + g_JungleSurfaceTraceProbeSpan < arg2)) {
    value2 = *dataCursor & 0xc000;
    if (value2 == 0x4000) {
      *arg4 = 2;
      arg4[1] = *(int *)(*(int *)(g_NatureTerrainDataBlock + 0x14) + 0x18 +
                           g_NatureTerrainDataBlock) + *(int *)(g_NatureTerrainDataBlock + 0x14) +
                   0x18 + g_NatureTerrainDataBlock;
      return 2;
    }
    if ((value2 == 0x8000) &&
       (((*dataCursor & 0x80) == 0 ||
        (g_JungleSurfaceTraceTargetCoord != *(int *)(g_JungleSurfaceTraceSegment + 0xc))))) {
      value = *(ushort *)(entry + 0x1a);
      value2 = (uint)*(ushort *)(entry + 0x18);
      entry2 = *(int *)(g_CollisionSurfaceTable + 4 + value2 * 4);
      arg4[2] = value2;
      entry3 = entry2 + 0x34 + ((uint)value * 7 + value2) * 4 + entry3;
      arg4[1] = (*(int *)(entry3 + 0xc) - *(int *)(entry + 0xc)) + g_JungleSurfaceTraceTargetCoord
      ;
      arg4[3] = entry3;
      return 1;
    }
  }
  else {
    arg4[3] = g_JungleSurfaceTraceSegment;
    if ((value2 & 2) != 0) {
      arg4[0xd] = arg4[0xd] | 2;
    }
  }
  return 1;
}

