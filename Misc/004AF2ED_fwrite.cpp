#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF2ED
// Label: fwrite
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 fwrite(undefined4 arg1,undefined4 arg2,undefined4 arg3,undefined4 arg4)

{
  undefined4 value;
  
  _lock_file(arg4);
  value = _fwrite_lk(arg1,arg2,arg3,arg4);
  _unlock_file(arg4);
  return value;
}

