#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0228
// Label: _initterm
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _initterm(undefined4 *arg1,undefined4 *arg2)

{
  for (; arg1 < arg2; arg1 = arg1 + 1) {
    if ((code *)*arg1 != (code *)0x0) {
      (*(code *)*arg1)();
    }
  }
  return;
}

