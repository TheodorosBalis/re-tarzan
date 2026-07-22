#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF88E
// Label: _fflush_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _fflush_lk(int arg1)

{
  int value;
  
  value = _flush(arg1);
  if (value != 0) {
    return -1;
  }
  if ((*(byte *)(arg1 + 0xd) & 0x40) != 0) {
    value = _commit(*(undefined4 *)(arg1 + 0x10));
    return -(uint)(value != 0);
  }
  return 0;
}

