#include "tarzan_ghidra_types.hpp"

// Address: 0x00453D30
// Label: DetachEntitySoundHandle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void DetachEntitySoundHandle(int *soundSlot)

{
  int entry;
  
  entry = *soundSlot;
  if (entry != 0) {
    StopEntitySoundSlotPlayback(entry + 0x22);
    ReleaseEntitySoundSlot(entry);
    *soundSlot = 0;
  }
  return;
}

