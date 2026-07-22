#include "tarzan_ghidra_types.hpp"

// Address: 0x004B273B
// Label: _heap_init
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 _heap_init(int arg1)

{
  int value;
  
  newHeapPTR = HeapCreate((uint)(arg1 == 0),0x1000,0);
  if (newHeapPTR != (HANDLE)0x0) {
    OsVerResult = __heap_select();
    if (OsVerResult == 3) {
      value = __sbh_heap_init(0x3f8);
    }
    else {
      if (OsVerResult != 2) {
        return 1;
      }
      value = InitializeVirtualSmallBlockHeapRegion();
    }
    if (value != 0) {
      return 1;
    }
    HeapDestroy(newHeapPTR);
  }
  return 0;
}

