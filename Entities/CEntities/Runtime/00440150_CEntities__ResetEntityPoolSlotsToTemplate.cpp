#include "tarzan_ghidra_types.hpp"

// Address: 0x00440150
// Label: CEntities::ResetEntityPoolSlotsToTemplate
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::ResetEntityPoolSlotsToTemplate(void)

{
  int slotIndex;
  int slotIndex2;
  int slotIndex3;
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  
  slotIndex3 = 0;
  if ((short)g_EntityPoolLimit != 0) {
    slotIndex = 0;
    do {
      slotIndex3 = slotIndex3 + 1;
      dataCursor = &g_EntityDefaultTemplate;
      dataCursor2 = (undefined4 *)(slotIndex + g_EntityPoolBase);
      for (slotIndex2 = 0x15; slotIndex2 != 0; slotIndex2 = slotIndex2 + -1) {
        *dataCursor2 = *dataCursor;
        dataCursor = dataCursor + 1;
        dataCursor2 = dataCursor2 + 1;
      }
      slotIndex = slotIndex + 0x54;
    } while (slotIndex3 < (int)(g_EntityPoolLimit & 0xffff));
  }
  return;
}

