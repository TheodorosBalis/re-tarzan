#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0264
// Label: _local_unwind2_exception_handler
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
_local_unwind2_exception_handler
          (int arg1,undefined4 arg2,undefined4 arg3,undefined4 *arg4)

{
  undefined4 value;
  
  value = 1;
  if ((*(uint *)(arg1 + 4) & 6) != 0) {
    *arg4 = arg2;
    value = 3;
  }
  return value;
}

