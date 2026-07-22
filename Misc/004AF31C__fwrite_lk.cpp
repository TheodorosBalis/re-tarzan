#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF31C
// Label: _fwrite_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint _fwrite_lk(char *arg1,uint arg2,uint arg3,int *arg4)

{
  int *intCursor;
  int value;
  uint value2;
  uint value3;
  uint value4;
  uint value5;
  
  intCursor = arg4;
  value4 = arg2 * arg3;
  if (value4 == 0) {
    arg3 = 0;
  }
  else {
    value3 = value4;
    if ((*(ushort *)(arg4 + 3) & 0x10c) == 0) {
      arg4 = (int *)0x1000;
    }
    else {
      arg4 = (int *)arg4[6];
    }
    do {
      if (((intCursor[3] & 0x108U) == 0) || (value5 = intCursor[1], value5 == 0)) {
        if (arg4 <= value3) {
          if (((intCursor[3] & 0x108U) != 0) && (value = _flush(intCursor), value != 0)) {
LAB_004af41d:
            return (value4 - value3) / arg2;
          }
          value5 = value3;
          if (arg4 != (int *)0x0) {
            value5 = value3 - value3 % (uint)arg4;
          }
          value2 = _write(intCursor[4],arg1,value5);
          if ((value2 == 0xffffffff) || (value3 = value3 - value2, value2 < value5)) {
            intCursor[3] = intCursor[3] | 0x20;
            goto LAB_004af41d;
          }
          goto LAB_004af3d4;
        }
        value = _flsbuf((int)*arg1,intCursor);
        if (value == -1) goto LAB_004af41d;
        arg1 = arg1 + 1;
        arg4 = (int *)intCursor[6];
        value3 = value3 - 1;
        if ((int)arg4 < 1) {
          arg4 = (int *)0x1;
        }
      }
      else {
        value2 = value3;
        if (value5 <= value3) {
          value2 = value5;
        }
        memmove(*intCursor,arg1,value2);
        intCursor[1] = intCursor[1] - value2;
        *intCursor = *intCursor + value2;
        value3 = value3 - value2;
LAB_004af3d4:
        arg1 = arg1 + value2;
      }
    } while (value3 != 0);
  }
  return arg3;
}

