#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8D60
// Label: IsSoundAllowedWhenSoundEffectsMuted
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 IsSoundAllowedWhenSoundEffectsMuted(ushort soundId,byte position)

{
  if (soundId < 2000) {
    if (((&g_LoadedSoundFlags)[(short)soundId * 0x2c] & 1) != 0) {
      return 1;
    }
  }
  else if ((position < 0x10) && ((&g_ActiveSoundChannelMap)[(char)position * 2] != -1)) {
    if (((&g_LoadedSoundFlags)[(short)(&g_ActiveSoundChannelMap)[(char)position * 2] * 0x2c] & 1) !=
        0) {
      return 1;
    }
    return 0;
  }
  return 0;
}

