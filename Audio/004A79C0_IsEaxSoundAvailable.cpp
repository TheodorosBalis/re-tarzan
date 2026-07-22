#include "tarzan_ghidra_types.hpp"

// Address: 0x004A79C0
// Label: IsEaxSoundAvailable
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 IsEaxSoundAvailable(void)

{
  if ((g_IsDSoundInitialized != 0) && (g_DSound3DListener != 0)) {
    return 1;
  }
  return 0;
}

