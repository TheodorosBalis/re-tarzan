#include "tarzan_ghidra_types.hpp"

// Address: 0x004B74FF
// Label: _ungetc_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint _ungetc_lk(uint arg1,int *arg2)

{
  uint value;
  
  if ((arg1 != 0xffffffff) &&
     ((value = arg2[3], (value & 1) != 0 || (((value & 0x80) != 0 && ((value & 2) == 0)))))) {
    if (arg2[2] == 0) {
      _getbuf(arg2);
    }
    if (*arg2 == arg2[2]) {
      if (arg2[1] != 0) {
        return 0xffffffff;
      }
      *arg2 = *arg2 + 1;
    }
    if ((*(byte *)(arg2 + 3) & 0x40) == 0) {
      *arg2 = *arg2 + -1;
      *(char *)*arg2 = (char)arg1;
    }
    else {
      *arg2 = *arg2 + -1;
      if (*(char *)*arg2 != (char)arg1) {
        *arg2 = (int)((char *)*arg2 + 1);
        return 0xffffffff;
      }
    }
    arg2[1] = arg2[1] + 1;
    arg2[3] = arg2[3] & 0xffffffefU | 1;
    return arg1 & 0xff;
  }
  return 0xffffffff;
}

