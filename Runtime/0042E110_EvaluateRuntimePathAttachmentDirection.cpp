#include "tarzan_ghidra_types.hpp"

// Address: 0x0042E110
// Label: EvaluateRuntimePathAttachmentDirection
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 EvaluateRuntimePathAttachmentDirection(int *arg1,int arg2)

{
  Entity *entity2 = (Entity *)arg2;
  int value;
  int value2;
  int value3;
  int value4;
  undefined2 scratchRect7;
  short scratchRect6;
  undefined2 scratchRect5;
  int scratchRect4;
  int scratchRect3;
  int scratchRect2;
  undefined1 scratchRect [32];
  
  value = CEntities::FindEntityAttachmentByFlags(arg2,0x40000000);
  if (value != 0) {
    value4 = arg1[7] - *arg1;
    value3 = arg1[9] - arg1[2];
    value2 = SqrtToInt(value3 * value3 + (arg1[8] - arg1[1]) * (arg1[8] - arg1[1]) +
                      value4 * value4);
    value2 = value2 >> 6;
    scratchRect7 = 0;
    scratchRect6 = GetAngleFromXZVector12Bit(value4,value3);
    scratchRect6 = -scratchRect6;
    value3 = entity2->sceneObjects;
    scratchRect5 = 0;
    scratchRect4 = ((EntitySceneObject *)value3)->x - *arg1;
    scratchRect3 = ((EntitySceneObject *)value3)->y - arg1[1];
    scratchRect2 = ((EntitySceneObject *)value3)->z - arg1[2];
    BuildBasisMatrixFromEulerAngles(&scratchRect7,scratchRect);
    TransformVectorByBasis(scratchRect,&scratchRect4,&scratchRect4);
    *(int *)(value + 0x1c) = (int)scratchRect6;
    *(int *)(value + 0x20) = scratchRect4;
    *(int *)(value + 0x28) = scratchRect2;
    if (value2 != 0) {
      *(int *)(value + 0x24) =
           (((scratchRect2 << 8) / value2) * (arg1[8] - arg1[1]) >> 8) + arg1[1];
    }
    value = *(int *)(value + 0x30);
    if ((value == 1) && (scratchRect2 < 1)) {
      return 2;
    }
    if (value == 2) {
      if (scratchRect2 < 0) {
        return 2;
      }
      if (value2 + 0x100 < scratchRect2) {
        return 1;
      }
    }
    if ((value == 0) && (value2 < scratchRect2)) {
      return 1;
    }
  }
  return 0xffffffff;
}

