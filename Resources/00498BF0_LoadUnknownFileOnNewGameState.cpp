#include "tarzan_ghidra_types.hpp"

// Address: 0x00498BF0
// Label: LoadUnknownFileOnNewGameState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void LoadUnknownFileOnNewGameState(undefined4 arg1)

{
  ReadAudioEsfStreamBytes(arg1,g_AudioEsfStreamFlagsAndSize & 0xfffffff);
  return;
}

