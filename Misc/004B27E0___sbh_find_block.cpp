#include "tarzan_ghidra_types.hpp"

// Address: 0x004B27E0
// Label: __sbh_find_block
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint __sbh_find_block(int arg1)

{
  uint value;
  
  value = mallocPTR;
  while( true ) {
    if (mallocPTR + g_CrtSmallBlockHeapRegionCount * 0x14 <= value) {
      return 0;
    }
    if ((uint)(arg1 - *(int *)(value + 0xc)) < 0x100000) break;
    value = value + 0x14;
  }
  return value;
}

