#include "tarzan_ghidra_types.hpp"

// Address: 0x00453C00
// Label: UpdateEntity3DSounds
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateEntity3DSounds(void)

{
  int *intCursor;
  int *intCursor2;
  int entry;
  
  RefreshAudioListenerAndChannelMask();
  intCursor = g_ActiveEntitySoundSlotList;
  while (intCursor2 = intCursor, intCursor2 != (int *)0x0) {
    intCursor = (int *)intCursor2[6];
    entry = UpdateEntitySoundSlotPlayback((int)intCursor2 + 0x22,intCursor2[4]);
    if (entry != 1) {
      if (*intCursor2 == 0) {
        StopEntitySoundSlotPlayback((int)intCursor2 + 0x22);
        ReleaseEntitySoundSlot(intCursor2);
      }
      else {
        DetachEntitySoundHandle(*intCursor2);
      }
    }
  }
  return;
}

