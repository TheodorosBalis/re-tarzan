#include "tarzan_ghidra_types.hpp"

// Address: 0x004B6430
// Label: strcat
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint * strcat(uint *arg1,uint *arg2)

{
  byte flagByte;
  uint value;
  uint *dataCursor;
  uint value2;
  uint *dataCursor2;
  
  dataCursor = arg1;
  do {
    if (((uint)dataCursor & 3) == 0) goto LAB_004b644c;
    value2 = *dataCursor;
    dataCursor = (uint *)((int)dataCursor + 1);
  } while ((byte)value2 != 0);
  goto LAB_004b647f;
  while( true ) {
    if ((value2 & 0xff0000) == 0) {
      dataCursor2 = (uint *)((int)dataCursor2 + 2);
      goto joined_r0x004b649b;
    }
    if ((value2 & 0xff000000) == 0) break;
LAB_004b644c:
    do {
      dataCursor2 = dataCursor;
      dataCursor = dataCursor2 + 1;
    } while (((*dataCursor2 ^ 0xffffffff ^ *dataCursor2 + 0x7efefeff) & 0x81010100) == 0);
    value2 = *dataCursor2;
    if ((char)value2 == '\0') goto joined_r0x004b649b;
    if ((char)(value2 >> 8) == '\0') {
      dataCursor2 = (uint *)((int)dataCursor2 + 1);
      goto joined_r0x004b649b;
    }
  }
LAB_004b647f:
  dataCursor2 = (uint *)((int)dataCursor + -1);
joined_r0x004b649b:
  do {
    if (((uint)arg2 & 3) == 0) {
      do {
        value = *arg2;
        value2 = *arg2;
        arg2 = arg2 + 1;
        if (((value ^ 0xffffffff ^ value + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)value2 == '\0') {
LAB_004b6508:
            *(byte *)dataCursor2 = (byte)value2;
            return arg1;
          }
          if ((char)(value2 >> 8) == '\0') {
            *(short *)dataCursor2 = (short)value2;
            return arg1;
          }
          if ((value2 & 0xff0000) == 0) {
            *(short *)dataCursor2 = (short)value2;
            *(byte *)((int)dataCursor2 + 2) = 0;
            return arg1;
          }
          if ((value2 & 0xff000000) == 0) {
            *dataCursor2 = value2;
            return arg1;
          }
        }
        *dataCursor2 = value2;
        dataCursor2 = dataCursor2 + 1;
      } while( true );
    }
    flagByte = (byte)*arg2;
    value2 = (uint)flagByte;
    arg2 = (uint *)((int)arg2 + 1);
    if (flagByte == 0) goto LAB_004b6508;
    *(byte *)dataCursor2 = flagByte;
    dataCursor2 = (uint *)((int)dataCursor2 + 1);
  } while( true );
}

