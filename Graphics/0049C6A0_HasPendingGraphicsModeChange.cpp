#include "tarzan_ghidra_types.hpp"

// Address: 0x0049C6A0
// Label: HasPendingGraphicsModeChange
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool HasPendingGraphicsModeChange(void)

{
  return g_RequestedGraphicsMode != g_CurrentGraphicsMode;
}

