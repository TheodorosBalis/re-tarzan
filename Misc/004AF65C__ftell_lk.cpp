#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF65C
// Label: _ftell_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _ftell_lk(char *arg1)

{
  uint value3;
  uint value4;
  byte flagByte;
  undefined4 *dataCursor;
  char *stringCursor;
  int value;
  char *stringCursor2;
  char *stringCursor3;
  int value2;
  int localState2;
  int localState;
  
  dataCursor = (undefined4 *)arg1;
  value3 = *(uint *)((int)arg1 + 0x10);
  if (*(int *)((int)arg1 + 4) < 0) {
    *(undefined4 *)((int)arg1 + 4) = 0;
  }
  localState = _lseek(value3,0,1);
  if (localState < 0) {
LAB_004af6ea:
    localState2 = -1;
  }
  else {
    value4 = *(uint *)((int)arg1 + 0xc);
    if ((value4 & 0x108) == 0) {
      return localState - *(int *)((int)arg1 + 4);
    }
    stringCursor = *(char **)arg1;
    stringCursor2 = *(char **)((int)arg1 + 8);
    localState2 = (int)stringCursor - (int)stringCursor2;
    if ((value4 & 3) == 0) {
      if ((value4 & 0x80) == 0) {
        dataCursor = (undefined4 *)_errno();
        *dataCursor = 0x16;
        goto LAB_004af6ea;
      }
    }
    else {
      stringCursor3 = stringCursor2;
      if ((*(byte *)((&g_FileDescriptorBlockTable)[(int)value3 >> 5] + 4 + (value3 & 0x1f) * 0x24) &
          0x80) != 0) {
        for (; stringCursor3 < stringCursor; stringCursor3 = stringCursor3 + 1) {
          if (*stringCursor3 == '\n') {
            localState2 = localState2 + 1;
          }
        }
      }
    }
    if (localState != 0) {
      if ((*(byte *)((int)arg1 + 0xc) & 1) != 0) {
        if (*(int *)((int)arg1 + 4) == 0) {
          localState2 = 0;
        }
        else {
          stringCursor = stringCursor + (*(int *)((int)arg1 + 4) - (int)stringCursor2);
          value2 = (value3 & 0x1f) * 0x24;
          if ((*(byte *)(value2 + 4 + (&g_FileDescriptorBlockTable)[(int)value3 >> 5]) & 0x80) != 0) {
            value = _lseek(value3,0,2);
            if (value == localState) {
              stringCursor2 = *(char **)((int)arg1 + 8);
              stringCursor3 = stringCursor2 + (int)stringCursor;
              arg1 = stringCursor;
              for (; stringCursor2 < stringCursor3; stringCursor2 = stringCursor2 + 1) {
                if (*stringCursor2 == '\n') {
                  arg1 = arg1 + 1;
                }
              }
              flagByte = *(byte *)((int)dataCursor + 0xd) & 0x20;
            }
            else {
              _lseek(value3,localState,0);
              stringCursor2 = (char *)0x200;
              if ((((char *)0x200 < stringCursor) || ((*(uint *)((int)arg1 + 0xc) & 8) == 0)) ||
                 ((*(uint *)((int)arg1 + 0xc) & 0x400) != 0)) {
                stringCursor2 = *(char **)((int)arg1 + 0x18);
              }
              flagByte = *(byte *)(value2 + 4 + (&g_FileDescriptorBlockTable)[(int)value3 >> 5]) & 4;
              arg1 = stringCursor2;
            }
            stringCursor = arg1;
            if (flagByte != 0) {
              stringCursor = arg1 + 1;
            }
          }
          arg1 = stringCursor;
          localState = localState - (int)arg1;
        }
      }
      localState2 = localState2 + localState;
    }
  }
  return localState2;
}

