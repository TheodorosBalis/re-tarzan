#include "tarzan_ghidra_types.hpp"

// Address: 0x004B72A1
// Label: DispatchFloatingPointConversionError
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void DispatchFloatingPointConversionError(int arg1,int *arg2,ushort *arg3)

{
  int value;
  undefined4 value2;
  undefined1 localState3 [40];
  undefined8 localState2;
  uint localState;
  
  arg3 = (ushort *)(uint)*arg3;
  value = *arg2;
  if (value == 1) {
LAB_004b72e6:
    value2 = 8;
  }
  else if (value == 2) {
    value2 = 4;
  }
  else if (value == 3) {
    value2 = 0x11;
  }
  else if (value == 4) {
    value2 = 0x12;
  }
  else {
    if (value == 5) goto LAB_004b72e6;
    if (value == 7) {
      *arg2 = 1;
      goto LAB_004b733c;
    }
    if (value != 8) goto LAB_004b733c;
    value2 = 0x10;
  }
  value = HandleMaskedFloatingPointExceptions(value2,arg2 + 6,arg3);
  if (value == 0) {
    if (((arg1 == 0x10) || (arg1 == 0x16)) || (arg1 == 0x1d)) {
      localState2 = *(undefined8 *)(arg2 + 4);
      localState = localState & 0xffffffe3 | 3;
    }
    else {
      localState = localState & 0xfffffffe;
    }
    RaiseStructuredFloatingPointException(localState3,&arg3,value2,arg1,arg2 + 2,arg2 + 6);
  }
LAB_004b733c:
  UpdateX87ControlWord(arg3,0xffff);
  if (((*arg2 != 8) && (g_CrtSuppressUserMathErrorHook == 0)) &&
     (value = UserMathErrorHookNoOp(arg2), value != 0)) {
    return;
  }
  SetErrnoFromFloatingPointError(*arg2);
  return;
}

