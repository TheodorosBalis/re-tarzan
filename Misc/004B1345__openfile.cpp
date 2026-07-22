#include "tarzan_ghidra_types.hpp"

// Address: 0x004B1345
// Label: _openfile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _openfile(undefined4 arg1,char *arg2,undefined4 arg3,undefined4 *arg4)

{
  char resultFlag;
  bool flagByte;
  bool flagByte2;
  bool flagByte3;
  int value;
  uint value2;
  uint value3;
  
  flagByte3 = false;
  flagByte2 = false;
  resultFlag = *arg2;
  if (resultFlag == 'a') {
    value2 = 0x109;
  }
  else {
    if (resultFlag == 'r') {
      value2 = 0;
      value3 = g_CrtOpenFileState | 1;
      goto LAB_004b1386;
    }
    if (resultFlag != 'w') {
      return (undefined4 *)0x0;
    }
    value2 = 0x301;
  }
  value3 = g_CrtOpenFileState | 2;
LAB_004b1386:
  flagByte = true;
LAB_004b1389:
  resultFlag = arg2[1];
  arg2 = arg2 + 1;
  if ((resultFlag == '\0') || (!flagByte)) {
    value = _sopen(arg1,value2,arg3,0x1a4);
    if (value < 0) {
      return (undefined4 *)0x0;
    }
    _g_AllocatedStreamBufferCount = _g_AllocatedStreamBufferCount + 1;
    arg4[3] = value3;
    arg4[1] = 0;
    *arg4 = 0;
    arg4[2] = 0;
    arg4[7] = 0;
    arg4[4] = value;
    return arg4;
  }
  if (resultFlag < 'U') {
    if (resultFlag == 'T') {
      if ((value2 & 0x1000) == 0) {
        value2 = value2 | 0x1000;
        goto LAB_004b1389;
      }
    }
    else if (resultFlag == '+') {
      if ((value2 & 2) == 0) {
        value2 = value2 & 0xfffffffe | 2;
        value3 = value3 & 0xfffffffc | 0x80;
        goto LAB_004b1389;
      }
    }
    else if (resultFlag == 'D') {
      if ((value2 & 0x40) == 0) {
        value2 = value2 | 0x40;
        goto LAB_004b1389;
      }
    }
    else if (resultFlag == 'R') {
      if (!flagByte2) {
        flagByte2 = true;
        value2 = value2 | 0x10;
        goto LAB_004b1389;
      }
    }
    else if ((resultFlag == 'S') && (!flagByte2)) {
      flagByte2 = true;
      value2 = value2 | 0x20;
      goto LAB_004b1389;
    }
  }
  else {
    if (resultFlag == 'b') {
      if ((value2 & 0xc000) != 0) goto LAB_004b1469;
      value2 = value2 | 0x8000;
      goto LAB_004b1389;
    }
    if (resultFlag == 'c') {
      if (!flagByte3) {
        flagByte3 = true;
        value3 = value3 | 0x4000;
        goto LAB_004b1389;
      }
    }
    else {
      if (resultFlag != 'n') {
        if ((resultFlag != 't') || ((value2 & 0xc000) != 0)) goto LAB_004b1469;
        value2 = value2 | 0x4000;
        goto LAB_004b1389;
      }
      if (!flagByte3) {
        flagByte3 = true;
        value3 = value3 & 0xffffbfff;
        goto LAB_004b1389;
      }
    }
  }
LAB_004b1469:
  flagByte = false;
  goto LAB_004b1389;
}

