#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABD40
// Label: IsMenuModeActive
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool IsMenuModeActive(void)

{
  return g_IsWorldModeActive == 0;
}

