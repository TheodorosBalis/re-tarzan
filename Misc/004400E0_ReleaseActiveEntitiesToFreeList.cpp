#include "tarzan_ghidra_types.hpp"

// Address: 0x004400E0
// Label: ReleaseActiveEntitiesToFreeList
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ReleaseActiveEntitiesToFreeList(void)

{
  char resultFlag;
  int value;
  uint value3;
  int value2;
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  
  value3 = _g_EntityEntryPoolEnd & 0xffff;
  if (value3 < (g_EntityPoolLimit & 0xffff)) {
    value2 = value3 * 0x54;
    do {
      dataCursor2 = (undefined4 *)(g_EntityPoolBase + value2);
      resultFlag = CEntities::ReleaseEntityToFreeList((byte *)dataCursor2);
      if (resultFlag != '\0') {
        dataCursor = &g_EntityDefaultTemplate;
        for (value = 0x15; value != 0; value = value + -1) {
          *dataCursor2 = *dataCursor;
          dataCursor = dataCursor + 1;
          dataCursor2 = dataCursor2 + 1;
        }
      }
      value3 = value3 + 1;
      value2 = value2 + 0x54;
    } while ((int)value3 < (int)(g_EntityPoolLimit & 0xffff));
  }
  RebuildFreeEntityList();
  return;
}

