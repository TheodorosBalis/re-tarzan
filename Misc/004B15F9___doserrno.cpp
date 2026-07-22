#include "tarzan_ghidra_types.hpp"

// Address: 0x004B15F9
// Label: __doserrno
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int __doserrno(void)

{
  int value;
  
  value = _getptd();
  return value + 0xc;
}

