#include "tarzan_ghidra_types.hpp"

// Address: 0x00453B40
// Label: ResetEntitySoundSlotLists
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetEntitySoundSlotLists(void)

{
  undefined *dataCursor;
  undefined *dataCursor2;
  int slotIndex;
  
  StopAllSoundChannelsAndResetAudioLine();
  slotIndex = 0xf;
  dataCursor = &DAT_00533cd0;
  do {
    dataCursor2 = dataCursor;
    slotIndex = slotIndex + -1;
    *(undefined **)(dataCursor2 + 0x18) = dataCursor2 + 0x30;
    dataCursor = dataCursor2 + 0x30;
  } while (slotIndex != 0);
  *(undefined4 *)(dataCursor2 + 0x48) = 0;
  g_ActiveEntitySoundSlotList = 0;
  g_FreeEntitySoundSlotList = &DAT_00533cd0;
  return;
}

