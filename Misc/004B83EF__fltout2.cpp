#include "tarzan_ghidra_types.hpp"

// Address: 0x004B83EF
// Label: _fltout2
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 _fltout2(int arg1,uint arg2,uint arg3,int arg4,byte arg5,short *arg6)

{
  short *value3;
  short *value4;
  char resultFlag;
  uint value7;
  short *value5;
  short *value6;
  short shortValue;
  int value;
  int value2;
  char *stringCursor;
  undefined1 localState15;
  undefined1 localState14;
  undefined1 localState13;
  undefined1 localState12;
  undefined1 localState11;
  undefined1 localState10;
  undefined1 localState9;
  undefined1 localState8;
  undefined1 localState7;
  undefined1 localState6;
  undefined1 localState5;
  undefined1 localState4;
  undefined2 localState3;
  undefined2 localState2;
  undefined2 localState19;
  undefined2 localState18;
  undefined2 localState20;
  undefined1 localState17;
  char localState;
  undefined4 localState16;
  
  value4 = arg6;
  value7 = arg3 & 0x7fff;
  localState15 = 0xcc;
  localState14 = 0xcc;
  localState13 = 0xcc;
  localState12 = 0xcc;
  localState11 = 0xcc;
  localState10 = 0xcc;
  localState9 = 0xcc;
  localState8 = 0xcc;
  localState7 = 0xcc;
  localState6 = 0xcc;
  localState5 = 0xfb;
  localState4 = 0x3f;
  localState16 = 1;
  if ((arg3 & 0x8000) == 0) {
    *(undefined1 *)(arg6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(arg6 + 1) = 0x2d;
  }
  if ((((short)value7 != 0) || (arg2 != 0)) || (arg1 != 0)) {
    if ((short)value7 == 0x7fff) {
      *arg6 = 1;
      if (((arg2 == 0x80000000) && (arg1 == 0)) || ((arg2 & 0x40000000) != 0)) {
        if (((arg3 & 0x8000) == 0) || (arg2 != 0xc0000000)) {
          if ((arg2 != 0x80000000) || (arg1 != 0)) goto LAB_004b84e4;
          stringCursor = "1#INF";
        }
        else {
          if (arg1 != 0) {
LAB_004b84e4:
            stringCursor = "1#QNAN";
            goto LAB_004b84e9;
          }
          stringCursor = "1#IND";
        }
        strcpy(arg6 + 2,stringCursor);
        *(undefined1 *)((int)value4 + 3) = 5;
      }
      else {
        stringCursor = "1#SNAN";
LAB_004b84e9:
        strcpy(arg6 + 2,stringCursor);
        *(undefined1 *)((int)value4 + 3) = 6;
      }
      return 0;
    }
    localState3 = 0;
    localState17 = (undefined1)value7;
    localState = (char)(value7 >> 8);
    localState18 = (undefined2)arg2;
    localState20 = (undefined2)(arg2 >> 0x10);
    localState2 = (undefined2)arg1;
    localState19 = (undefined2)((uint)arg1 >> 0x10);
    shortValue = (short)(((value7 >> 8) + (arg2 >> 0x18) * 2) * 0x4d + -0x134312f4 + value7 * 0x4d10 >>
                   0x10);
    __multtenpow12(&localState3,-(int)shortValue,1);
    if (0x3ffe < CONCAT11(localState,localState17)) {
      shortValue = shortValue + 1;
      __ld12mul(&localState3,&localState15);
    }
    *value4 = shortValue;
    value2 = arg4;
    if (((arg5 & 1) == 0) || (value2 = arg4 + shortValue, 0 < arg4 + shortValue)) {
      if (0x15 < value2) {
        value2 = 0x15;
      }
      value = CONCAT11(localState,localState17) - 0x3ffe;
      localState17 = 0;
      localState = '\0';
      arg6 = (short *)0x8;
      do {
        ShiftUInt96LeftOne(&localState3);
        arg6 = (short *)((int)arg6 + -1);
      } while (arg6 != (short *)0x0);
      if (value < 0) {
        arg6 = (short *)0x0;
        for (value7 = -value & 0xff; value7 != 0; value7 = value7 - 1) {
          ShiftUInt96RightOne(&localState3);
        }
      }
      arg4 = value2 + 1;
      value5 = value4 + 2;
      arg6 = value5;
      if (0 < arg4) {
        do {
          arg1 = CONCAT22(localState2,localState3);
          arg2 = CONCAT22(localState18,localState19);
          arg3 = CONCAT13(localState,CONCAT12(localState17,localState20));
          ShiftUInt96LeftOne(&localState3);
          ShiftUInt96LeftOne(&localState3);
          ___add_12(&localState3,&arg1);
          ShiftUInt96LeftOne(&localState3);
          resultFlag = localState;
          localState = '\0';
          value5 = (short *)((int)arg6 + 1);
          arg4 = arg4 + -1;
          *(char *)arg6 = resultFlag + '0';
          arg6 = value5;
        } while (arg4 != 0);
      }
      value6 = value5 + -1;
      value3 = value4 + 2;
      if ('4' < *(char *)((int)value5 + -1)) {
        for (; value3 <= value6; value6 = (short *)((int)value6 + -1)) {
          if ((char)*value6 != '9') {
            if (value3 <= value6) goto LAB_004b8641;
            break;
          }
          *(char *)value6 = '0';
        }
        value6 = (short *)((int)value6 + 1);
        *value4 = *value4 + 1;
LAB_004b8641:
        *(char *)value6 = (char)*value6 + '\x01';
LAB_004b8643:
        resultFlag = ((char)value6 - (char)value4) + -3;
        *(char *)((int)value4 + 3) = resultFlag;
        *(undefined1 *)(resultFlag + 4 + (int)value4) = 0;
        return localState16;
      }
      for (; value3 <= value6; value6 = (short *)((int)value6 + -1)) {
        if ((char)*value6 != '0') {
          if (value3 <= value6) goto LAB_004b8643;
          break;
        }
      }
      *value4 = 0;
      *(undefined1 *)(value4 + 1) = 0x20;
      *(undefined1 *)((int)value4 + 3) = 1;
      *(char *)value3 = '0';
      goto LAB_004b8679;
    }
  }
  *value4 = 0;
  *(undefined1 *)(value4 + 1) = 0x20;
  *(undefined1 *)((int)value4 + 3) = 1;
  *(undefined1 *)(value4 + 2) = 0x30;
LAB_004b8679:
  *(undefined1 *)((int)value4 + 5) = 0;
  return 1;
}

