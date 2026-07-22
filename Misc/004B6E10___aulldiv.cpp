#include "tarzan_ghidra_types.hpp"

// Address: 0x004B6E10
// Label: __aulldiv
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __aulldiv
   
   Library: Visual Studio */

undefined8 __aulldiv(uint arg1,uint arg2,uint arg3,uint arg4)

{
  ulonglong value3;
  longlong value2;
  uint value4;
  int value;
  uint value5;
  uint value6;
  uint value7;
  uint value8;
  uint value9;
  
  value4 = arg1;
  value8 = arg4;
  value6 = arg2;
  value9 = arg3;
  if (arg4 == 0) {
    value4 = arg2 / arg3;
    value = (int)(((ulonglong)arg2 % (ulonglong)arg3 << 0x20 | (ulonglong)arg1) /
                 (ulonglong)arg3);
  }
  else {
    do {
      value5 = value8 >> 1;
      value9 = value9 >> 1 | (uint)((value8 & 1) != 0) << 0x1f;
      value7 = value6 >> 1;
      value4 = value4 >> 1 | (uint)((value6 & 1) != 0) << 0x1f;
      value8 = value5;
      value6 = value7;
    } while (value5 != 0);
    value3 = CONCAT44(value7,value4) / (ulonglong)value9;
    value = (int)value3;
    value2 = (ulonglong)arg3 * (value3 & 0xffffffff);
    value4 = (uint)((ulonglong)value2 >> 0x20);
    value8 = value4 + value * arg4;
    if (((CARRY4(value4,value * arg4)) || (arg2 < value8)) ||
       ((arg2 <= value8 && (arg1 < (uint)value2)))) {
      value = value + -1;
    }
    value4 = 0;
  }
  return CONCAT44(value4,value);
}

