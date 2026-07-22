#include "tarzan_ghidra_types.hpp"

// Address: 0x0042EE60
// Label: ClosestPointOnSegment3DAndDistanceSq
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ClosestPointOnSegment3DAndDistanceSq(int *arg1,int *arg2,int *arg3)

{
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int value7;
  
  value = arg1[7] - *arg1;
  value7 = arg1[8] - arg1[1];
  value3 = arg1[9] - arg1[2];
  value4 = value3 >> 2;
  value2 = value >> 2;
  value6 = value7 >> 2;
  value5 = value2 * value2 + value6 * value6 + value4 * value4 >> 0xc;
  if ((value5 != 0) &&
     (value5 = ((*arg2 - *arg1 >> 2) * value2 + (arg2[1] - arg1[1] >> 2) * value6 +
              (arg2[2] - arg1[2] >> 2) * value4) / value5, 0 < value5)) {
    if (0xfff < value5) {
      *arg3 = arg1[7];
      arg3[1] = arg1[8];
      value = arg1[9];
      arg3[2] = value;
      value = value - arg2[2];
      return value * value + (arg3[1] - arg2[1]) * (arg3[1] - arg2[1]) +
             (*arg3 - *arg2) * (*arg3 - *arg2);
    }
    *arg3 = (value * value5 >> 0xc) + *arg1;
    arg3[1] = (value7 * value5 >> 0xc) + arg1[1];
    value = arg1[2] + (value3 * value5 >> 0xc);
    arg3[2] = value;
    value = value - arg2[2];
    return value * value + (arg3[1] - arg2[1]) * (arg3[1] - arg2[1]) +
           (*arg3 - *arg2) * (*arg3 - *arg2);
  }
  *arg3 = *arg1;
  arg3[1] = arg1[1];
  value = arg1[2];
  arg3[2] = value;
  value = value - arg2[2];
  return value * value + (arg3[1] - arg2[1]) * (arg3[1] - arg2[1]) +
         (*arg3 - *arg2) * (*arg3 - *arg2);
}

