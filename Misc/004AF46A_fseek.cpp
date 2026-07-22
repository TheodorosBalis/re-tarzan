#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF46A
// Label: fseek
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 fseek(undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined4 value;
  
  _lock_file(arg1);
  value = _fseek_lk(arg1,arg2,arg3);
  _unlock_file(arg1);
  return value;
}

