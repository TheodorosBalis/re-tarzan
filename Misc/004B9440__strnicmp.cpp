#include "tarzan_ghidra_types.hpp"

// Address: 0x004B9440
// Label: _strnicmp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _strnicmp(byte *arg1,char *arg2,int arg3)

{
  char resultFlag;
  int value;
  byte flagByte;
  ushort value2;
  uint value3;
  undefined4 value4;
  uint value5;
  bool flagByte2;
  uint value6;
  
  value = _g_CrtLocaleRefCount;
  value4 = 0;
  if (arg3 != 0) {
    if (g_CrtMultibyteLocaleActive == 0) {
      do {
        flagByte = *arg1;
        resultFlag = *arg2;
        value2 = CONCAT11(flagByte,resultFlag);
        if (flagByte == 0) break;
        value2 = CONCAT11(flagByte,resultFlag);
        value5 = (uint)value2;
        if (resultFlag == '\0') break;
        arg1 = arg1 + 1;
        arg2 = arg2 + 1;
        if ((0x40 < flagByte) && (flagByte < 0x5b)) {
          value5 = (uint)CONCAT11(flagByte + 0x20,resultFlag);
        }
        value2 = (ushort)value5;
        flagByte = (byte)value5;
        if ((0x40 < flagByte) && (flagByte < 0x5b)) {
          value2 = (ushort)CONCAT31((int3)(value5 >> 8),flagByte + 0x20);
        }
        flagByte = (byte)(value2 >> 8);
        flagByte2 = flagByte < (byte)value2;
        if (flagByte != (byte)value2) goto LAB_004b949f;
        arg3 = arg3 + -1;
      } while (arg3 != 0);
      value4 = 0;
      flagByte = (byte)(value2 >> 8);
      flagByte2 = flagByte < (byte)value2;
      if (flagByte != (byte)value2) {
LAB_004b949f:
        value4 = 0xffffffff;
        if (!flagByte2) {
          value4 = 1;
        }
      }
    }
    else {
      LOCK();
      _g_CrtLocaleRefCount = _g_CrtLocaleRefCount + 1;
      UNLOCK();
      flagByte2 = 0 < g_CrtLocaleLockActive;
      if (flagByte2) {
        LOCK();
        UNLOCK();
        _g_CrtLocaleRefCount = value;
        _lock(0x13);
      }
      value6 = (uint)flagByte2;
      value3 = 0;
      value5 = 0;
      do {
        value3 = CONCAT31((int3)(value3 >> 8),*arg1);
        value5 = CONCAT31((int3)(value5 >> 8),*arg2);
        if ((value3 == 0) || (value5 == 0)) break;
        arg1 = arg1 + 1;
        arg2 = arg2 + 1;
        value5 = _tolower_lk(value5,value3);
        value3 = _tolower_lk();
        flagByte2 = value3 < value5;
        if (value3 != value5) goto LAB_004b9515;
        arg3 = arg3 + -1;
      } while (arg3 != 0);
      value4 = 0;
      flagByte2 = value3 < value5;
      if (value3 != value5) {
LAB_004b9515:
        value4 = 0xffffffff;
        if (!flagByte2) {
          value4 = 1;
        }
      }
      if (value6 == 0) {
        LOCK();
        _g_CrtLocaleRefCount = _g_CrtLocaleRefCount + -1;
        UNLOCK();
      }
      else {
        _unlock(0x13);
      }
    }
  }
  return value4;
}

