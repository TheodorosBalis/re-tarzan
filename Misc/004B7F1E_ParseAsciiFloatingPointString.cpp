#include "tarzan_ghidra_types.hpp"

// Address: 0x004B7F1E
// Label: ParseAsciiFloatingPointString
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
ParseAsciiFloatingPointString
          (ushort *arg1,int *arg2,byte *arg3,undefined4 arg4,int arg5,int arg6,
          int arg7)

{
  int value;
  uint value8;
  char *stringCursor;
  int value3;
  int value4;
  byte flagByte;
  byte *value5;
  byte *value6;
  byte *value7;
  int value2;
  char localState15 [23];
  char localState14;
  ushort localState13;
  undefined2 localState19;
  undefined2 localState18;
  byte *localState12;
  ushort localState11;
  int localState10;
  int localState9;
  undefined4 localState8;
  int localState7;
  int localState6;
  int localState5;
  int localState4;
  undefined4 localState3;
  int localState2;
  char *localState;
  int localState17;
  uint localState16;
  
  localState = localState15;
  localState8 = 0;
  localState4 = 1;
  localState16 = 0;
  localState2 = 0;
  localState7 = 0;
  localState6 = 0;
  localState9 = 0;
  localState10 = 0;
  localState5 = 0;
  localState17 = 0;
  localState3 = 0;
  for (value5 = arg3;
      (((flagByte = *value5, flagByte == 0x20 || (flagByte == 9)) || (flagByte == 10)) || (flagByte == 0xd));
      value5 = value5 + 1) {
  }
  value3 = 4;
  value2 = 0;
  value4 = localState2;
LAB_004b7f75:
  localState2 = value4;
  value4 = 1;
  flagByte = *value5;
  value6 = value5 + 1;
  value7 = arg3;
  value = localState2;
  switch(value2) {
  case 0:
    if (('0' < (char)flagByte) && ((char)flagByte < ':')) {
LAB_004b7f92:
      localState2 = value;
      value2 = 3;
      goto LAB_004b81b7;
    }
    if (flagByte == g_CrtDecimalPointString) goto LAB_004b7fa1;
    if (flagByte == 0x2b) {
      localState8 = 0;
      value2 = 2;
      value5 = value6;
      value4 = localState2;
    }
    else if (flagByte == 0x2d) {
      localState8 = 0x8000;
      value2 = 2;
      value5 = value6;
      value4 = localState2;
    }
    else {
      value2 = value4;
      value5 = value6;
      value4 = localState2;
      if (flagByte != 0x30) goto LAB_004b8291;
    }
    goto LAB_004b7f75;
  case 1:
    localState2 = 1;
    if (('0' < (char)flagByte) && (value = value4, (char)flagByte < ':')) goto LAB_004b7f92;
    value2 = value3;
    value5 = value6;
    if (flagByte != g_CrtDecimalPointString) {
      value2 = value4;
      if ((flagByte == 0x2b) || (value2 = localState2, flagByte == 0x2d)) goto LAB_004b8026;
      value2 = value4;
      localState2 = value4;
      if (flagByte != 0x30) goto LAB_004b7fff;
    }
    goto LAB_004b7f75;
  case 2:
    if (('0' < (char)flagByte) && ((char)flagByte < ':')) goto LAB_004b7f92;
    if (flagByte == g_CrtDecimalPointString) {
LAB_004b7fa1:
      value2 = 5;
      value5 = value6;
      value4 = localState2;
    }
    else {
      value2 = value4;
      value5 = value6;
      value4 = localState2;
      if (flagByte != 0x30) goto LAB_004b8296;
    }
    goto LAB_004b7f75;
  case 3:
    localState2 = value4;
    while( true ) {
      if (g_CrtLocaleEnabled < 2) {
        value8 = (byte)g_CrtCtypeTable[(uint)flagByte * 2] & 4;
      }
      else {
        value8 = _isctype(flagByte,4);
      }
      if (value8 == 0) break;
      if (localState16 < 0x19) {
        localState16 = localState16 + 1;
        stringCursor = localState + 1;
        *localState = flagByte - 0x30;
        localState = stringCursor;
      }
      else {
        localState17 = localState17 + 1;
      }
      flagByte = *value6;
      value6 = value6 + 1;
    }
    value2 = value3;
    value5 = value6;
    value4 = localState2;
    if (flagByte != g_CrtDecimalPointString) goto LAB_004b8113;
    goto LAB_004b7f75;
  case 4:
    localState2 = 1;
    localState7 = 1;
    value2 = value4;
    if (localState16 == 0) {
      while (value4 = localState7, value2 = localState2, flagByte == 0x30) {
        localState17 = localState17 + -1;
        flagByte = *value6;
        value6 = value6 + 1;
      }
    }
    while( true ) {
      localState2 = value2;
      localState7 = value4;
      if (g_CrtLocaleEnabled < 2) {
        value8 = (byte)g_CrtCtypeTable[(uint)flagByte * 2] & 4;
      }
      else {
        value8 = _isctype(flagByte,4);
      }
      if (value8 == 0) break;
      if (localState16 < 0x19) {
        localState16 = localState16 + 1;
        localState17 = localState17 + -1;
        stringCursor = localState + 1;
        *localState = flagByte - 0x30;
        localState = stringCursor;
      }
      flagByte = *value6;
      value6 = value6 + 1;
      value4 = localState7;
      value2 = localState2;
    }
LAB_004b8113:
    value2 = localState2;
    if ((flagByte == 0x2b) || (flagByte == 0x2d)) {
LAB_004b8026:
      localState2 = value2;
      value2 = 0xb;
      value5 = value6 + -1;
      value4 = localState2;
    }
    else {
LAB_004b7fff:
      if (((char)flagByte < 'D') ||
         (('E' < (char)flagByte && (((char)flagByte < 'd' || ('e' < (char)flagByte)))))) goto LAB_004b8291;
      value2 = 6;
      value5 = value6;
      value4 = localState2;
    }
    goto LAB_004b7f75;
  case 5:
    localState7 = value4;
    if (g_CrtLocaleEnabled < 2) {
      value8 = (byte)g_CrtCtypeTable[(uint)flagByte * 2] & 4;
    }
    else {
      value8 = _isctype(flagByte,4);
    }
    value2 = value3;
    if (value8 != 0) goto LAB_004b81b7;
    goto LAB_004b8296;
  case 6:
    arg3 = value5 + -1;
    if (((char)flagByte < '1') || ('9' < (char)flagByte)) {
      if (flagByte == 0x2b) goto LAB_004b81ec;
      if (flagByte == 0x2d) goto LAB_004b81e0;
      value7 = arg3;
      if (flagByte != 0x30) goto LAB_004b8296;
LAB_004b8185:
      value2 = 8;
      value5 = value6;
      value4 = localState2;
      goto LAB_004b7f75;
    }
    break;
  case 7:
    if (((char)flagByte < '1') || ('9' < (char)flagByte)) {
      if (flagByte == 0x30) goto LAB_004b8185;
      goto LAB_004b8296;
    }
    break;
  case 8:
    localState6 = 1;
    while (flagByte == 0x30) {
      flagByte = *value6;
      value6 = value6 + 1;
    }
    if (((char)flagByte < '1') || ('9' < (char)flagByte)) goto LAB_004b8291;
    break;
  case 9:
    localState6 = 1;
    value3 = 0;
    goto LAB_004b8217;
  default:
    goto switchD_004b7f81_caseD_a;
  case 0xb:
    if (arg7 != 0) {
      arg3 = value5;
      if (flagByte == 0x2b) {
LAB_004b81ec:
        value2 = 7;
        value5 = value6;
        value4 = localState2;
      }
      else {
        value7 = value5;
        if (flagByte != 0x2d) goto LAB_004b8296;
LAB_004b81e0:
        localState4 = -1;
        value2 = 7;
        value5 = value6;
        value4 = localState2;
      }
      goto LAB_004b7f75;
    }
    value2 = 10;
    value6 = value5;
switchD_004b7f81_caseD_a:
    value5 = value6;
    value7 = value6;
    value4 = localState2;
    if (value2 != 10) goto LAB_004b7f75;
    goto LAB_004b8296;
  }
  value2 = 9;
LAB_004b81b7:
  value5 = value6 + -1;
  value4 = localState2;
  goto LAB_004b7f75;
LAB_004b8217:
  if (g_CrtLocaleEnabled < 2) {
    value8 = (byte)g_CrtCtypeTable[(uint)flagByte * 2] & 4;
  }
  else {
    value8 = _isctype(flagByte,4);
  }
  if (value8 == 0) goto LAB_004b8261;
  value3 = (char)flagByte + -0x30 + value3 * 10;
  if (0x1450 < value3) goto LAB_004b8259;
  flagByte = *value6;
  value6 = value6 + 1;
  goto LAB_004b8217;
LAB_004b8259:
  value3 = 0x1451;
LAB_004b8261:
  while( true ) {
    localState5 = value3;
    if (g_CrtLocaleEnabled < 2) {
      value8 = (byte)g_CrtCtypeTable[(uint)flagByte * 2] & 4;
    }
    else {
      value8 = _isctype(flagByte,4);
    }
    if (value8 == 0) break;
    flagByte = *value6;
    value6 = value6 + 1;
    value3 = localState5;
  }
LAB_004b8291:
  value7 = value6 + -1;
LAB_004b8296:
  *arg2 = (int)value7;
  if (localState2 == 0) {
    localState13 = 0;
    localState11 = 0;
    localState12 = (byte *)0x0;
    arg3 = (byte *)0x0;
    localState3 = 4;
    goto LAB_004b83a4;
  }
  stringCursor = localState;
  if (0x18 < localState16) {
    if ('\x04' < localState14) {
      localState14 = localState14 + '\x01';
    }
    localState16 = 0x18;
    localState17 = localState17 + 1;
    stringCursor = localState + -1;
  }
  if (localState16 == 0) {
    localState13 = 0;
    localState11 = 0;
    localState12 = (byte *)0x0;
    arg3 = (byte *)0x0;
  }
  else {
    while (stringCursor = stringCursor + -1, *stringCursor == '\0') {
      localState16 = localState16 - 1;
      localState17 = localState17 + 1;
    }
    __mtold12(localState15,localState16,&localState13);
    value3 = localState5;
    if (localState4 < 0) {
      value3 = -localState5;
    }
    value3 = value3 + localState17;
    if (localState6 == 0) {
      value3 = value3 + arg5;
    }
    if (localState7 == 0) {
      value3 = value3 - arg6;
    }
    if (value3 < 0x1451) {
      if (-0x1451 < value3) {
        __multtenpow12(&localState13,value3,arg4);
        arg3 = (byte *)CONCAT22(localState18,localState19);
        goto LAB_004b8329;
      }
      localState10 = 1;
    }
    else {
      localState9 = 1;
    }
    localState11 = (ushort)arg3;
    localState12 = arg3;
    localState13 = localState11;
  }
LAB_004b8329:
  if (localState9 == 0) {
    if (localState10 != 0) {
      localState13 = 0;
      localState11 = 0;
      localState12 = (byte *)0x0;
      arg3 = (byte *)0x0;
      localState3 = 1;
    }
  }
  else {
    arg3 = (byte *)0x0;
    localState11 = 0x7fff;
    localState12 = (byte *)0x80000000;
    localState13 = 0;
    localState3 = 2;
  }
LAB_004b83a4:
  *(byte **)(arg1 + 3) = localState12;
  *(byte **)(arg1 + 1) = arg3;
  arg1[5] = localState11 | (ushort)localState8;
  *arg1 = localState13;
  return localState3;
}

