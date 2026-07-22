#include "tarzan_ghidra_types.hpp"

// Address: 0x004567D0
// Label: Stampede::ProjectPointToNearestElephantPathSegment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int Stampede::ProjectPointToNearestElephantPathSegment(int arg1,undefined4 arg2)

{
  int *intCursor;
  int value;
  int value2;
  int value3;
  uint value8;
  int value4;
  int value5;
  int value6;
  int value7;
  undefined4 localState5;
  undefined4 localState4;
  undefined4 localState3;
  undefined4 localState2;
  undefined4 localState;
  undefined4 localState8;
  undefined4 localState7;
  undefined4 localState6;
  
  value = *(int *)(arg1 + 0x14);
  value6 = 0;
  value4 = *(int *)(arg1 + 0xc) + 0x30;
  value2 = value + -3;
  if (value2 < 0) {
    value2 = 0;
  }
  value5 = value4 + value2 * 0x1c;
  value7 = 0x7fffffff;
  for (; value2 <= value + 3; value2 = value2 + 1) {
    value3 = ComputeDistanceSqToPathSegmentXZ(value5,arg2,&localState);
    if (value3 < 0) {
      value3 = 0x7fffffff;
    }
    if (value3 < value7) {
      localState5 = localState;
      localState4 = localState8;
      localState3 = localState7;
      localState2 = localState6;
      value6 = value2;
      value7 = value3;
    }
    value5 = value5 + 0x1c;
  }
  intCursor = (int *)(value4 + value6 * 0x1c);
  value8 = GetAngleFromXZVector12Bit
                    (*(int *)(value4 + (value6 + 1) * 0x1c) - *intCursor,intCursor[9] - intCursor[2]);
  *(uint *)(arg1 + 0x6c) = value8 & 0xfff;
  *(undefined4 *)(arg1 + 0x18) = localState5;
  *(int *)(arg1 + 0x10) = value7;
  *(int *)(arg1 + 0x14) = value6;
  *(undefined4 *)(arg1 + 0x1c) = localState4;
  *(undefined4 *)(arg1 + 0x20) = localState3;
  *(undefined4 *)(arg1 + 0x24) = localState2;
  return value7;
}

