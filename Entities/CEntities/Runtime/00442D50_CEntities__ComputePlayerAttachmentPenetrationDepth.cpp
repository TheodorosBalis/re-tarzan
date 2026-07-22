#include "tarzan_ghidra_types.hpp"

// Address: 0x00442D50
// Label: CEntities::ComputePlayerAttachmentPenetrationDepth
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::ComputePlayerAttachmentPenetrationDepth
              (int entry,short *sceneObject,int attachment,short *flags)

{
  int value;
  byte flagByte;
  uint value5;
  int value2;
  int value3;
  int value4;
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
  value4 = 0x7ffffff;
  if (*(short *)(entry + 0xa6) != 3) {
    TransformVectorByBasis(entry + 0xb8,&localState9,&localState9);
  }
  localState9 = ((localState9 + *(int *)(entry + 0x14)) -
             (*(int *)(attachment + 0x3c) + *(int *)(attachment + 0x14))) + *(int *)(entry + 0x3c);
  localState8 = ((localState8 + *(int *)(entry + 0x18)) -
             (*(int *)(attachment + 0x40) + *(int *)(attachment + 0x18))) + *(int *)(entry + 0x40);
  localState7 = ((localState7 + *(int *)(entry + 0x1c)) -
             (*(int *)(attachment + 0x44) + *(int *)(attachment + 0x1c))) + *(int *)(entry + 0x44);
  localState11 = (int)flags[1];
  localState10 = (int)flags[2];
  localState14 = (int)flags[3];
  value3 = (int)*flags;
  localState13 = (int)flags[4];
  value2 = (int)flags[5];
  if (*(int *)(attachment + 0xb4) == 1) {
    value3 = *(int *)(attachment + 0xa8) * value3 >> 0xc;
    localState11 = *(int *)(attachment + 0xac) * localState11 >> 0xc;
    localState10 = *(int *)(attachment + 0xb0) * localState10 >> 0xc;
    localState14 = *(int *)(attachment + 0xa8) * localState14 >> 0xc;
    localState13 = *(int *)(attachment + 0xac) * localState13 >> 0xc;
    value2 = *(int *)(attachment + 0xb0) * value2 >> 0xc;
  }
  localState12 = value2;
  if (*(short *)(attachment + 0xa6) == 3) {
    localState2 = localState6;
    localState5 = localState9;
    localState4 = localState8;
    localState3 = localState7;
  }
  else {
    localState17 = -*(short *)(attachment + 0xa0);
    localState16 = -*(short *)(attachment + 0xa2);
    localState15 = -*(short *)(attachment + 0xa4);
    BuildRotationMatrixFromEulerAngles12Bit(&localState17,localState);
    TransformVectorByBasis(localState,&localState9,&localState5);
  }
  flagByte = localState5 < value3;
  if (localState4 < localState13) {
    flagByte = flagByte | 0x10;
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
  if (value2 < localState3) {
    flagByte = flagByte | 8;
  }
  value2 = localState10;
  value = localState13;
  switch(flagByte) {
  case 0:
    value4 = 0x7fffffff;
    break;
  case 1:
    value5 = localState5 - value3 >> 0x1f;
    value4 = (localState5 - value3 ^ value5) - value5;
    value4 = value4 * value4;
    break;
  case 2:
    value5 = localState5 - localState14 >> 0x1f;
    value4 = (localState5 - localState14 ^ value5) - value5;
    value4 = value4 * value4;
    break;
  case 4:
    value5 = localState3 - localState10 >> 0x1f;
    value4 = (localState3 - localState10 ^ value5) - value5;
    value4 = value4 * value4;
    break;
  case 5:
    value4 = (localState3 - localState10) * (localState3 - localState10) + (localState5 - value3) * (localState5 - value3);
    break;
  case 6:
    value4 = (localState3 - localState10) * (localState3 - localState10) +
            (localState5 - localState14) * (localState5 - localState14);
    break;
  case 8:
    value5 = localState3 - localState12 >> 0x1f;
    value4 = (localState3 - localState12 ^ value5) - value5;
    value4 = value4 * value4;
    break;
  case 9:
    goto LAB_00443180;
  case 10:
    value3 = localState14;
LAB_00443180:
    value4 = (localState3 - localState12) * (localState3 - localState12) + (localState5 - value3) * (localState5 - value3);
    break;
  case 0x10:
    value5 = localState4 - localState13 >> 0x1f;
    value4 = (localState4 - localState13 ^ value5) - value5;
    value4 = value4 * value4;
    break;
  case 0x11:
    value4 = (localState4 - localState13) * (localState4 - localState13) + (localState5 - value3) * (localState5 - value3);
    break;
  case 0x12:
    value4 = (localState4 - localState13) * (localState4 - localState13) +
            (localState5 - localState14) * (localState5 - localState14);
    break;
  case 0x14:
    value4 = (localState3 - localState10) * (localState3 - localState10) +
            (localState4 - localState13) * (localState4 - localState13);
    break;
  case 0x15:
    value3 = localState5 - value3;
    value = localState4 - localState13;
    goto LAB_004431a2;
  case 0x16:
    value3 = localState5 - localState14;
    value = localState4 - localState13;
    goto LAB_004431a2;
  case 0x18:
    value4 = (localState3 - localState12) * (localState3 - localState12) +
            (localState4 - localState13) * (localState4 - localState13);
    break;
  case 0x19:
    value3 = localState5 - value3;
    goto LAB_0044319c;
  case 0x1a:
    value3 = localState5 - localState14;
    goto LAB_0044319c;
  case 0x20:
    value5 = localState4 - localState11 >> 0x1f;
    value4 = (localState4 - localState11 ^ value5) - value5;
    value4 = value4 * value4;
    break;
  case 0x21:
    value3 = localState5 - value3;
    value4 = (localState4 - localState11) * (localState4 - localState11);
    goto LAB_004431b0;
  case 0x22:
    value3 = localState5 - localState14;
    value4 = (localState4 - localState11) * (localState4 - localState11);
    goto LAB_004431b0;
  case 0x24:
    value4 = (localState3 - localState10) * (localState3 - localState10) +
            (localState4 - localState11) * (localState4 - localState11);
    break;
  case 0x25:
    value3 = localState5 - value3;
    value = localState4 - localState11;
    goto LAB_004431a2;
  case 0x26:
    value3 = localState5 - localState14;
    value = localState4 - localState11;
    goto LAB_004431a2;
  case 0x28:
    value4 = (localState3 - localState12) * (localState3 - localState12) +
            (localState4 - localState11) * (localState4 - localState11);
    break;
  case 0x29:
    goto LAB_00443198;
  case 0x2a:
    value3 = localState14;
LAB_00443198:
    value3 = localState5 - value3;
    value = localState11;
LAB_0044319c:
    value = localState4 - value;
    value2 = localState12;
LAB_004431a2:
    value4 = (localState3 - value2) * (localState3 - value2) + value * value;
LAB_004431b0:
    value4 = value4 + value3 * value3;
  }
  if (value4 <= (int)sceneObject[3] * (int)sceneObject[3]) {
    value4 = SqrtToInt(value4);
    return (int)sceneObject[3] - (value4 >> 6);
  }
  return 0;
}

