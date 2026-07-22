#include "tarzan_ghidra_types.hpp"

// Address: 0x004B6E80
// Label: __aullrem
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __aullrem
   
   Library: Visual Studio */

undefined8 __aullrem(uint arg1,uint arg2,uint arg3,uint arg4)

{
  ulonglong value4;
  longlong value3;
  uint value6;
  uint value7;
  uint value8;
  int value;
  int value2;
  uint value9;
  uint value10;
  uint value5;
  bool flagByte;
  
  value6 = arg1;
  value7 = arg4;
  value10 = arg2;
  value5 = arg3;
  if (arg4 == 0) {
    value = (int)(((ulonglong)arg2 % (ulonglong)arg3 << 0x20 | (ulonglong)arg1) %
                 (ulonglong)arg3);
    value2 = 0;
  }
  else {
    do {
      value8 = value7 >> 1;
      value5 = value5 >> 1 | (uint)((value7 & 1) != 0) << 0x1f;
      value9 = value10 >> 1;
      value6 = value6 >> 1 | (uint)((value10 & 1) != 0) << 0x1f;
      value7 = value8;
      value10 = value9;
    } while (value8 != 0);
    value4 = CONCAT44(value9,value6) / (ulonglong)value5;
    value6 = (int)value4 * arg4;
    value3 = (value4 & 0xffffffff) * (ulonglong)arg3;
    value10 = (uint)((ulonglong)value3 >> 0x20);
    value7 = (uint)value3;
    value5 = value10 + value6;
    if (((CARRY4(value10,value6)) || (arg2 < value5)) || ((arg2 <= value5 && (arg1 < value7))))
    {
      flagByte = value7 < arg3;
      value7 = value7 - arg3;
      value5 = (value5 - arg4) - (uint)flagByte;
    }
    value = -(value7 - arg1);
    value2 = -(uint)(value7 - arg1 != 0) - ((value5 - arg2) - (uint)(value7 < arg1));
  }
  return CONCAT44(value2,value);
}

