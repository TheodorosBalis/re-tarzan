#include "tarzan_ghidra_types.hpp"

// Address: 0x00440190
// Label: CEntities::InitializeEntityPoolAndLists
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitializeEntityPoolAndLists(void)

{
  undefined4 *dataCursor;
  int entry;
  undefined4 *dataCursor2;
  undefined4 *dataCursor3;
  
  dataCursor = g_EntityPoolBase;
  g_ActiveEntityListHead = 0;
  g_CollisionTriggerEntryListHead = 0;
  g_ActiveEntityListTail = g_EntityPoolBase;
  g_EntityEntryPool = g_EntityPoolBase;
  g_PlayerHeldThrowableEntity = 0;
  dataCursor2 = &g_EntityDefaultTemplate;
  dataCursor3 = g_EntityPoolBase;
  for (entry = 0x15; entry != 0; entry = entry + -1) {
    *dataCursor3 = *dataCursor2;
    dataCursor2 = dataCursor2 + 1;
    dataCursor3 = dataCursor3 + 1;
  }
  *dataCursor = 1;
  RebuildFreeEntityList();
  dataCursor = &DAT_00531cbc;
  do {
    dataCursor[-1] = 0;
    *dataCursor = 0;
    dataCursor = dataCursor + 2;
  } while ((int)dataCursor < 0x531d34);
  return;
}

