#include "tarzan_ghidra_types.hpp"

// Address: 0x004B3BB0
// Label: HandleCrtFdivSpecialCases
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint HandleCrtFdivSpecialCases
               (int arg1,uint arg2,ushort arg3,undefined4 arg4,uint arg5,uint arg6
               )

{
  float10 floatValue;
  uint value;
  float10 floatValue2;
  
  floatValue = (float10)CONCAT28(arg3,CONCAT44(arg2,arg1));
  while (!CARRY4(arg2,arg2)) {
    if (arg1 == 0 && arg2 == 0) {
      return 0;
    }
    if ((arg3 & 0x7fff) != 0) {
      return arg3 & 0x7fff;
    }
    value = arg6 & 0x7fff;
    if (value == 0) {
      if (CARRY4(arg5,arg5)) {
        return arg5 * 2;
      }
    }
    else if ((value == 0x7fff) || (value = arg5 * 2, !CARRY4(arg5,arg5))) {
      return value;
    }
    floatValue2 = floatValue * (float10)_k_CrtFdivHugeScaleFloat;
    arg1 = SUB104(floatValue2,0);
    arg3 = (ushort)((unkuint10)floatValue2 >> 0x40);
    arg2 = (uint)((unkuint10)floatValue2 >> 0x20);
  }
  value = arg2 * 2 ^ 0xe000000;
  if ((value & 0xe000000) != 0) {
    return value;
  }
  value = arg2 * 2 >> 0x1c;
  if ((&g_CrtFdivSpecialCaseMaskTable)[value] != '\0') {
    if (((arg3 & 0x7fff) != 0) && ((arg3 & 0x7fff) != 0x7fff)) {
      if ((arg6 & 0x7fff) != 1) {
        return arg6 & 0x7fff;
      }
      return 1;
    }
    return arg3 & 0x7fff;
  }
  return value;
}

