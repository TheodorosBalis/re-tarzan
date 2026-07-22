#include "tarzan_ghidra_types.hpp"

// Address: 0x00441AB0
// Label: IsWorldPositionOutsideOuterActivationBounds
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 IsWorldPositionOutsideOuterActivationBounds(int *arg1)

{
  int result;
  undefined3 value;
  
  result = *arg1;
  value = (undefined3)((uint)result >> 8);
  if (result < g_RuntimeOuterActivationBounds) {
    return CONCAT31(value,1);
  }
  if (g_RuntimeOuterActivationMaxX < result) {
    return CONCAT31(value,1);
  }
  result = arg1[2];
  value = (undefined3)((uint)result >> 8);
  if (result < g_RuntimeOuterActivationMinZ) {
    return CONCAT31(value,1);
  }
  return CONCAT31(value,g_RuntimeOuterActivationMaxZ < result);
}

