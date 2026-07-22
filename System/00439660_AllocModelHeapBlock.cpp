#include "tarzan_ghidra_types.hpp"

// Address: 0x00439660
// Label: AllocModelHeapBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined2 * AllocModelHeapBlock(undefined4 arg1,undefined4 arg2)

{
  undefined2 *dataCursor;
  
  dataCursor = (undefined2 *)AllocModelHeapBlockHeader(arg1,arg2);
  if (dataCursor == (undefined2 *)0x0) {
    CompactModelHeapForAllocation(arg2);
    dataCursor = (undefined2 *)AllocModelHeapBlockHeader(arg1,arg2);
    if (dataCursor == (undefined2 *)0x0) {
      InternalError(s_mal_perm___004ed428);
      UpdateModelHeapStats();
      return (undefined2 *)0x0;
    }
  }
  *(undefined4 *)(dataCursor + 2) = 0xffffffff;
  *dataCursor = 0;
  return dataCursor + 0xc;
}

