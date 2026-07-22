#include "tarzan_ghidra_types.hpp"

// Address: 0x00449350
// Label: IsFacingBlockedEndOfSurfaceSegment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool IsFacingBlockedEndOfSurfaceSegment(undefined4 arg1,int *arg2)

{
  int *intCursor;
  int result;
  
  intCursor = arg2 + -7;
  if ((arg2[5] & 0x2000U) == 0) {
    intCursor = arg2;
  }
  result = GetAngleFromXZVector12Bit(intCursor[7] - *intCursor,intCursor[9] - intCursor[2]);
  result = GetWrappedAngleDistance12Bit(arg1,result - 0x800U & 0xfff);
  if (0x400 < result) {
    result = GetSurfaceSegmentTerminalFlagMask(arg2);
    return result != 0;
  }
  result = GetSurfaceSegmentTerminalFlagMask(arg2);
  return result == 0;
}

