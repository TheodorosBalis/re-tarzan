#include "tarzan_ghidra_types.hpp"

// Address: 0x00443B90
// Label: CEntities::ComputeAttachmentBoundsPushVector
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
CEntities::ComputeAttachmentBoundsPushVector
          (int entry,short *sceneObject,int attachment,short *flags,uint *arg5,int *arg6)

{
  short shortValue;
  int value;
  uint value3;
  int value2;
  bool flagByte;
  short localState19;
  short localState18;
  short localState17;
  short localState16;
  short localState15;
  short localState14;
  int localState13;
  int localState12;
  int localState11;
  int localState10;
  int localState9;
  int localState8;
  int localState7;
  int localState6;
  int localState5;
  int localState4;
  int localState3;
  int localState2;
  undefined1 localState [32];
  
  value = attachment + 0xb8;
  value2 = 0x7ffffff;
  arg6[2] = 0;
  *arg6 = 0;
  localState7 = (int)*sceneObject;
  localState6 = (int)sceneObject[1];
  localState5 = (int)sceneObject[2];
  if (*(short *)(entry + 0xa6) != 3) {
    TransformVectorByBasis(entry + 0xb8,&localState7,&localState7);
  }
  localState7 = (localState7 + *(int *)(entry + 0x14)) - *(int *)(attachment + 0x14);
  localState6 = (localState6 + *(int *)(entry + 0x18)) - *(int *)(attachment + 0x18);
  localState5 = (localState5 + *(int *)(entry + 0x1c)) - *(int *)(attachment + 0x1c);
  flagByte = *(short *)(attachment + 0xa6) != 3;
  localState9 = (int)flags[1];
  localState8 = (int)flags[2];
  shortValue = *flags;
  localState13 = (int)flags[3];
  localState12 = (int)flags[4];
  localState11 = (int)flags[5];
  localState16 = -*(short *)(attachment + 0xa0);
  localState15 = -*(short *)(attachment + 0xa2);
  localState14 = -*(short *)(attachment + 0xa4);
  localState10 = (int)shortValue;
  BuildRotationBasisFromEulerAngles(&localState16,localState);
  TransformVectorByBasis(localState,&localState7,&localState4);
  value3 = (uint)(localState4 < shortValue);
  if (localState3 < localState12) {
    value3 = value3 | 0x10;
  }
  if (localState2 < localState8) {
    value3 = value3 | 4;
  }
  if (localState13 < localState4) {
    value3 = value3 | 2;
  }
  if (localState9 < localState3) {
    value3 = value3 | 0x20;
  }
  if (localState11 < localState2) {
    value3 = value3 | 8;
  }
  *arg5 = value3;
  switch(value3) {
  case 0:
    value2 = -1;
    localState19 = 0;
    localState18 = 0;
    localState17 = 0;
    goto LAB_004442b7;
  case 1:
    localState19 = -0x400;
    value2 = (localState4 - localState10) * (localState4 - localState10);
    localState18 = 0;
    localState17 = 0;
    break;
  case 2:
    localState19 = 0x400;
    value3 = localState4 - localState13 >> 0x1f;
    value2 = (localState4 - localState13 ^ value3) - value3;
    value2 = value2 * value2;
    localState18 = 0;
    localState17 = 0;
    break;
  default:
    goto LAB_004442b7;
  case 4:
    value3 = localState2 - localState8 >> 0x1f;
    value2 = (localState2 - localState8 ^ value3) - value3;
    value2 = value2 * value2;
    localState18 = 0;
    goto LAB_00443e1c;
  case 5:
    value2 = (localState2 - localState8) * (localState2 - localState8) +
            (localState4 - localState10) * (localState4 - localState10);
    localState19 = -0x400;
    localState18 = 0;
    localState17 = -0x400;
    goto LAB_00443da3;
  case 6:
    localState19 = 0x400;
    localState17 = -0x400;
    value2 = (localState2 - localState8) * (localState2 - localState8) +
            (localState4 - localState13) * (localState4 - localState13);
    localState18 = 0;
    goto LAB_00443da3;
  case 8:
    value3 = localState2 - localState11 >> 0x1f;
    value2 = (localState2 - localState11 ^ value3) - value3;
    value2 = value2 * value2;
    goto LAB_004441a1;
  case 9:
    value2 = (localState2 - localState11) * (localState2 - localState11) +
            (localState4 - localState10) * (localState4 - localState10);
    localState19 = -0x400;
    localState18 = 0;
    localState17 = 0x400;
    break;
  case 10:
    value2 = (localState2 - localState11) * (localState2 - localState11) +
            (localState4 - localState13) * (localState4 - localState13);
    localState19 = 0x400;
    localState18 = 0;
    localState17 = 0x400;
    break;
  case 0x10:
    localState18 = 0x400;
    value3 = localState3 - localState12 >> 0x1f;
    value2 = (localState3 - localState12 ^ value3) - value3;
    value2 = value2 * value2;
    localState19 = 0;
    localState17 = 0;
    goto LAB_00443da3;
  case 0x11:
    localState19 = -0x400;
    value2 = (localState12 - localState3) * (localState12 - localState3) +
            (localState4 - localState10) * (localState4 - localState10);
    localState18 = 0x400;
    localState17 = 0;
    break;
  case 0x12:
    value2 = (localState3 - localState12) * (localState3 - localState12) +
            (localState4 - localState13) * (localState4 - localState13);
    localState19 = 0x400;
    localState18 = 0x400;
    localState17 = 0;
    break;
  case 0x14:
    value2 = (localState2 - localState8) * (localState2 - localState8) +
            (localState3 - localState12) * (localState3 - localState12);
    localState18 = 0x400;
LAB_00443e1c:
    localState17 = -0x400;
LAB_00443e23:
    localState19 = 0;
    if (flagByte) {
      TransformShortVectorByBasis(value,&localState19,&localState19);
    }
    goto LAB_004442b7;
  case 0x15:
    localState17 = -0x400;
    value2 = (localState2 - localState8) * (localState2 - localState8) +
            (localState3 - localState12) * (localState3 - localState12) +
            (localState4 - localState10) * (localState4 - localState10);
    localState19 = -0x400;
    localState18 = 0x400;
    break;
  case 0x16:
    value2 = (localState2 - localState8) * (localState2 - localState8) +
            (localState3 - localState12) * (localState3 - localState12) +
            (localState4 - localState13) * (localState4 - localState13);
    localState19 = 0x400;
    localState18 = 0x400;
    localState17 = -0x400;
    break;
  case 0x18:
    value2 = (localState2 - localState11) * (localState2 - localState11) +
            (localState3 - localState12) * (localState3 - localState12);
LAB_004441a1:
    localState17 = 0x400;
    localState19 = 0;
    localState18 = 0;
    goto LAB_00443da3;
  case 0x19:
    value2 = (localState2 - localState11) * (localState2 - localState11) +
            (localState3 - localState12) * (localState3 - localState12) +
            (localState4 - localState10) * (localState4 - localState10);
    localState19 = -0x400;
    localState18 = 0x400;
    localState17 = 0x400;
    goto LAB_00443da3;
  case 0x1a:
    value2 = (localState2 - localState11) * (localState2 - localState11) +
            (localState3 - localState12) * (localState3 - localState12) +
            (localState4 - localState13) * (localState4 - localState13);
    localState19 = 0x400;
    localState18 = localState19;
    localState17 = localState19;
    goto LAB_00443da3;
  case 0x20:
    localState18 = -0x400;
    value2 = (localState3 - localState9) * (localState3 - localState9);
    localState19 = 0;
    localState17 = 0;
    goto LAB_00443da3;
  case 0x21:
    value2 = (localState3 - localState9) * (localState3 - localState9) +
            (localState4 - localState10) * (localState4 - localState10);
    localState19 = -0x400;
    localState18 = -0x400;
    localState17 = 0;
    goto LAB_00443da3;
  case 0x22:
    value2 = (localState3 - localState9) * (localState3 - localState9) +
            (localState4 - localState13) * (localState4 - localState13);
    localState19 = 0x400;
    localState18 = -0x400;
    localState17 = 0;
    goto LAB_00443da3;
  case 0x24:
    value2 = (localState2 - localState8) * (localState2 - localState8) +
            (localState3 - localState9) * (localState3 - localState9);
    localState19 = 0;
    localState18 = -0x400;
    localState17 = -0x400;
    break;
  case 0x25:
    value2 = (localState2 - localState8) * (localState2 - localState8) +
            (localState3 - localState9) * (localState3 - localState9) +
            (localState4 - localState10) * (localState4 - localState10);
    localState19 = -0x400;
    localState18 = localState19;
    localState17 = localState19;
    goto LAB_00443da3;
  case 0x26:
    value2 = (localState2 - localState8) * (localState2 - localState8) +
            (localState3 - localState9) * (localState3 - localState9) +
            (localState4 - localState13) * (localState4 - localState13);
    localState19 = 0x400;
    localState18 = -0x400;
    localState17 = -0x400;
LAB_00443da3:
    if (flagByte) {
      TransformShortVectorByBasis(value,&localState19,&localState19);
    }
    goto LAB_004442b7;
  case 0x28:
    value2 = (localState2 - localState11) * (localState2 - localState11) +
            (localState3 - localState9) * (localState3 - localState9);
    localState18 = -0x400;
    localState17 = 0x400;
    goto LAB_00443e23;
  case 0x29:
    value2 = (localState2 - localState11) * (localState2 - localState11) +
            (localState3 - localState9) * (localState3 - localState9) +
            (localState4 - localState10) * (localState4 - localState10);
    localState19 = -0x400;
    localState18 = -0x400;
    localState17 = 0x400;
    break;
  case 0x2a:
    localState17 = 0x400;
    value2 = (localState2 - localState11) * (localState2 - localState11) +
            (localState3 - localState9) * (localState3 - localState9) +
            (localState4 - localState13) * (localState4 - localState13);
    localState19 = 0x400;
    localState18 = -0x400;
  }
  if (flagByte) {
    TransformShortVectorByBasis(value,&localState19,&localState19);
  }
LAB_004442b7:
  if (value2 <= (int)sceneObject[3] * (int)sceneObject[3]) {
    if (value2 == -1) {
      *arg6 = 0;
      arg6[2] = 0;
      arg6[1] = 0;
      return 1;
    }
    if (0 < value2) {
      value = SqrtToInt(value2);
      if (value >> 6 < (int)sceneObject[3]) {
        value = (int)sceneObject[3] - (value >> 6);
        *arg6 = localState19 * value >> 10;
        arg6[1] = localState18 * value >> 10;
        arg6[2] = localState17 * value >> 10;
      }
      return 1;
    }
    arg6[1] = 0;
    arg6[2] = 0;
    *arg6 = 0;
  }
  return 0;
}

