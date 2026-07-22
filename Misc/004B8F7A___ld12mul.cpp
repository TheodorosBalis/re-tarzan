#include "tarzan_ghidra_types.hpp"

// Address: 0x004B8F7A
// Label: __ld12mul
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void __ld12mul(int *arg1,int *arg2)

{
  short shortValue;
  int value;
  ushort value3;
  int *intCursor;
  int *intCursor2;
  ushort value4;
  int value2;
  ushort value5;
  ushort value6;
  byte localState8;
  undefined1 localState14;
  undefined2 localState13;
  short localState7;
  undefined2 localState12;
  undefined2 localState6;
  undefined1 localState11;
  byte localState;
  int localState5;
  int localState4;
  int localState3;
  ushort *localState2;
  ushort *localState10;
  short *localState9;
  
  intCursor2 = arg2;
  intCursor = arg1;
  localState4 = 0;
  localState8 = 0;
  localState14 = 0;
  localState13 = 0;
  localState7 = 0;
  localState12 = 0;
  localState6 = 0;
  localState11 = 0;
  localState = 0;
  value4 = *(ushort *)((int)arg1 + 10) & 0x7fff;
  value5 = *(ushort *)((int)arg2 + 10) & 0x7fff;
  value6 = (*(ushort *)((int)arg2 + 10) ^ *(ushort *)((int)arg1 + 10)) & 0x8000;
  value3 = value5 + value4;
  if (((value4 < 0x7fff) && (value5 < 0x7fff)) && (value3 < 0xbffe)) {
    if (value3 < 0x3fc0) {
LAB_004b901d:
      arg1[2] = 0;
      arg1[1] = 0;
      *arg1 = 0;
      return;
    }
    if (((value4 != 0) || (value3 = value3 + 1, (arg1[2] & 0x7fffffffU) != 0)) ||
       ((value4 = 0, arg1[1] != 0 || (*arg1 != 0)))) {
      if (((value5 == 0) && (value3 = value3 + 1, (arg2[2] & 0x7fffffffU) == 0)) &&
         ((arg2[1] == 0 && (*arg2 == 0)))) goto LAB_004b901d;
      localState3 = 0;
      localState9 = &localState7;
      arg2 = (int *)0x5;
      do {
        if (0 < (int)arg2) {
          localState10 = (ushort *)(localState3 * 2 + (int)arg1);
          localState2 = (ushort *)(intCursor2 + 2);
          localState5 = (int)arg2;
          do {
            value2 = AddUInt32WithCarry(*(undefined4 *)(localState9 + -2),
                                       (uint)*localState10 * (uint)*localState2,localState9 + -2);
            if (value2 != 0) {
              *localState9 = *localState9 + 1;
            }
            localState10 = localState10 + 1;
            localState2 = localState2 + -1;
            localState5 = localState5 + -1;
          } while (localState5 != 0);
        }
        localState9 = localState9 + 1;
        localState3 = localState3 + 1;
        arg2 = (int *)((int)arg2 + -1);
      } while (0 < (int)arg2);
      *( undefined2 *)((int)&arg1 + 0) = value3 + 0xc002;
      if ((short)(ushort)arg1 < 1) {
LAB_004b90d1:
        *( undefined2 *)((int)&arg1 + 0) = (ushort)arg1 - 1;
        if ((short)(ushort)arg1 < 0) {
          value2 = -(int)(short)(ushort)arg1;
          *( undefined2 *)((int)&arg1 + 0) = (ushort)arg1 + (short)value2;
          do {
            if ((localState8 & 1) != 0) {
              localState4 = localState4 + 1;
            }
            ShiftUInt96RightOne(&localState8);
            value2 = value2 + -1;
          } while (value2 != 0);
          if (localState4 != 0) {
            localState8 = localState8 | 1;
          }
        }
      }
      else {
        do {
          if ((localState & 0x80) != 0) break;
          ShiftUInt96LeftOne(&localState8);
          *( undefined2 *)((int)&arg1 + 0) = (ushort)arg1 - 1;
        } while (0 < (short)(ushort)arg1);
        if ((short)(ushort)arg1 < 1) goto LAB_004b90d1;
      }
      if ((0x8000 < CONCAT11(localState14,localState8)) ||
         (shortValue = CONCAT11(localState,localState11), value = CONCAT22(localState6,localState12),
         value2 = CONCAT22(localState7,localState13),
         (CONCAT22(localState13,CONCAT11(localState14,localState8)) & 0x1ffff) == 0x18000)) {
        if (CONCAT22(localState7,localState13) == -1) {
          value2 = 0;
          if (CONCAT22(localState6,localState12) == -1) {
            if (CONCAT11(localState,localState11) == -1) {
              *( undefined2 *)((int)&arg1 + 0) = (ushort)arg1 + 1;
              shortValue = -0x8000;
              value = 0;
              value2 = 0;
            }
            else {
              shortValue = CONCAT11(localState,localState11) + 1;
              value = 0;
              value2 = 0;
            }
          }
          else {
            shortValue = CONCAT11(localState,localState11);
            value = CONCAT22(localState6,localState12) + 1;
          }
        }
        else {
          value2 = CONCAT22(localState7,localState13) + 1;
          shortValue = CONCAT11(localState,localState11);
          value = CONCAT22(localState6,localState12);
        }
      }
      localState7 = (short)((uint)value2 >> 0x10);
      localState13 = (undefined2)value2;
      localState6 = (undefined2)((uint)value >> 0x10);
      localState12 = (undefined2)value;
      localState = (byte)((ushort)shortValue >> 8);
      localState11 = (undefined1)shortValue;
      if (0x7ffe < (ushort)arg1) goto LAB_004b917a;
      value4 = (ushort)arg1 | value6;
      *(undefined2 *)intCursor = localState13;
      *(uint *)((int)intCursor + 2) = CONCAT22(localState12,localState7);
      *(uint *)((int)intCursor + 6) = CONCAT13(localState,CONCAT12(localState11,localState6));
    }
    *(ushort *)((int)intCursor + 10) = value4;
  }
  else {
LAB_004b917a:
    intCursor[1] = 0;
    *intCursor = 0;
    intCursor[2] = (-(uint)(value6 != 0) & 0x80000000) + 0x7fff8000;
  }
  return;
}

