#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF552
// Label: _fread_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint _fread_lk(undefined1 *arg1,uint arg2,uint arg3,int *arg4)

{
  int *intCursor;
  uint value2;
  int value;
  undefined1 *dataCursor;
  uint value3;
  uint value4;
  
  intCursor = arg4;
  value3 = arg2 * arg3;
  if (value3 == 0) {
    arg3 = 0;
  }
  else {
    dataCursor = arg1;
    arg1 = (undefined1 *)value3;
    if ((*(ushort *)(arg4 + 3) & 0x10c) == 0) {
      arg4 = (int *)0x1000;
    }
    else {
      arg4 = (int *)arg4[6];
    }
    do {
      if (((*(ushort *)(intCursor + 3) & 0x10c) == 0) || (value2 = intCursor[1], value2 == 0)) {
        if (arg1 < arg4) {
          value = _filbuf(intCursor);
          if (value == -1) goto LAB_004af62e;
          *dataCursor = (char)value;
          arg4 = (int *)intCursor[6];
          dataCursor = dataCursor + 1;
          arg1 = (undefined1 *)((int)arg1 - 1);
        }
        else {
          value2 = (uint)arg1;
          if (arg4 != (int *)0x0) {
            value2 = (int)arg1 - (uint)arg1 % (uint)arg4;
          }
          value = _read(intCursor[4],dataCursor,value2);
          if (value == 0) {
            intCursor[3] = intCursor[3] | 0x10;
LAB_004af62e:
            return (value3 - (int)arg1) / arg2;
          }
          if (value == -1) {
            intCursor[3] = intCursor[3] | 0x20;
            goto LAB_004af62e;
          }
          arg1 = (undefined1 *)((int)arg1 - value);
          dataCursor = dataCursor + value;
        }
      }
      else {
        value4 = (uint)arg1;
        if (value2 <= arg1) {
          value4 = value2;
        }
        memmove(dataCursor,*intCursor,value4);
        arg1 = (undefined1 *)((int)arg1 - value4);
        intCursor[1] = intCursor[1] - value4;
        *intCursor = *intCursor + value4;
        dataCursor = dataCursor + value4;
      }
    } while (arg1 != (undefined1 *)0x0);
  }
  return arg3;
}

