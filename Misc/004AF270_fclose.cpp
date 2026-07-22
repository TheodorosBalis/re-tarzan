#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF270
// Label: fclose
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 fclose(int arg1)

{
  undefined4 value;
  
  value = 0xffffffff;
  if ((*(byte *)(arg1 + 0xc) & 0x40) == 0) {
    _lock_file(arg1);
    value = _fclose_lk(arg1);
    _unlock_file(arg1);
  }
  else {
    *(undefined4 *)(arg1 + 0xc) = 0;
  }
  return value;
}

