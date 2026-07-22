#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF8BC
// Label: _flush
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 _flush(int *arg1)

{
  int value;
  undefined4 value3;
  int value2;
  
  value3 = 0;
  if ((((byte)arg1[3] & 3) == 2) && ((arg1[3] & 0x108U) != 0)) {
    value2 = *arg1 - arg1[2];
    if (0 < value2) {
      value = _write(arg1[4],arg1[2],value2);
      if (value == value2) {
        if ((arg1[3] & 0x80U) != 0) {
          arg1[3] = arg1[3] & 0xfffffffd;
        }
      }
      else {
        arg1[3] = arg1[3] | 0x20;
        value3 = 0xffffffff;
      }
    }
  }
  arg1[1] = 0;
  *arg1 = arg1[2];
  return value3;
}

