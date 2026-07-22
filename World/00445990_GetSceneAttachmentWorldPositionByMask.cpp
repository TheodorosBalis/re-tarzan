#include "tarzan_ghidra_types.hpp"

// Address: 0x00445990
// Label: GetSceneAttachmentWorldPositionByMask
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int GetSceneAttachmentWorldPositionByMask(int arg1,undefined4 arg2,int *arg3)

{
  short shortValue;
  int entry;
  short localState3;
  short localState2;
  short localState;
  
  entry = GetEntitySceneObjectAttachmentBlock(arg1);
  if ((entry != 0) && (entry = FindSceneAttachmentByMask(entry,arg2), entry != 0)) {
    if (FrameCount != *(int *)(arg1 + 0xf8)) {
      *(int *)(arg1 + 0xf8) = FrameCount;
      shortValue = *(short *)(arg1 + 0xa6);
      if (shortValue == 0) {
        BuildBasisMatrixFromEulerAngles(arg1 + 0xa0,arg1 + 0xb8);
      }
      else if (shortValue == 1) {
        BuildSceneNodeMode1BasisFromEulerAngles(arg1 + 0xa0,arg1 + 0xb8);
      }
      else if (shortValue == 2) {
        BuildRotationBasisFromEulerAngles(arg1 + 0xa0,arg1 + 0xb8);
      }
      if (*(int *)(arg1 + 0xb4) != 0) {
        ScaleBasisAxesClamped(arg1 + 0xb8,arg1 + 0xa8);
      }
    }
    TransformShortVectorByBasis(arg1 + 0xb8,entry,&localState3);
    *arg3 = *(int *)(arg1 + 0x14) + (int)localState3;
    arg3[1] = *(int *)(arg1 + 0x18) + (int)localState2;
    arg3[2] = *(int *)(arg1 + 0x1c) + (int)localState;
    return entry;
  }
  return 0;
}

