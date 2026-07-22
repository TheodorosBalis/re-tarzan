#include "tarzan_ghidra_types.hpp"

// Address: 0x0048A190
// Label: CountBitsNeededForValue
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CountBitsNeededForValue(uint arg1)

{
  int count;
  
  count = 0;
  for (; arg1 != 0; arg1 = arg1 >> 1) {
    count = count + 1;
  }
  return count;
}

