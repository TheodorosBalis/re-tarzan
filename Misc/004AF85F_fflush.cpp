#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF85F
// Label: fflush
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 fflush(int arg1)

{
  undefined4 value;
  
  if (arg1 == 0) {
    value = flsall(0);
    return value;
  }
  _lock_file(arg1);
  value = _fflush_lk(arg1);
  _unlock_file(arg1);
  return value;
}

