#include "tarzan_ghidra_types.hpp"

// Address: 0x004B1D00
// Label: strchr
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint * strchr(uint *arg1,char arg2)

{
  uint value;
  char resultFlag;
  uint value2;
  uint value3;
  uint *dataCursor;
  
  while (((uint)arg1 & 3) != 0) {
    value = *arg1;
    if ((char)value == arg2) {
      return arg1;
    }
    arg1 = (uint *)((int)arg1 + 1);
    if ((char)value == '\0') {
      return (uint *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      value = *arg1;
      value3 = value ^ CONCAT22(CONCAT11(arg2,arg2),CONCAT11(arg2,arg2));
      value2 = value ^ 0xffffffff ^ value + 0x7efefeff;
      dataCursor = arg1 + 1;
      if (((value3 ^ 0xffffffff ^ value3 + 0x7efefeff) & 0x81010100) != 0) break;
      arg1 = dataCursor;
      if ((value2 & 0x81010100) != 0) {
        if ((value2 & 0x1010100) != 0) {
          return (uint *)0x0;
        }
        if ((value + 0x7efefeff & 0x80000000) == 0) {
          return (uint *)0x0;
        }
      }
    }
    value = *arg1;
    if ((char)value == arg2) {
      return arg1;
    }
    if ((char)value == '\0') {
      return (uint *)0x0;
    }
    resultFlag = (char)(value >> 8);
    if (resultFlag == arg2) {
      return (uint *)((int)arg1 + 1);
    }
    if (resultFlag == '\0') {
      return (uint *)0x0;
    }
    resultFlag = (char)(value >> 0x10);
    if (resultFlag == arg2) {
      return (uint *)((int)arg1 + 2);
    }
    if (resultFlag == '\0') break;
    resultFlag = (char)(value >> 0x18);
    if (resultFlag == arg2) {
      return (uint *)((int)arg1 + 3);
    }
    arg1 = dataCursor;
    if (resultFlag == '\0') {
      return (uint *)0x0;
    }
  }
  return (uint *)0x0;
}

