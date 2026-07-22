#include "tarzan_ghidra_types.hpp"

// Address: 0x0041C920
// Label: RequestEncodedSceneModelResourceLoad
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RequestEncodedSceneModelResourceLoad(int *arg1)

{
  int entry;
  undefined4 *dataCursor;
  int entry2;
  int entry3;
  undefined4 value;
  
  entry2 = *arg1;
  entry3 = *(int *)(entry2 + 0xc);
  if (entry3 != 0) {
    entry = arg1[2] * 8;
    if ((*(int *)(entry + 0x30 + entry2) == 0) && (*(int *)(entry + 0x2c + entry2) == -1)) {
      dataCursor = (undefined4 *)(*(int *)(entry3 + 0x20) + entry + 0x24 + entry3);
      value = QueueModelLoadRequestForSceneModelSlot
                        (arg1[1],*dataCursor,entry + 0x30 + entry2,dataCursor[1]);
      *(undefined4 *)(entry + 0x2c + entry2) = value;
    }
  }
  return;
}

