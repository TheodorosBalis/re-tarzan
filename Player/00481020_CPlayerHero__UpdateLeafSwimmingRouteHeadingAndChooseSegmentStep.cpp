#include "tarzan_ghidra_types.hpp"

// Address: 0x00481020
// Label: CPlayerHero::UpdateLeafSwimmingRouteHeadingAndChooseSegmentStep
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CPlayerHero::UpdateLeafSwimmingRouteHeadingAndChooseSegmentStep(int *arg1,int arg2)

{
  int value;
  int value2;
  int value3;
  undefined2 localState7;
  short localState6;
  undefined2 localState5;
  int localState4;
  int localState3;
  int localState2;
  undefined1 localState [32];
  
  value3 = arg1[7] - *arg1;
  value2 = arg1[9] - arg1[2];
  value = SqrtToInt(value2 * value2 + (arg1[8] - arg1[1]) * (arg1[8] - arg1[1]) +
                    value3 * value3);
  localState7 = 0;
  localState6 = GetAngleFromXZVector12Bit(value3,value2);
  localState6 = -localState6;
  localState5 = 0;
  localState4 = *(int *)(arg2 + 0x14) - *arg1;
  localState3 = *(int *)(arg2 + 0x18) - arg1[1];
  localState2 = *(int *)(arg2 + 0x1c) - arg1[2];
  BuildBasisMatrixFromEulerAngles(&localState7,localState);
  TransformVectorByBasis(localState,&localState4,&localState4);
  value2 = GetWrappedSignedAngleDelta12Bit((int)g_LeafSwimmingCameraOrbitAngle,(int)localState6);
  g_LeafSwimmingCameraOrbitAngle = g_LeafSwimmingCameraOrbitAngle + (short)(value2 >> 3);
  return ((localState2 <= value >> 6) - 1 & 2) - 1;
}

