#include "tarzan_ghidra_types.hpp"

// Address: 0x00448720
// Label: MoveEntitySceneObjectAlongJungleSurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
MoveEntitySceneObjectAlongJungleSurface
          (int arg1,int *arg2,int arg3,uint arg4,int *arg5)

{
  Entity *entity = (Entity *)arg1;
  int *intCursor;
  undefined4 value;
  int entry;
  uint value2;
  
  value2 = (uint)*(short *)(arg1 + 0x38);
  if (arg3 != 0) {
    value2 = -value2;
  }
  g_JungleSurfaceTraceProbeSpan =
       ((int)((value2 ^ (int)value2 >> 0x1f) - ((int)value2 >> 0x1f)) >> 1) +
       ((arg4 ^ (int)arg4 >> 0x1f) - ((int)arg4 >> 0x1f));
  entry = TraceEntitySceneObjectJungleSurfaceMove(arg4 + value2,arg2[1],arg1,arg1);
  if (entry == 1) {
    value = entity->descriptor;
    entity->descriptor = 0;
    entry = TraceEntitySceneObjectJungleSurfaceMove(-value2,arg2[1],arg1,arg1);
    if (entry == 1) {
      intCursor = (int *)(arg1 + 0x18);
      entity->descriptor = value;
      SampleJungleSurfacePointWithFloorOffset
                (*(undefined4 *)(arg1 + 4),entity->previous,intCursor);
      UpdateEntitySceneObjectSurfaceAnglesFromSegment(entity->previous,intCursor);
      *arg5 = *intCursor;
      arg5[1] = *(int *)(arg1 + 0x1c);
      arg5[2] = *(int *)(arg1 + 0x20);
      *arg5 = *arg5 - *arg2;
      arg5[1] = arg5[1] - arg2[1];
      arg5[2] = arg5[2] - arg2[2];
      return 0;
    }
  }
  *arg5 = 0;
  arg5[1] = 0;
  arg5[2] = 0;
  return 0;
}

