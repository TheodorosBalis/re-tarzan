#include "tarzan_ghidra_types.hpp"

// Address: 0x00443290
// Label: CEntities::ComputeLocalAttachmentBoundsPushVector
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::ComputeLocalAttachmentBoundsPushVector
              (int entry,short *sceneObject,int attachment,short *flags,undefined2 *arg5,
              int *arg6)

{
  undefined2 value2;
  byte flagByte;
  uint value3;
  int value;
  short localState17;
  short localState16;
  short localState15;
  int localState14;
  int localState13;
  int localState12;
  int localState11;
  int localState10;
  int localState9;
  int localState8;
  int localState7;
  undefined4 localState6;
  int localState5;
  int localState4;
  int localState3;
  undefined4 localState2;
  undefined1 localState [32];
  
  localState9 = (int)*sceneObject;
  localState8 = (int)sceneObject[1];
  localState7 = (int)sceneObject[2];
  TransformVectorByBasis(entry + 0xb8,&localState9,&localState9);
  localState8 = arg6[1] - *(int *)(attachment + 0x18);
  localState7 = arg6[2] - *(int *)(attachment + 0x1c);
  localState9 = *arg6 - *(int *)(attachment + 0x14);
  localState11 = (int)flags[1];
  localState13 = (int)flags[4];
  localState10 = (int)flags[2] * *(int *)(attachment + 0xb0) >> 0xc;
  localState14 = (int)flags[3] * *(int *)(attachment + 0xa8) >> 0xc;
  localState12 = (int)flags[5] * *(int *)(attachment + 0xb0) >> 0xc;
  localState17 = -*(short *)(attachment + 0xa0);
  localState16 = -*(short *)(attachment + 0xa2);
  localState15 = -*(short *)(attachment + 0xa4);
  value = (int)*flags * *(int *)(attachment + 0xa8) >> 0xc;
  localState2 = localState6;
  localState5 = localState9;
  localState4 = localState8;
  localState3 = localState7;
  if (*(short *)(attachment + 0xa6) == 0) {
    BuildRotationBasisFromEulerAngles(&localState17,localState);
    TransformVectorByBasis(localState,&localState9,&localState5);
  }
  if (*(short *)(attachment + 0xa6) == 1) {
    BuildRotationMatrixFromEulerAngles12Bit(&localState17,localState);
    TransformVectorByBasis(localState,&localState9,&localState5);
  }
  flagByte = localState5 < value;
  if (localState4 < localState13) {
    return -1;
  }
  if (localState3 < localState10) {
    flagByte = flagByte | 4;
  }
  if (localState14 < localState5) {
    flagByte = flagByte | 2;
  }
  if (localState11 < localState4) {
    flagByte = flagByte | 0x20;
  }
  if (localState12 < localState3) {
    flagByte = flagByte | 8;
  }
  switch(flagByte) {
  case 0:
    *arg5 = 0;
    arg5[1] = 0;
    arg5[2] = 0;
    TransformShortVectorByBasis(attachment + 0xb8,arg5,arg5);
    return 0;
  case 1:
    value = (localState5 - value) * (localState5 - value);
    value2 = 0;
    *arg5 = 0xfc00;
    arg5[1] = 0;
    goto LAB_004439dd;
  case 2:
    value3 = localState5 - localState14 >> 0x1f;
    value = (localState5 - localState14 ^ value3) - value3;
    value = value * value;
    value2 = 0;
    *arg5 = 0x400;
    arg5[1] = 0;
    goto LAB_004439dd;
  default:
    goto switchD_00443471_caseD_3;
  case 4:
    value3 = localState3 - localState10 >> 0x1f;
    value = (localState3 - localState10 ^ value3) - value3;
    value = value * value;
    *arg5 = 0;
    arg5[1] = 0;
    arg5[2] = 0xfc00;
    break;
  case 5:
    value = (localState3 - localState10) * (localState3 - localState10) + (localState5 - value) * (localState5 - value);
    value2 = 0xfc00;
    *arg5 = 0xfc00;
    arg5[1] = 0;
    goto LAB_004439dd;
  case 6:
    value = (localState3 - localState10) * (localState3 - localState10) +
            (localState5 - localState14) * (localState5 - localState14);
    *arg5 = 0x400;
    arg5[1] = 0;
    arg5[2] = 0xfc00;
    break;
  case 8:
    value3 = localState3 - localState12 >> 0x1f;
    value = (localState3 - localState12 ^ value3) - value3;
    value = value * value;
    *arg5 = 0;
    arg5[1] = 0;
    arg5[2] = 0x400;
    break;
  case 9:
    value = (localState3 - localState12) * (localState3 - localState12) + (localState5 - value) * (localState5 - value);
    *arg5 = 0xfc00;
    arg5[1] = 0;
    arg5[2] = 0x400;
    break;
  case 10:
    value = (localState3 - localState12) * (localState3 - localState12) +
            (localState5 - localState14) * (localState5 - localState14);
    value2 = 0x400;
    *arg5 = 0x400;
    arg5[1] = 0;
    goto LAB_004439dd;
  case 0x10:
    value3 = localState4 - localState13 >> 0x1f;
    value = (localState4 - localState13 ^ value3) - value3;
    value = value * value;
    *arg5 = 0;
    arg5[1] = 0x400;
    arg5[2] = 0;
    break;
  case 0x11:
    value = (localState13 - localState4) * (localState13 - localState4) + (localState5 - value) * (localState5 - value);
    *arg5 = 0xfc00;
    arg5[1] = 0x400;
    arg5[2] = 0;
    break;
  case 0x12:
    value = (localState4 - localState13) * (localState4 - localState13) +
            (localState5 - localState14) * (localState5 - localState14);
    value2 = 0x400;
    goto LAB_0044377c;
  case 0x14:
    value = (localState3 - localState10) * (localState3 - localState10) +
            (localState4 - localState13) * (localState4 - localState13);
    *arg5 = 0;
    arg5[1] = 0x400;
    arg5[2] = 0xfc00;
    break;
  case 0x15:
    value2 = 0xfc00;
    value = (localState3 - localState10) * (localState3 - localState10) +
            (localState4 - localState13) * (localState4 - localState13) + (localState5 - value) * (localState5 - value);
    *arg5 = 0xfc00;
    arg5[1] = 0x400;
    goto LAB_004439dd;
  case 0x16:
    value = (localState3 - localState10) * (localState3 - localState10) +
            (localState4 - localState13) * (localState4 - localState13) +
            (localState5 - localState14) * (localState5 - localState14);
    *arg5 = 0x400;
    arg5[1] = 0x400;
    arg5[2] = 0xfc00;
    break;
  case 0x18:
    value = (localState3 - localState12) * (localState3 - localState12) +
            (localState4 - localState13) * (localState4 - localState13);
    value2 = 0x400;
    *arg5 = 0;
    arg5[1] = 0x400;
    goto LAB_004439dd;
  case 0x19:
    value2 = 0x400;
    value = (localState3 - localState12) * (localState3 - localState12) +
            (localState4 - localState13) * (localState4 - localState13) + (localState5 - value) * (localState5 - value);
    *arg5 = 0xfc00;
    arg5[1] = 0x400;
    goto LAB_004439dd;
  case 0x1a:
    value2 = 0x400;
    value = (localState3 - localState12) * (localState3 - localState12) +
            (localState4 - localState13) * (localState4 - localState13) +
            (localState5 - localState14) * (localState5 - localState14);
    *arg5 = 0x400;
    arg5[1] = 0x400;
    goto LAB_004439dd;
  case 0x20:
    value3 = localState4 - localState11 >> 0x1f;
    value = (localState4 - localState11 ^ value3) - value3;
    value = value * value;
    *arg5 = 0;
    arg5[1] = 0xfc00;
    arg5[2] = 0;
    break;
  case 0x21:
    value = (localState4 - localState11) * (localState4 - localState11) + (localState5 - value) * (localState5 - value);
    value2 = 0xfc00;
LAB_0044377c:
    *arg5 = value2;
    arg5[1] = value2;
    arg5[2] = 0;
    break;
  case 0x22:
    value = (localState4 - localState11) * (localState4 - localState11) +
            (localState5 - localState14) * (localState5 - localState14);
    *arg5 = 0x400;
    arg5[1] = 0xfc00;
    arg5[2] = 0;
    break;
  case 0x24:
    value2 = 0xfc00;
    value = (localState3 - localState10) * (localState3 - localState10) +
            (localState4 - localState11) * (localState4 - localState11);
    *arg5 = 0;
    arg5[1] = 0xfc00;
    goto LAB_004439dd;
  case 0x25:
    value2 = 0xfc00;
    value = (localState3 - localState10) * (localState3 - localState10) +
            (localState4 - localState11) * (localState4 - localState11) + (localState5 - value) * (localState5 - value);
    *arg5 = 0xfc00;
    arg5[1] = 0xfc00;
    goto LAB_004439dd;
  case 0x26:
    value2 = 0xfc00;
    value = (localState3 - localState10) * (localState3 - localState10) +
            (localState4 - localState11) * (localState4 - localState11) +
            (localState5 - localState14) * (localState5 - localState14);
    *arg5 = 0x400;
    arg5[1] = 0xfc00;
    goto LAB_004439dd;
  case 0x28:
    value = (localState3 - localState12) * (localState3 - localState12) +
            (localState4 - localState11) * (localState4 - localState11);
    *arg5 = 0;
    arg5[1] = 0xfc00;
    arg5[2] = 0x400;
    break;
  case 0x29:
    value = (localState3 - localState12) * (localState3 - localState12) +
            (localState4 - localState11) * (localState4 - localState11) + (localState5 - value) * (localState5 - value);
    *arg5 = 0xfc00;
    arg5[1] = 0xfc00;
    arg5[2] = 0x400;
    break;
  case 0x2a:
    value2 = 0x400;
    value = (localState3 - localState12) * (localState3 - localState12) +
            (localState4 - localState11) * (localState4 - localState11) +
            (localState5 - localState14) * (localState5 - localState14);
    *arg5 = 0x400;
    arg5[1] = 0xfc00;
LAB_004439dd:
    arg5[2] = value2;
  }
  TransformShortVectorByBasis(attachment + 0xb8,arg5,arg5);
  if (value < 0x4001) {
    return value;
  }
switchD_00443471_caseD_3:
  return -1;
}

