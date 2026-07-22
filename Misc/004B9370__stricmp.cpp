#include "tarzan_ghidra_types.hpp"

// Address: 0x004B9370
// Label: _stricmp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char _stricmp(byte *arg1,byte *arg2)

{
  bool flagByte;
  int value;
  byte flagByte2;
  byte flagByte3;
  byte flagByte4;
  char resultFlag;
  uint value2;
  
  value = _g_CrtLocaleRefCount;
  if (g_CrtMultibyteLocaleActive == 0) {
    flagByte4 = 0xff;
    do {
      do {
        if (flagByte4 == 0) {
          return '\0';
        }
        flagByte4 = *arg2;
        arg2 = arg2 + 1;
        flagByte3 = *arg1;
        arg1 = arg1 + 1;
      } while (flagByte3 == flagByte4);
      flagByte2 = flagByte4 + 0xbf + (-((byte)(flagByte4 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      flagByte3 = flagByte3 + 0xbf;
      flagByte4 = flagByte3 + (-(flagByte3 < 0x1a) & 0x20U) + 0x41;
    } while (flagByte4 == flagByte2);
    resultFlag = (flagByte4 < flagByte2) * -2 + '\x01';
  }
  else {
    LOCK();
    _g_CrtLocaleRefCount = _g_CrtLocaleRefCount + 1;
    UNLOCK();
    flagByte = 0 < g_CrtLocaleLockActive;
    if (flagByte) {
      LOCK();
      UNLOCK();
      _g_CrtLocaleRefCount = value;
      _lock(0x13);
    }
    value2 = (uint)flagByte;
    flagByte4 = 0xff;
    do {
      do {
        resultFlag = '\0';
        if (flagByte4 == 0) goto LAB_004b941f;
        flagByte4 = *arg2;
        arg2 = arg2 + 1;
        flagByte3 = *arg1;
        arg1 = arg1 + 1;
      } while (flagByte4 == flagByte3);
      flagByte3 = _tolower_lk(flagByte3,flagByte4);
      flagByte4 = _tolower_lk();
    } while (flagByte3 == flagByte4);
    resultFlag = (flagByte3 < flagByte4) * -2 + '\x01';
LAB_004b941f:
    if (value2 == 0) {
      LOCK();
      _g_CrtLocaleRefCount = _g_CrtLocaleRefCount + -1;
      UNLOCK();
    }
    else {
      _unlock(0x13);
    }
  }
  return resultFlag;
}

