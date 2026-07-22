#include "tarzan_ghidra_types.hpp"

// Address: 0x00453BB0
// Label: ReleaseEntitySoundSlot
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseEntitySoundSlot(int soundSlot)

{
  if (*(int *)(soundSlot + 0x18) != 0) {
    *(undefined4 *)(*(int *)(soundSlot + 0x18) + 0x14) = *(undefined4 *)(soundSlot + 0x14);
  }
  if (*(int *)(soundSlot + 0x14) != 0) {
    *(undefined4 *)(*(int *)(soundSlot + 0x14) + 0x18) = *(undefined4 *)(soundSlot + 0x18);
    *(int *)(soundSlot + 0x18) = g_FreeEntitySoundSlotList;
    g_FreeEntitySoundSlotList = soundSlot;
    return;
  }
  g_ActiveEntitySoundSlotList = *(undefined4 *)(soundSlot + 0x18);
  *(int *)(soundSlot + 0x18) = g_FreeEntitySoundSlotList;
  g_FreeEntitySoundSlotList = soundSlot;
  return;
}

