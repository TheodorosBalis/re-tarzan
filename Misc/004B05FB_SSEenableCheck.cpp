#include "tarzan_ghidra_types.hpp"

// Address: 0x004B05FB
// Label: SSEenableCheck
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SSEenableCheck(void)

{
  _control87(0x10000,0x30000);
  return;
}

