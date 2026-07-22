#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF918
// Label: _flushall
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _flushall(void)

{
  flsall(1);
  return 0;
}

