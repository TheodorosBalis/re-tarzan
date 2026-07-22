#include "tarzan_ghidra_types.hpp"

// Address: 0x00498C10
// Label: CloseAudioEsfStream
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CloseAudioEsfStream(void)

{
  if (g_AudioEsfStreamHandle != 0) {
    CloseVirtualGameFileHandle(g_AudioEsfStreamHandle);
  }
  g_AudioEsfStreamHandle = 0;
  return;
}

