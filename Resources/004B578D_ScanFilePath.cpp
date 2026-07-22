#include "tarzan_ghidra_types.hpp"

// Address: 0x004B578D
// Label: ScanFilePath
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ScanFilePath(byte *arg1,undefined4 *arg2,byte *arg3,int *arg4,int *arg5)

{
  byte flagByte;
  bool flagByte2;
  bool flagByte3;
  byte *value2;
  byte *value3;
  uint value;
  undefined4 *dataCursor;
  
  *arg5 = 0;
  *arg4 = 1;
  if (arg2 != (undefined4 *)0x0) {
    *arg2 = arg3;
    arg2 = arg2 + 1;
  }
  if (*arg1 == 0x22) {
    while( true ) {
      flagByte = arg1[1];
      value2 = arg1 + 1;
      if ((flagByte == 0x22) || (flagByte == 0)) break;
      if (((*(byte *)((int)&DAT_00c47120 + flagByte + 1) & 4) != 0) &&
         (*arg5 = *arg5 + 1, arg3 != (byte *)0x0)) {
        *arg3 = *value2;
        arg3 = arg3 + 1;
        value2 = arg1 + 2;
      }
      *arg5 = *arg5 + 1;
      arg1 = value2;
      if (arg3 != (byte *)0x0) {
        *arg3 = *value2;
        arg3 = arg3 + 1;
      }
    }
    *arg5 = *arg5 + 1;
    if (arg3 != (byte *)0x0) {
      *arg3 = 0;
      arg3 = arg3 + 1;
    }
    if (*value2 == 0x22) {
      value2 = arg1 + 2;
    }
  }
  else {
    do {
      *arg5 = *arg5 + 1;
      if (arg3 != (byte *)0x0) {
        *arg3 = *arg1;
        arg3 = arg3 + 1;
      }
      flagByte = *arg1;
      value2 = arg1 + 1;
      if ((*(byte *)((int)&DAT_00c47120 + flagByte + 1) & 4) != 0) {
        *arg5 = *arg5 + 1;
        if (arg3 != (byte *)0x0) {
          *arg3 = *value2;
          arg3 = arg3 + 1;
        }
        value2 = arg1 + 2;
      }
      if (flagByte == 0x20) break;
      if (flagByte == 0) goto LAB_004b5838;
      arg1 = value2;
    } while (flagByte != 9);
    if (flagByte == 0) {
LAB_004b5838:
      value2 = value2 + -1;
    }
    else if (arg3 != (byte *)0x0) {
      arg3[-1] = 0;
    }
  }
  flagByte2 = false;
  dataCursor = arg2;
  while (*value2 != 0) {
    for (; (*value2 == 0x20 || (*value2 == 9)); value2 = value2 + 1) {
    }
    if (*value2 == 0) break;
    if (dataCursor != (undefined4 *)0x0) {
      *dataCursor = arg3;
      dataCursor = dataCursor + 1;
      arg2 = dataCursor;
    }
    *arg4 = *arg4 + 1;
    while( true ) {
      flagByte3 = true;
      value = 0;
      for (; *value2 == 0x5c; value2 = value2 + 1) {
        value = value + 1;
      }
      if (*value2 == 0x22) {
        value3 = value2;
        if ((value & 1) == 0) {
          if ((!flagByte2) || (value3 = value2 + 1, value2[1] != 0x22)) {
            flagByte3 = false;
            value3 = value2;
          }
          flagByte2 = !flagByte2;
          dataCursor = arg2;
        }
        value = value >> 1;
        value2 = value3;
      }
      for (; value != 0; value = value - 1) {
        if (arg3 != (byte *)0x0) {
          *arg3 = 0x5c;
          arg3 = arg3 + 1;
        }
        *arg5 = *arg5 + 1;
      }
      flagByte = *value2;
      if ((flagByte == 0) || ((!flagByte2 && ((flagByte == 0x20 || (flagByte == 9)))))) break;
      if (flagByte3) {
        if (arg3 == (byte *)0x0) {
          if ((*(byte *)((int)&DAT_00c47120 + flagByte + 1) & 4) != 0) {
            value2 = value2 + 1;
            *arg5 = *arg5 + 1;
          }
        }
        else {
          if ((*(byte *)((int)&DAT_00c47120 + flagByte + 1) & 4) != 0) {
            *arg3 = flagByte;
            arg3 = arg3 + 1;
            value2 = value2 + 1;
            *arg5 = *arg5 + 1;
          }
          *arg3 = *value2;
          arg3 = arg3 + 1;
        }
        *arg5 = *arg5 + 1;
      }
      value2 = value2 + 1;
    }
    if (arg3 != (byte *)0x0) {
      *arg3 = 0;
      arg3 = arg3 + 1;
    }
    *arg5 = *arg5 + 1;
  }
  if (dataCursor != (undefined4 *)0x0) {
    *dataCursor = 0;
  }
  *arg4 = *arg4 + 1;
  return;
}

