#include "tarzan_ghidra_types.hpp"

// Address: 0x0042EC80
// Label: ComputeDistanceSqToPathSegmentXZ
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ComputeDistanceSqToPathSegmentXZ(int *arg1,int *arg2,int *arg3)

{
  int value;
  uint value7;
  int value2;
  int value3;
  int value4;
  int value5;
  uint value8;
  int value6;
  int localState5;
  int localState4;
  int localState3;
  int localState2;
  int localState [2];
  int localState6;
  
  value3 = arg2[1];
  value4 = arg2[2] - arg1[2];
  localState4 = arg1[7] - *arg1;
  value5 = arg1[1];
  value2 = *arg2 - *arg1;
  localState3 = arg1[8] - value5;
  localState2 = arg1[9] - arg1[2];
  localState5 = 0;
  NormalizeVectorToFixed12(&localState4,localState);
  *arg3 = g_SinCosTable12Bit * localState6 + g_LevelEntityInitScratch_Field0388 * localState[0] >> 0xc;
  arg3[2] = g_LevelEntityInitScratch_Field0388 * localState6 - g_SinCosTable12Bit * localState[0] >>
               0xc;
  arg3[1] = 0;
  localState3 = localState3 >> 2;
  value6 = localState4 >> 2;
  value = localState2 >> 2;
  value7 = (value2 >> 2) * value6 + (value3 - value5 >> 2) * localState3 + (value4 >> 2) * value;
  value8 = value6 * value6 + localState3 * localState3 + value * value;
  if (((-1 < (int)value7) || ((int)value8 < 1)) && (((int)value7 < 1 || (-1 < (int)value8)))) {
    if ((int)((value8 ^ (int)value8 >> 0x1f) - ((int)value8 >> 0x1f)) <
        (int)((value7 ^ (int)value7 >> 0x1f) - ((int)value7 >> 0x1f))) {
      localState5 = 0x100;
    }
    else if ((value8 & 0xffffff00) != 0) {
      localState5 = (int)value7 / ((int)value8 >> 8);
    }
  }
  value5 = value4 - (localState2 * localState5 >> 8) >> 2;
  value3 = value2 - (localState4 * localState5 >> 8) >> 2;
  return value3 * value3 + value5 * value5;
}

