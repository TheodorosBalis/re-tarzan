#include "tarzan_ghidra_types.hpp"

// Address: 0x00441B60
// Label: CEntities::AdvanceScriptAttachmentSequence
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::AdvanceScriptAttachmentSequence(uint *entry)

{
  uint value;
  uint value2;
  short shortValue;
  
  if ((*entry & 0xff) == 1) {
    value = entry[4];
    if (value != 0) {
      *(short *)(entry + 6) = (short)entry[6] + 1;
      while( true ) {
        value2 = *(uint *)(value + (short)entry[6] * 4);
        if (value2 != 0) break;
        shortValue = (short)entry[6] + 1;
        *(short *)(entry + 6) = shortValue;
        *(undefined2 *)(entry + 6) = *(undefined2 *)(value + shortValue * 4);
      }
      entry[3] = value2;
    }
    *(undefined2 *)((int)entry + 0x16) = 0;
    *(undefined2 *)(entry + 5) = 0xffff;
  }
  else if ((*entry & 0xff) == 2) {
    value = entry[4];
    if (value != 0) {
      *(short *)(entry + 6) = (short)entry[6] + 1;
      while( true ) {
        value2 = *(uint *)(value + (short)entry[6] * 4);
        if (value2 != 0) break;
        shortValue = (short)entry[6] + 1;
        *(short *)(entry + 6) = shortValue;
        *(undefined2 *)(entry + 6) = *(undefined2 *)(value + shortValue * 4);
      }
      entry[3] = value2;
    }
    *(undefined2 *)((int)entry + 0x16) = 0xffff;
    *(undefined2 *)(entry + 5) = 0xffff;
    return 0;
  }
  return 0;
}

