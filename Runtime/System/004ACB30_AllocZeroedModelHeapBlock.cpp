#include "tarzan_ghidra_types.hpp"

// Address: 0x004ACB30
// Label: AllocZeroedModelHeapBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 * AllocZeroedModelHeapBlock(uint arg1)

{
  undefined4 *dataCursor;
  uint value;
  undefined4 *dataCursor2;
  
  if (0 < (int)arg1) {
    dataCursor = (undefined4 *)CompactAndAllocModelHeapBlock(arg1,&g_ModelLoadHeapState);
    if (dataCursor != (undefined4 *)0x0) {
      dataCursor2 = dataCursor;
      for (value = arg1 >> 2; value != 0; value = value - 1) {
        *dataCursor2 = 0;
        dataCursor2 = dataCursor2 + 1;
      }
      for (arg1 = arg1 & 3; arg1 != 0; arg1 = arg1 - 1) {
        *(undefined1 *)dataCursor2 = 0;
        dataCursor2 = (undefined4 *)((int)dataCursor2 + 1);
      }
    }
    return dataCursor;
  }
  return (undefined4 *)0x0;
}

