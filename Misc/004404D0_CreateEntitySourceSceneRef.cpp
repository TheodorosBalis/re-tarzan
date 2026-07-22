#include "tarzan_ghidra_types.hpp"

// Address: 0x004404D0
// Label: CreateEntitySourceSceneRef
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CreateEntitySourceSceneRef(uint *arg1)

{
  undefined4 *dataCursor;
  int entry;
  undefined4 *dataCursor2;
  
  dataCursor = (undefined4 *)CEntities::AllocEntityAttachment(arg1,0x38,0x200,&DAT_00531d40);
  if (dataCursor != (undefined4 *)0x0) {
    *arg1 = *arg1 | 0x200;
    dataCursor2 = &DAT_00531d40;
    for (entry = 0xe; entry != 0; entry = entry + -1) {
      *dataCursor = *dataCursor2;
      dataCursor2 = dataCursor2 + 1;
      dataCursor = dataCursor + 1;
    }
  }
  return 0;
}

