#include "tarzan_ghidra_types.hpp"

// Address: 0x004B5FF1
// Label: IsUInt96Zero
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 IsUInt96Zero(int *arg1)

{
  int result;
  
  result = 0;
  do {
    if (*arg1 != 0) {
      return 0;
    }
    result = result + 1;
    arg1 = arg1 + 1;
  } while (result < 3);
  return 1;
}

