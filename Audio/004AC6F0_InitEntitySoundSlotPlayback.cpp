#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC6F0
// Label: InitEntitySoundSlotPlayback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 InitEntitySoundSlotPlayback(undefined4 soundId,undefined4 *position)

{
  if (position != (undefined4 *)0x0) {
    position[1] = 0xffffffff;
    *position = soundId;
    position[2] = 0xf;
    return 1;
  }
  PlaySoundID(soundId,100,0,0,0x3fb33333);
  return 1;
}

