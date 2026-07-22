#include "tarzan_ghidra_types.hpp"

// Address: 0x00449120
// Label: ProjectWorldPositionToJungleSurfaceCoord
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ProjectWorldPositionToJungleSurfaceCoord(int *arg1,ushort *arg2)

{
  int value;
  int value2;
  int value3;
  uint value6;
  int value4;
  int value5;
  ushort *dataCursor;
  int localState2;
  ushort *localState;
  
  value6 = (uint)*arg2;
  localState = (ushort *)0x0;
  localState2 = 0x1000;
  dataCursor = arg2 + 0x18;
  while (value6 = value6 - 1, value6 != 0) {
    value5 = *(int *)(dataCursor + 4);
    value = arg1[2];
    value2 = *(int *)dataCursor;
    value3 = *arg1;
    value4 = GetAngleFromXZVector12Bit
                      (*(int *)(dataCursor + 0xe) - value2,*(int *)(dataCursor + 0x12) - value5);
    value5 = GetAngleFromXZVector12Bit(value3 - value2,value - value5);
    value5 = value5 - value4;
    if (value5 < 0) {
      value5 = -value5;
    }
    if (value5 < localState2) {
      localState2 = value5;
      localState = dataCursor;
    }
    dataCursor = dataCursor + 0xe;
  }
  value5 = SqrtToInt((arg1[2] - *(int *)(localState + 4)) * (arg1[2] - *(int *)(localState + 4)) +
                    (*arg1 - *(int *)localState) * (*arg1 - *(int *)localState));
  value5 = (value5 >> 6) + *(int *)(localState + 6);
  if (*(int *)(arg2 + 2) < value5) {
    value5 = *(int *)(arg2 + 2);
  }
  return value5;
}

