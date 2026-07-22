#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF426
// Label: _fsopen
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 _fsopen(undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  int value;
  undefined4 value2;
  
  value = _getstream();
  if (value == 0) {
    return 0;
  }
  value2 = _openfile(arg1,arg2,arg3,value);
  _unlock_file(value);
  return value2;
}

