#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF63A
// Label: ftell
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 ftell(undefined4 arg1)

{
  undefined4 value;
  
  _lock_file(arg1);
  value = _ftell_lk(arg1);
  _unlock_file(arg1);
  return value;
}

