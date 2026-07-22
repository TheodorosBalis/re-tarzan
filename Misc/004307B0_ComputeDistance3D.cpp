#include "tarzan_ghidra_types.hpp"

// Address: 0x004307B0
// Label: ComputeDistance3D
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ComputeDistance3D(int arg1,int arg2,int arg3,int arg4,int arg5,int arg6)

{
  int value;
  
  value = SqrtToInt((arg3 - arg6) * (arg3 - arg6) +
                    (arg2 - arg5) * (arg2 - arg5) +
                    (arg1 - arg4) * (arg1 - arg4));
  return value >> 6;
}

