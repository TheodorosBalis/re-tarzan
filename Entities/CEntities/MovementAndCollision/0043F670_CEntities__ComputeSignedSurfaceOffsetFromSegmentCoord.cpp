#include "tarzan_ghidra_types.hpp"

// Address: 0x0043F670
// Label: CEntities::ComputeSignedSurfaceOffsetFromSegmentCoord
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::ComputeSignedSurfaceOffsetFromSegmentCoord(int entry)

{
  int *intCursor;
  int *intCursor2;
  undefined4 value;
  undefined4 value2;
  undefined4 value3;
  int offset;
  int offset2;
  int offset3;
  int localState3;
  undefined4 localState2;
  int localState;
  
  InterpolateJungleSurfacePointByCoordRef
            (*(undefined4 *)(entry + 0x110),*(undefined4 *)(entry + 0x10c),&localState3);
  localState2 = *(undefined4 *)(entry + 0x18);
  intCursor = (int *)RefreshEntitySceneObjectPreviousJungleSurfaceSegment(entry);
  intCursor2 = (int *)RefreshEntitySceneObjectNextJungleSurfaceSegment(entry);
  value = GetAngleFromXZVector12Bit(*intCursor2 - localState3,intCursor2[2] - localState);
  value2 = GetAngleFromXZVector12Bit(*intCursor - localState3,intCursor[2] - localState);
  value3 = GetAngleFromXZVector12Bit
                    (*(int *)(entry + 0x14) - localState3,*(int *)(entry + 0x1c) - localState);
  offset = GetWrappedAngleDistance12Bit(value,value3);
  offset2 = GetWrappedAngleDistance12Bit(value2,value3);
  localState3 = *(int *)(entry + 0x14) - localState3;
  localState = *(int *)(entry + 0x1c) - localState;
  offset3 = SqrtToInt(localState * localState + localState3 * localState3);
  offset3 = offset3 >> 6;
  if (offset2 < offset) {
    offset3 = -offset3;
  }
  return offset3;
}

