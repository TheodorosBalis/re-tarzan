#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC6C0
// Label: StopEntitySoundSlotPlayback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StopEntitySoundSlotPlayback(undefined4 *soundSlot)

{
  if (soundSlot != (undefined4 *)0x0) {
    StopSoundChannelByIndex(0xffffffff,*(undefined1 *)(soundSlot + 1));
    soundSlot[1] = 0xffffffff;
    *soundSlot = 0xffffffff;
    soundSlot[2] = 0;
  }
  return;
}

