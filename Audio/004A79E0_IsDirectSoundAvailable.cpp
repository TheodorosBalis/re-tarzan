#include "tarzan_ghidra_types.hpp"

// Address: 0x004A79E0
// Label: IsDirectSoundAvailable
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 IsDirectSoundAvailable(void)

{
  if (((g_IsDSoundInitialized != 0) && (g_DirectSound != 0)) && (g_PrimarySoundBuffer != 0)) {
    return 1;
  }
  return 0;
}

