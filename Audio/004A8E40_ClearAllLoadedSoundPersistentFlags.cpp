#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8E40
// Label: ClearAllLoadedSoundPersistentFlags
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ClearAllLoadedSoundPersistentFlags(void)

{
  byte *value;
  byte *value2;
  
  value = &g_LoadedSoundFlags;
  do {
    value2 = value + 0x2c;
    *value = *value & 0xfb;
    value = value2;
  } while ((int)value2 < 0x9e4a06);
  return;
}

