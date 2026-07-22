#include "tarzan_ghidra_types.hpp"

// Address: 0x004458B0
// Label: TransformSceneAttachmentToWorld
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TransformSceneAttachmentToWorld(undefined4 arg1,int arg2,int *arg3)

{
  short shortValue;
  short scratchTransform3;
  short scratchTransform2;
  short scratchTransform;
  
  if (FrameCount != *(int *)(arg2 + 0xf8)) {
    *(int *)(arg2 + 0xf8) = FrameCount;
    shortValue = *(short *)(arg2 + 0xa6);
    if (shortValue == 0) {
      BuildBasisMatrixFromEulerAngles(arg2 + 0xa0,arg2 + 0xb8);
    }
    else if (shortValue == 1) {
      BuildSceneNodeMode1BasisFromEulerAngles(arg2 + 0xa0,arg2 + 0xb8);
    }
    else if (shortValue == 2) {
      BuildRotationBasisFromEulerAngles(arg2 + 0xa0,arg2 + 0xb8);
    }
    if (*(int *)(arg2 + 0xb4) != 0) {
      ScaleBasisAxesClamped(arg2 + 0xb8,arg2 + 0xa8);
    }
  }
  TransformShortVectorByBasis(arg2 + 0xb8,arg1,&scratchTransform3);
  *arg3 = *(int *)(arg2 + 0x14) + (int)scratchTransform3;
  arg3[1] = *(int *)(arg2 + 0x18) + (int)scratchTransform2;
  arg3[2] = *(int *)(arg2 + 0x1c) + (int)scratchTransform;
  return;
}

