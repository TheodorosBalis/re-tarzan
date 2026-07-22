#include "tarzan_ghidra_types.hpp"

// Address: 0x00440660
// Label: CEntities::InitEntityAttachmentHeap
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::InitEntityAttachmentHeap(int entry)

{
  undefined4 *dataCursor;
  uint value;
  
  value = entry + 3U & 0xfffffffc;
  dataCursor = (undefined4 *)CompactAndAllocModelHeapBlock(value,&g_ModelLoadHeapState);
  if (dataCursor != (undefined4 *)0x0) {
    _g_EntityAttachmentHeapSentinel = 0;
    _g_EntityAttachmentHeapState_Field0010 = value | 2;
    _g_EntityAttachmentHeapState_Field0008 = 0;
    g_EntityAttachmentHeapEnd = (int)dataCursor + value;
    _g_EntityAttachmentHeapState_Field0014 = 0;
    _g_EntityAttachmentHeapState_Field0004 = dataCursor;
    g_EntityAttachmentFreeBlockHead = dataCursor;
    g_EntityAttachmentHeapStart = dataCursor;
    dataCursor[4] = value - 0x18 | 1;
    *dataCursor = &g_EntityAttachmentHeapSentinel;
    dataCursor[1] = 0;
    dataCursor[2] = &g_EntityAttachmentHeapSentinel;
    dataCursor[3] = 0;
    dataCursor[5] = 0;
    value = value - 0x30 >> 2;
    dataCursor = dataCursor + 6;
    do {
      *dataCursor = 0;
      dataCursor = dataCursor + 1;
      value = value - 1;
    } while (value != 0);
  }
  return;
}

