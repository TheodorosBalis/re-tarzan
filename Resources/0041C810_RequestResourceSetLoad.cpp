#include "tarzan_ghidra_types.hpp"

// Address: 0x0041C810
// Label: RequestResourceSetLoad
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RequestResourceSetLoad(int arg1)

{
  undefined4 value;
  
  if ((*(int *)(arg1 + 8) == -1) && (*(int *)(arg1 + 0xc) == 0)) {
    value = EnqueueAssetPayloadLoadRequest
                      (*(undefined4 *)(arg1 + 4),BuildResourceSetTextureRuntimeAfterLoad,arg1)
    ;
    *(undefined4 *)(arg1 + 8) = value;
  }
  return;
}

