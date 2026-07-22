#include "tarzan_ghidra_types.hpp"

// Address: 0x0043F270
// Label: IsEntitySceneObjectInsideGroundAttachmentBounds
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 IsEntitySceneObjectInsideGroundAttachmentBounds(short *arg1,int arg2,int arg3)

{
  int result;
  int result2;
  int result3;
  int result4;
  int result5;
  short localState7;
  short localState6;
  short localState5;
  int localState4;
  int localState3;
  int localState2;
  undefined1 localState [32];
  
  localState4 = *(int *)(arg3 + 0x14) - *(int *)(arg2 + 0x14);
  localState3 = *(int *)(arg3 + 0x18) - *(int *)(arg2 + 0x18);
  localState2 = *(int *)(arg3 + 0x1c) - *(int *)(arg2 + 0x1c);
  localState7 = -*(short *)(arg2 + 0xa0);
  localState6 = -*(short *)(arg2 + 0xa2);
  localState5 = -*(short *)(arg2 + 0xa4);
  BuildRotationMatrixFromEulerAngles12Bit(&localState7,localState);
  TransformVectorByBasis(localState,&localState4,&localState4);
  if (*(int *)(arg2 + 0xb4) == 1) {
    result = (int)*arg1 * *(int *)(arg2 + 0xa8) >> 0xc;
    result4 = (int)arg1[2] * *(int *)(arg2 + 0xb0) >> 0xc;
    result2 = (int)arg1[1] * *(int *)(arg2 + 0xac) >> 0xc;
    result3 = (int)arg1[3] * *(int *)(arg2 + 0xa8) >> 0xc;
    result5 = (int)arg1[5] * *(int *)(arg2 + 0xb0) >> 0xc;
  }
  else {
    result = (int)*arg1;
    result2 = (int)arg1[1];
    result4 = (int)arg1[2];
    result3 = (int)arg1[3];
    result5 = (int)arg1[5];
  }
  if ((((localState3 < result2) && (result <= localState4)) && (localState4 <= result3)) &&
     ((result4 <= localState2 && (localState2 <= result5)))) {
    return 1;
  }
  return 0;
}

