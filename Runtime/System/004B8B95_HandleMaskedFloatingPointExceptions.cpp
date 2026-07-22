#include "tarzan_ghidra_types.hpp"

// Address: 0x004B8B95
// Label: HandleMaskedFloatingPointExceptions
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool HandleMaskedFloatingPointExceptions(uint arg1,double *arg2,uint arg3)

{
  double value;
  bool flagByte;
  uint mask;
  bool flagByte2;
  float10 floatValue;
  undefined8 localState;
  int localState2;
  
  mask = arg1 & 0x1f;
  flagByte = true;
  if (((arg1 & 8) != 0) && ((arg3 & 1) != 0)) {
    RaiseX87ExceptionFlags(1);
    mask = arg1 & 0x17;
    goto LAB_004b8d8a;
  }
  if (((arg1 & 4) != 0) && ((arg3 & 4) != 0)) {
    RaiseX87ExceptionFlags(4);
    mask = arg1 & 0x1b;
    goto LAB_004b8d8a;
  }
  if (((arg1 & 1) == 0) || ((arg3 & 8) == 0)) {
    if (((arg1 & 2) != 0) && ((arg3 & 0x10) != 0)) {
      flagByte2 = (arg1 & 0x10) != 0;
      if (*arg2 != _g_DoubleZero) {
        floatValue = (float10)NormalizeDoubleMantissaAndExponent(*arg2,&localState2);
        localState2 = localState2 + -0x600;
        if (localState2 < -0x432) {
          localState = 0.0;
          flagByte2 = flagByte;
        }
        else {
          localState = (double)(ulonglong)
                             (SUB87((double)floatValue,0) & 0xfffffffffffff | 0x10000000000000);
          if (localState2 < -0x3fd) {
            localState2 = -0x3fd - localState2;
            do {
              if ((((ulonglong)localState & 1) != 0) && (!flagByte2)) {
                flagByte2 = flagByte;
              }
              mask = (uint)localState >> 1;
              if (((ulonglong)localState & 0x100000000) != 0) {
                *( undefined1 *)((int)&localState + 3) = (byte)((ulonglong)localState >> 0x18) >> 1;
                *( undefined1 *)((int)&localState + 0) = (undefined3)mask;
                *( undefined4 *)((int)&localState + 0) = CONCAT13(*( undefined1 *)((int)&localState + 3),(undefined3)localState) | 0x80000000;
                mask = (uint)localState;
              }
              *( undefined4 *)((int)&localState + 0) = mask;
              localState = (double)CONCAT44(*( undefined4 *)((int)&localState + 4) >> 1,(uint)localState);
              localState2 = localState2 + -1;
            } while (localState2 != 0);
          }
          if ((double)floatValue < _g_DoubleZero) {
            localState = -localState;
          }
        }
        *arg2 = localState;
        flagByte = flagByte2;
      }
      if (flagByte) {
        RaiseX87ExceptionFlags(0x10);
      }
      mask = arg1 & 0x1d;
    }
    goto LAB_004b8d8a;
  }
  RaiseX87ExceptionFlags(8);
  mask = arg3 & 0xc00;
  value = _g_CrtDoubleInfinity;
  if (mask == 0) {
    if (*arg2 <= _g_DoubleZero) {
      value = -_g_CrtDoubleInfinity;
    }
LAB_004b8caa:
    *arg2 = value;
  }
  else {
    if (mask == 0x400) {
      value = _g_CrtDoubleMaxFinite;
      if (*arg2 <= _g_DoubleZero) {
        value = -_g_CrtDoubleInfinity;
      }
      goto LAB_004b8caa;
    }
    if (mask == 0x800) {
      if (*arg2 <= _g_DoubleZero) {
        value = -_g_CrtDoubleMaxFinite;
      }
      goto LAB_004b8caa;
    }
    if (mask == 0xc00) {
      value = _g_CrtDoubleMaxFinite;
      if (*arg2 <= _g_DoubleZero) {
        value = -_g_CrtDoubleMaxFinite;
      }
      goto LAB_004b8caa;
    }
  }
  mask = arg1 & 0x1e;
LAB_004b8d8a:
  if (((arg1 & 0x10) != 0) && ((arg3 & 0x20) != 0)) {
    RaiseX87ExceptionFlags(0x20);
    mask = mask & 0xffffffef;
  }
  return mask == 0;
}

