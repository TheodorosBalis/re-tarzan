#include "tarzan_ghidra_types.hpp"

// Address: 0x004B6420
// Label: strcpy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint * strcpy(uint *arg1,uint *arg2)

{
  byte flagByte;
  uint value;
  uint value2;
  uint *dataCursor;
  
  dataCursor = arg1;
  while (((uint)arg2 & 3) != 0) {
    flagByte = (byte)*arg2;
    value2 = (uint)flagByte;
    arg2 = (uint *)((int)arg2 + 1);
    if (flagByte == 0) goto LAB_004b6508;
    *(byte *)dataCursor = flagByte;
    dataCursor = (uint *)((int)dataCursor + 1);
  }
  do {
    value = *arg2;
    value2 = *arg2;
    arg2 = arg2 + 1;
    if (((value ^ 0xffffffff ^ value + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)value2 == '\0') {
LAB_004b6508:
        *(byte *)dataCursor = (byte)value2;
        return arg1;
      }
      if ((char)(value2 >> 8) == '\0') {
        *(short *)dataCursor = (short)value2;
        return arg1;
      }
      if ((value2 & 0xff0000) == 0) {
        *(short *)dataCursor = (short)value2;
        *(byte *)((int)dataCursor + 2) = 0;
        return arg1;
      }
      if ((value2 & 0xff000000) == 0) {
        *dataCursor = value2;
        return arg1;
      }
    }
    *dataCursor = value2;
    dataCursor = dataCursor + 1;
  } while( true );
}

