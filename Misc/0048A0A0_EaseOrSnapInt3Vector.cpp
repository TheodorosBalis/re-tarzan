#include "tarzan_ghidra_types.hpp"

// Address: 0x0048A0A0
// Label: EaseOrSnapInt3Vector
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void EaseOrSnapInt3Vector(int *arg1,int *arg2,byte arg3,int arg4)

{
  int value;
  
  if (arg4 != 0) {
    *arg1 = *arg2;
    arg1[1] = arg2[1];
    arg1[2] = arg2[2];
    return;
  }
  value = 1 << (arg3 & 0x1f);
  *arg1 = ((*arg2 - *arg1) + value >> (arg3 & 0x1f)) + *arg1;
  arg1[1] = ((arg2[1] - arg1[1]) + value >> (arg3 & 0x1f)) + arg1[1];
  arg1[2] = ((arg2[2] - arg1[2]) + value >> (arg3 & 0x1f)) + arg1[2];
  return;
}

