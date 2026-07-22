#include "tarzan_ghidra_types.hpp"

// Address: 0x00453B70
// Label: AcquireEntitySoundSlot
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void AcquireEntitySoundSlot(void)

{
  int *slotCursor;
  undefined4 *dataCursor;
  
  dataCursor = g_FreeEntitySoundSlotList;
  if (g_FreeEntitySoundSlotList == (undefined4 *)0x0) {
    return;
  }
  slotCursor = g_FreeEntitySoundSlotList + 6;
  g_FreeEntitySoundSlotList = (undefined4 *)g_FreeEntitySoundSlotList[6];
  *slotCursor = g_ActiveEntitySoundSlotList;
  dataCursor[5] = 0;
  if (g_ActiveEntitySoundSlotList != 0) {
    *(undefined4 **)(g_ActiveEntitySoundSlotList + 0x14) = dataCursor;
  }
  *dataCursor = 0;
  return;
}

