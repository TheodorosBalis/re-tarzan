#include "tarzan_ghidra_types.hpp"

// Address: 0x00441A60
// Label: IsEntitySourceRefOutsideOuterActivationBounds
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 IsEntitySourceRefOutsideOuterActivationBounds(undefined4 arg1)

{
  int result;
  
  result = CEntities::FindEntityAttachmentByFlags(arg1,0x200);
  if (result != 0) {
    if (*(int *)(result + 0xc) < g_RuntimeOuterActivationBounds) {
      return 1;
    }
    if (g_RuntimeOuterActivationMaxX < *(int *)(result + 0xc)) {
      return 1;
    }
    if (*(int *)(result + 0x14) < g_RuntimeOuterActivationMinZ) {
      return 1;
    }
    if (g_RuntimeOuterActivationMaxZ < *(int *)(result + 0x14)) {
      return 1;
    }
  }
  return 0;
}

