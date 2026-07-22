#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF496
// Label: _fseek_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _fseek_lk(int arg1,int arg2,int arg3)

{
  uint value2;
  int value;
  undefined4 *dataCursor;
  
  if (((*(uint *)(arg1 + 0xc) & 0x83) == 0) ||
     (((arg3 != 0 && (arg3 != 1)) && (arg3 != 2)))) {
    dataCursor = (undefined4 *)_errno();
    *dataCursor = 0x16;
    value = -1;
  }
  else {
    *(uint *)(arg1 + 0xc) = *(uint *)(arg1 + 0xc) & 0xffffffef;
    if (arg3 == 1) {
      value = _ftell_lk(arg1);
      arg2 = arg2 + value;
      arg3 = 0;
    }
    _flush(arg1);
    value2 = *(uint *)(arg1 + 0xc);
    if ((value2 & 0x80) == 0) {
      if ((((value2 & 1) != 0) && ((value2 & 8) != 0)) && ((value2 & 0x400) == 0)) {
        *(undefined4 *)(arg1 + 0x18) = 0x200;
      }
    }
    else {
      *(uint *)(arg1 + 0xc) = value2 & 0xfffffffc;
    }
    value = _lseek(*(undefined4 *)(arg1 + 0x10),arg2,arg3);
    value = (value != -1) - 1;
  }
  return value;
}

