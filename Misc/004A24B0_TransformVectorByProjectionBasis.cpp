#include "tarzan_ghidra_types.hpp"

// Address: 0x004A24B0
// Label: TransformVectorByProjectionBasis
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TransformVectorByProjectionBasis(short *arg1,short *arg2,int *arg3)

{
  int value;
  int value2;
  int value3;
  
  SetProjectionBasisMatrixThunk(arg1);
  value = (int)*arg2;
  value2 = (int)arg2[1];
  value3 = (int)arg2[2];
  *arg3 = arg1[2] * value3 + arg1[1] * value2 + *arg1 * value >> 0xc;
  arg3[1] = arg1[5] * value3 + arg1[4] * value2 + arg1[3] * value >> 0xc;
  arg3[2] = arg1[8] * value3 + arg1[7] * value2 + arg1[6] * value >> 0xc;
  return;
}

