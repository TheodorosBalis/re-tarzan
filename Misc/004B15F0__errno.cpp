#include "tarzan_ghidra_types.hpp"

// Address: 0x004B15F0
// Label: _errno
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _errno(void)

{
  int value;
  
  value = _getptd();
  return value + 8;
}

