#include "tarzan_ghidra_types.hpp"

// Address: 0x004B77A6
// Label: ReturnBasedOnArgSize
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 ReturnBasedOnArgSize(int arg1)

{
  if (arg1 == 0x3a4) {
    return 0x411;
  }
  if (arg1 == 0x3a8) {
    return 0x804;
  }
  if (arg1 == 0x3b5) {
    return 0x412;
  }
  if (arg1 != 0x3b6) {
    return 0;
  }
  return 0x404;
}

