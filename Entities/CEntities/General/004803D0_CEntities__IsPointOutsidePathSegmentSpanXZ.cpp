#include "tarzan_ghidra_types.hpp"

// Address: 0x004803D0
// Label: CEntities::IsPointOutsidePathSegmentSpanXZ
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::IsPointOutsidePathSegmentSpanXZ(int *entry,int *sceneObject,int *attachment)

{
  int value;
  int value2;
  int value3;
  undefined2 localState6;
  short localState4;
  undefined2 localState5;
  int localState3;
  int localState2;
  int localState;
  undefined1 localState7 [32];
  
  value3 = entry[7] - *entry;
  value2 = entry[9] - entry[2];
  value = SqrtToInt(value2 * value2 + value3 * value3);
  localState6 = 0;
  localState4 = GetAngleFromXZVector12Bit(value3,value2);
  localState5 = 0;
  localState4 = -localState4;
  *attachment = (int)localState4;
  localState3 = *sceneObject - *entry;
  localState2 = sceneObject[1] - entry[1];
  localState = sceneObject[2] - entry[2];
  value2 = SqrtToInt(localState * localState + localState3 * localState3);
  BuildBasisMatrixFromEulerAngles(&localState6,localState7);
  TransformVectorByBasis(localState7,&localState3,&localState3);
  if ((localState < value >> 6) && (value2 >> 6 < value >> 6)) {
    return 0;
  }
  return 1;
}

