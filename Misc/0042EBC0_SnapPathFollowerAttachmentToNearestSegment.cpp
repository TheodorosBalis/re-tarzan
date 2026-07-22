#include "tarzan_ghidra_types.hpp"

// Address: 0x0042EBC0
// Label: SnapPathFollowerAttachmentToNearestSegment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int SnapPathFollowerAttachmentToNearestSegment(int arg1,undefined4 arg2)

{
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  ushort *localState6;
  undefined4 localState5;
  undefined4 localState4;
  undefined4 localState3;
  undefined4 localState2;
  undefined4 localState;
  undefined4 localState9;
  undefined4 localState8;
  undefined4 localState7;
  
  value2 = 0;
  localState6 = *(ushort **)(arg1 + 0xc) + 0x18;
  value5 = **(ushort **)(arg1 + 0xc) - 1;
  value4 = 0;
  value3 = 0x7fffffff;
  if (0 < value5) {
    do {
      value = ComputeDistanceSqToPathSegmentXZ(localState6,arg2,&localState);
      if (value < 0) {
        value = 0x7fffffff;
      }
      if (value < value3) {
        localState5 = localState;
        localState4 = localState9;
        localState3 = localState8;
        localState2 = localState7;
        value2 = value4;
        value3 = value;
      }
      localState6 = localState6 + 0xe;
      value4 = value4 + 1;
    } while (value4 < value5);
  }
  *(int *)(arg1 + 0x10) = value3;
  *(undefined4 *)(arg1 + 0x18) = localState5;
  *(int *)(arg1 + 0x14) = value2;
  *(undefined4 *)(arg1 + 0x1c) = localState4;
  *(undefined4 *)(arg1 + 0x20) = localState3;
  *(undefined4 *)(arg1 + 0x24) = localState2;
  return value2;
}

