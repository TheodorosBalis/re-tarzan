#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF9D0
// Label: strstr
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint * strstr(uint *arg1,char *arg2)

{
  char *stringCursor;
  char *stringCursor2;
  char resultFlag;
  uint *dataCursor2;
  uint value;
  char resultFlag2;
  uint value2;
  char *stringCursor3;
  uint value3;
  uint *dataCursor;
  
  resultFlag = *arg2;
  if (resultFlag == '\0') {
    return arg1;
  }
  if (arg2[1] == '\0') {
    while (((uint)arg1 & 3) != 0) {
      value = *arg1;
      if ((char)value == resultFlag) {
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
        value3 = value ^ CONCAT22(CONCAT11(resultFlag,resultFlag),CONCAT11(resultFlag,resultFlag));
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
      if ((char)value == resultFlag) {
        return arg1;
      }
      if ((char)value == '\0') {
        return (uint *)0x0;
      }
      resultFlag2 = (char)(value >> 8);
      if (resultFlag2 == resultFlag) {
        return (uint *)((int)arg1 + 1);
      }
      if (resultFlag2 == '\0') {
        return (uint *)0x0;
      }
      resultFlag2 = (char)(value >> 0x10);
      if (resultFlag2 == resultFlag) {
        return (uint *)((int)arg1 + 2);
      }
      if (resultFlag2 == '\0') break;
      resultFlag2 = (char)(value >> 0x18);
      if (resultFlag2 == resultFlag) {
        return (uint *)((int)arg1 + 3);
      }
      arg1 = dataCursor;
      if (resultFlag2 == '\0') {
        return (uint *)0x0;
      }
    }
    return (uint *)0x0;
  }
  do {
    resultFlag2 = (char)*arg1;
    do {
      while (dataCursor = arg1, arg1 = (uint *)((int)dataCursor + 1), resultFlag2 != resultFlag) {
        if (resultFlag2 == '\0') {
          return (uint *)0x0;
        }
        resultFlag2 = *(char *)arg1;
      }
      resultFlag2 = *(char *)arg1;
      stringCursor3 = arg2;
      dataCursor2 = dataCursor;
    } while (resultFlag2 != arg2[1]);
    do {
      if (stringCursor3[2] == '\0') {
        return dataCursor;
      }
      if (*(char *)((int)dataCursor2 + 2) != stringCursor3[2]) break;
      stringCursor = stringCursor3 + 3;
      if (*stringCursor == '\0') {
        return dataCursor;
      }
      stringCursor2 = (char *)((int)dataCursor2 + 3);
      stringCursor3 = stringCursor3 + 2;
      dataCursor2 = (uint *)((int)dataCursor2 + 2);
    } while (*stringCursor == *stringCursor2);
  } while( true );
}

