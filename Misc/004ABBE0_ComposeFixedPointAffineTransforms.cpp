#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABBE0
// Label: ComposeFixedPointAffineTransforms
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComposeFixedPointAffineTransforms(int arg1,int arg2,int arg3)

{
  int *intCursor;
  
  MultiplyBasisMatrices(arg1,arg2,arg3);
  intCursor = (int *)(arg3 + 0x14);
  TransformVectorByBasis(arg1,arg2 + 0x14,intCursor);
  *intCursor = *intCursor + *(int *)(arg1 + 0x14);
  *(int *)(arg3 + 0x18) = *(int *)(arg3 + 0x18) + *(int *)(arg1 + 0x18);
  *(int *)(arg3 + 0x1c) = *(int *)(arg3 + 0x1c) + *(int *)(arg1 + 0x1c);
  return;
}

