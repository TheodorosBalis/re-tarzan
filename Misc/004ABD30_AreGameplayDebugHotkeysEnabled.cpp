#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABD30
// Label: AreGameplayDebugHotkeysEnabled
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint AreGameplayDebugHotkeysEnabled(void)

{
  return g_GameplayRuntimeFlags & 0x80000000;
}

