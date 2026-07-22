#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8E60
// Label: HasAudioLineBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool HasAudioLineBuffer(void)

{
  return g_AudioLineSoundBuffer != 0;
}

