#include "tarzan_ghidra_types.hpp"

// Address: 0x0042E400
// Label: IsEntitySceneObjectOutsidePathSegmentSpan
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 IsEntitySceneObjectOutsidePathSegmentSpan(int *arg1,int arg2)

{
  int result;
  int result2;
  int result3;
  undefined2 localState7;
  short localState6;
  undefined2 localState5;
  int localState4;
  int localState3;
  int localState2;
  undefined1 localState [32];
  
  result3 = arg1[7] - *arg1;
  result2 = arg1[9] - arg1[2];
  result = SqrtToInt(result2 * result2 + result3 * result3);
  localState7 = 0;
  localState6 = GetAngleFromXZVector12Bit(result3,result2);
  localState5 = 0;
  localState6 = -localState6;
  localState4 = *(int *)(arg2 + 0x14) - *arg1;
  localState3 = *(int *)(arg2 + 0x18) - arg1[1];
  localState2 = *(int *)(arg2 + 0x1c) - arg1[2];
  result2 = SqrtToInt(localState2 * localState2 + localState4 * localState4);
  BuildBasisMatrixFromEulerAngles(&localState7,localState);
  TransformVectorByBasis(localState,&localState4,&localState4);
  if ((localState2 < result >> 6) && (result2 >> 6 < result >> 6)) {
    return 0;
  }
  return 1;
}

