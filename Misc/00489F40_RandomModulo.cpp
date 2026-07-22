#include "tarzan_ghidra_types.hpp"

// Address: 0x00489F40
// Label: RandomModulo
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint RandomModulo(uint arg1)

{
  uint value;
  
  value = NextRandomValue();
  return value % arg1;
}

