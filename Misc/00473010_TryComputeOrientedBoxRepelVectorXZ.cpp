#include "tarzan_ghidra_types.hpp"

// Address: 0x00473010
// Label: TryComputeOrientedBoxRepelVectorXZ
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
TryComputeOrientedBoxRepelVectorXZ
          (int arg1,short *arg2,int arg3,short *arg4,uint *arg5,int *arg6)

{
  Entity *entity3 = (Entity *)arg3;
  short shortValue;
  uint value2;
  int value;
  short localState11 [4];
  int localState10;
  int localState9;
  int localState8;
  int localState7;
  int localState6;
  int localState5;
  int localState4;
  int localState3;
  int localState2;
  int localState;
  int localState13;
  int localState12;
  
  arg6[2] = 0;
  *arg6 = 0;
  localState4 = (int)*arg2;
  localState3 = (int)arg2[1];
  localState2 = (int)arg2[2];
  value = 0x7ffffff;
  TransformVectorByBasis(arg1 + 0xb8,&localState4,&localState4);
  localState4 = (localState4 + *(int *)(arg1 + 0x14)) - *(int *)(arg3 + 0x20);
  localState3 = (localState3 + *(int *)(arg1 + 0x18)) - *(int *)(arg3 + 0x24);
  localState2 = (localState2 + *(int *)(arg1 + 0x1c)) - *(int *)(arg3 + 0x28);
  localState6 = (int)arg4[1];
  localState5 = (int)arg4[2];
  localState10 = (int)arg4[3];
  shortValue = *arg4;
  localState9 = (int)arg4[4];
  localState8 = (int)arg4[5];
  localState7 = (int)shortValue;
  TransformVectorByBasis(arg3 + 0x4c,&localState4,&localState);
  value2 = (uint)(localState < shortValue);
  if (localState13 < localState9) {
    value2 = value2 | 0x10;
  }
  if (localState12 < localState5) {
    value2 = value2 | 4;
  }
  if (localState10 < localState) {
    value2 = value2 | 2;
  }
  if (localState6 < localState13) {
    value2 = value2 | 0x20;
  }
  if (localState8 < localState12) {
    value2 = value2 | 8;
  }
  *arg5 = value2;
  switch(value2) {
  case 0:
    value = 0x7fffff;
    localState11[0] = 0;
    localState11[1] = 0;
    localState11[2] = 0;
    goto switchD_00473145_caseD_3;
  case 1:
    localState11[0] = -0x400;
    value = (localState - localState7) * (localState - localState7);
    localState11[1] = 0;
    localState11[2] = 0;
    break;
  case 2:
    localState11[0] = 0x400;
    value2 = localState - localState10 >> 0x1f;
    value = (localState - localState10 ^ value2) - value2;
    value = value * value;
    localState11[2] = 0;
    localState11[1] = 0;
    break;
  default:
    goto switchD_00473145_caseD_3;
  case 4:
    localState11[2] = -0x400;
    value2 = localState12 - localState5 >> 0x1f;
    value = (localState12 - localState5 ^ value2) - value2;
    value = value * value;
    localState11[0] = 0;
    localState11[1] = 0;
    break;
  case 5:
    localState11[2] = -0x400;
    value = (localState12 - localState5) * (localState12 - localState5) +
            (localState - localState7) * (localState - localState7);
    localState11[0] = -0x400;
    localState11[1] = 0;
    break;
  case 6:
    localState11[0] = 0x400;
    localState11[1] = 0;
    value = (localState12 - localState5) * (localState12 - localState5) +
            (localState - localState10) * (localState - localState10);
    localState11[2] = -0x400;
    break;
  case 8:
    value2 = localState12 - localState8 >> 0x1f;
    value = (localState12 - localState8 ^ value2) - value2;
    value = value * value;
    localState11[1] = 0;
    goto LAB_004735ba;
  case 9:
    localState11[0] = -0x400;
    localState11[1] = 0;
    value = (localState12 - localState8) * (localState12 - localState8) +
            (localState - localState7) * (localState - localState7);
    localState11[2] = 0x400;
    break;
  case 10:
    localState11[1] = 0;
    value = (localState12 - localState8) * (localState12 - localState8) +
            (localState - localState10) * (localState - localState10);
    localState11[2] = 0x400;
    localState11[0] = 0x400;
    break;
  case 0x10:
    localState11[1] = 0x400;
    value2 = localState13 - localState9 >> 0x1f;
    value = (localState13 - localState9 ^ value2) - value2;
    value = value * value;
    localState11[0] = 0;
    localState11[2] = 0;
    break;
  case 0x11:
    value = (localState9 - localState13) * (localState9 - localState13) +
            (localState - localState7) * (localState - localState7);
    localState11[0] = -0x400;
    localState11[1] = 0x400;
    localState11[2] = 0;
    break;
  case 0x12:
    value = (localState13 - localState9) * (localState13 - localState9) +
            (localState - localState10) * (localState - localState10);
    localState11[0] = 0x400;
    localState11[1] = 0x400;
    localState11[2] = 0;
    break;
  case 0x14:
    localState11[0] = 0;
    localState11[1] = 0x400;
    value = (localState12 - localState5) * (localState12 - localState5) +
            (localState13 - localState9) * (localState13 - localState9);
    localState11[2] = -0x400;
    break;
  case 0x15:
    localState11[2] = -0x400;
    value = (localState12 - localState5) * (localState12 - localState5) +
            (localState13 - localState9) * (localState13 - localState9) +
            (localState - localState7) * (localState - localState7);
    localState11[0] = -0x400;
    localState11[1] = 0x400;
    break;
  case 0x16:
    value = (localState12 - localState5) * (localState12 - localState5) +
            (localState13 - localState9) * (localState13 - localState9) +
            (localState - localState10) * (localState - localState10);
    localState11[0] = 0x400;
    localState11[1] = 0x400;
    localState11[2] = -0x400;
    break;
  case 0x18:
    localState11[2] = 0x400;
    value = (localState12 - localState8) * (localState12 - localState8) +
            (localState13 - localState9) * (localState13 - localState9);
    localState11[0] = 0;
    localState11[1] = 0x400;
    break;
  case 0x19:
    value = (localState12 - localState8) * (localState12 - localState8) +
            (localState13 - localState9) * (localState13 - localState9) +
            (localState - localState7) * (localState - localState7);
    localState11[2] = 0x400;
    localState11[0] = -0x400;
    localState11[1] = 0x400;
    break;
  case 0x1a:
    value = (localState12 - localState8) * (localState12 - localState8) +
            (localState13 - localState9) * (localState13 - localState9) +
            (localState - localState10) * (localState - localState10);
    localState11[0] = 0x400;
    localState11[1] = 0x400;
    localState11[2] = 0x400;
    break;
  case 0x20:
    localState11[1] = 0xfc00;
    value2 = localState13 - localState6 >> 0x1f;
    value = (localState13 - localState6 ^ value2) - value2;
    value = value * value;
    localState11[2] = 0;
    localState11[0] = 0;
    break;
  case 0x21:
    value = (localState13 - localState6) * (localState13 - localState6) +
            (localState - localState7) * (localState - localState7);
    localState11[0] = -0x400;
    localState11[1] = 0xfc00;
    localState11[2] = 0;
    break;
  case 0x22:
    value = (localState13 - localState6) * (localState13 - localState6) +
            (localState - localState10) * (localState - localState10);
    localState11[0] = 0x400;
    localState11[1] = 0xfc00;
    localState11[2] = 0;
    break;
  case 0x24:
    localState11[2] = -0x400;
    value = (localState12 - localState5) * (localState12 - localState5) +
            (localState13 - localState6) * (localState13 - localState6);
    localState11[0] = 0;
    localState11[1] = 0xfc00;
    break;
  case 0x25:
    value = (localState12 - localState5) * (localState12 - localState5) +
            (localState13 - localState6) * (localState13 - localState6) +
            (localState - localState7) * (localState - localState7);
    localState11[2] = -0x400;
    localState11[0] = -0x400;
    localState11[1] = 0xfc00;
    break;
  case 0x26:
    localState11[2] = -0x400;
    value = (localState12 - localState5) * (localState12 - localState5) +
            (localState13 - localState6) * (localState13 - localState6) +
            (localState - localState10) * (localState - localState10);
    localState11[0] = 0x400;
    localState11[1] = 0xfc00;
    break;
  case 0x28:
    value = (localState12 - localState8) * (localState12 - localState8) +
            (localState13 - localState6) * (localState13 - localState6);
    localState11[1] = 0xfc00;
LAB_004735ba:
    localState11[0] = 0;
    localState11[2] = 0x400;
    break;
  case 0x29:
    value = (localState12 - localState8) * (localState12 - localState8) +
            (localState13 - localState6) * (localState13 - localState6) +
            (localState - localState7) * (localState - localState7);
    localState11[0] = -0x400;
    localState11[1] = 0xfc00;
    localState11[2] = 0x400;
    break;
  case 0x2a:
    localState11[2] = 0x400;
    value = (localState12 - localState8) * (localState12 - localState8) +
            (localState13 - localState6) * (localState13 - localState6) +
            (localState - localState10) * (localState - localState10);
    localState11[0] = 0x400;
    localState11[1] = 0xfc00;
  }
  TransformShortVectorByBasis(arg3 + 0x2c,localState11,localState11);
switchD_00473145_caseD_3:
  if ((int)arg2[3] * (int)arg2[3] < value) {
    return 0;
  }
  if (value < 1) {
    arg6[2] = 0;
    *arg6 = 0;
  }
  else {
    value = SqrtToInt(value);
    if (value >> 6 < (int)arg2[3]) {
      value = (int)arg2[3] - (value >> 6);
      *arg6 = localState11[0] * value >> 10;
      arg6[2] = localState11[2] * value >> 10;
      return 1;
    }
  }
  return 1;
}

