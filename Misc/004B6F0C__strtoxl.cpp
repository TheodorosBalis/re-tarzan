#include "tarzan_ghidra_types.hpp"

// Address: 0x004B6F0C
// Label: _strtoxl
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint _strtoxl(byte *arg1,int *arg2,uint arg3,uint arg4)

{
  byte *value5;
  uint value2;
  uint value3;
  int value;
  undefined4 *dataCursor;
  byte flagByte;
  uint value4;
  uint localState2;
  byte *localState;
  
  localState2 = 0;
  flagByte = *arg1;
  value5 = arg1;
  while( true ) {
    localState = value5 + 1;
    if (g_CrtLocaleEnabled < 2) {
      value2 = (byte)g_CrtCtypeTable[(uint)flagByte * 2] & 8;
    }
    else {
      value2 = _isctype(flagByte,8);
    }
    if (value2 == 0) break;
    flagByte = *localState;
    value5 = localState;
  }
  if (flagByte == 0x2d) {
    arg4 = arg4 | 2;
LAB_004b6f67:
    flagByte = *localState;
    localState = value5 + 2;
  }
  else if (flagByte == 0x2b) goto LAB_004b6f67;
  if ((((int)arg3 < 0) || (arg3 == 1)) || (0x24 < (int)arg3)) {
    if (arg2 != (int *)0x0) {
      *arg2 = (int)arg1;
    }
    return 0;
  }
  if (arg3 == 0) {
    if (flagByte != 0x30) {
      arg3 = 10;
      goto LAB_004b6fd1;
    }
    if ((*localState != 0x78) && (*localState != 0x58)) {
      arg3 = 8;
      goto LAB_004b6fd1;
    }
    arg3 = 0x10;
  }
  if (((arg3 == 0x10) && (flagByte == 0x30)) && ((*localState == 0x78 || (*localState == 0x58)))) {
    flagByte = localState[1];
    localState = localState + 2;
  }
LAB_004b6fd1:
  value2 = (uint)(0xffffffff / (ulonglong)arg3);
  do {
    value4 = (uint)flagByte;
    if (g_CrtLocaleEnabled < 2) {
      value3 = (byte)g_CrtCtypeTable[value4 * 2] & 4;
    }
    else {
      value3 = _isctype(value4,4);
    }
    if (value3 == 0) {
      if (g_CrtLocaleEnabled < 2) {
        value4 = *(ushort *)(g_CrtCtypeTable + value4 * 2) & 0x103;
      }
      else {
        value4 = _isctype(value4,0x103);
      }
      if (value4 == 0) {
LAB_004b707d:
        localState = localState + -1;
        if ((arg4 & 8) == 0) {
          if (arg2 != (int *)0x0) {
            localState = arg1;
          }
          localState2 = 0;
        }
        else if (((arg4 & 4) != 0) ||
                (((arg4 & 1) == 0 &&
                 ((((arg4 & 2) != 0 && (0x80000000 < localState2)) ||
                  (((arg4 & 2) == 0 && (0x7fffffff < localState2)))))))) {
          dataCursor = (undefined4 *)_errno();
          *dataCursor = 0x22;
          if ((arg4 & 1) == 0) {
            localState2 = ((arg4 & 2) != 0) + 0x7fffffff;
          }
          else {
            localState2 = 0xffffffff;
          }
        }
        if (arg2 != (int *)0x0) {
          *arg2 = (int)localState;
        }
        if ((arg4 & 2) == 0) {
          return localState2;
        }
        return -localState2;
      }
      value = toupper((int)(char)flagByte);
      value4 = value - 0x37;
    }
    else {
      value4 = (int)(char)flagByte - 0x30;
    }
    if (arg3 <= value4) goto LAB_004b707d;
    if ((localState2 < value2) ||
       ((localState2 == value2 && (value4 <= (uint)(0xffffffff % (ulonglong)arg3))))) {
      localState2 = localState2 * arg3 + value4;
      arg4 = arg4 | 8;
    }
    else {
      arg4 = arg4 | 0xc;
    }
    flagByte = *localState;
    localState = localState + 1;
  } while( true );
}

