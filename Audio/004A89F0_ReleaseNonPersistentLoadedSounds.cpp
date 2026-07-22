#include "tarzan_ghidra_types.hpp"

// Address: 0x004A89F0
// Label: ReleaseNonPersistentLoadedSounds
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseNonPersistentLoadedSounds(void)

{
  int value;
  byte *value2;
  
  value = 0;
  value2 = &g_LoadedSoundFlags;
  do {
    if ((*value2 & 4) == 0) {
      ReleaseLoadedSoundById(value);
    }
    value = value + 1;
    value2 = value2 + 0x2c;
  } while ((short)value < 2000);
  return;
}

