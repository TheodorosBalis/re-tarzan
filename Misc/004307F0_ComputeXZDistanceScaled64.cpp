#include "tarzan_ghidra_types.hpp"

// Address: 0x004307F0
// Label: ComputeXZDistanceScaled64
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ComputeXZDistanceScaled64
              (int arg1,undefined4 arg2,int arg3,int arg4,undefined4 arg5,int arg6
              )

{
  int value;
  
  value = SqrtToInt((arg3 - arg6) * (arg3 - arg6) +
                    (arg1 - arg4) * (arg1 - arg4));
  return value >> 6;
}

