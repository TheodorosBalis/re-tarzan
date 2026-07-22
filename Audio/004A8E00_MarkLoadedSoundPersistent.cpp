#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8E00
// Label: MarkLoadedSoundPersistent
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void MarkLoadedSoundPersistent(ushort soundId)

{
  if (soundId < 2000) {
    (&g_LoadedSoundFlags)[(short)soundId * 0x2c] = (&g_LoadedSoundFlags)[(short)soundId * 0x2c] | 4;
  }
  return;
}

