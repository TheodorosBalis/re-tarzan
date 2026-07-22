#include "tarzan_ghidra_types.hpp"

// Address: 0x00453D60
// Label: FlushEntitySoundSlots
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void FlushEntitySoundSlots(void)

{
  int *slotCursor;
  int *slotCursor2;
  
  slotCursor2 = g_ActiveEntitySoundSlotList;
  while (slotCursor2 != (int *)0x0) {
    slotCursor = (int *)slotCursor2[6];
    if (*slotCursor2 == 0) {
      StopEntitySoundSlotPlayback((int)slotCursor2 + 0x22);
      ReleaseEntitySoundSlot(slotCursor2);
      slotCursor2 = slotCursor;
    }
    else {
      DetachEntitySoundHandle(*slotCursor2);
      slotCursor2 = slotCursor;
    }
  }
  StopAllSoundChannelsAndResetAudioLine();
  return;
}

