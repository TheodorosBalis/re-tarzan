#include "tarzan_ghidra_types.hpp"

// Address: 0x004B92A0
// Label: NormalizeDoubleMantissaAndExponent
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 NormalizeDoubleMantissaAndExponent(uint arg1,uint arg2,int *arg3)

{
  ushort value3;
  int value;
  bool flagByte;
  int value2;
  float10 floatValue;
  double localState;
  
  if ((double)CONCAT17(*( undefined1 *)((int)&arg2 + 3),CONCAT16(*( undefined1 *)((int)&arg2 + 2),CONCAT24((ushort)arg2,arg1))) ==
      _g_DoubleZero) {
    value2 = 0;
    localState = 0.0;
  }
  else if (((arg2 & 0x7ff00000) == 0) && (((arg2 & 0xfffff) != 0 || (arg1 != 0)))) {
    value2 = -0x3fd;
    if (_g_DoubleZero <=
        (double)CONCAT17(*( undefined1 *)((int)&arg2 + 3),CONCAT16(*( undefined1 *)((int)&arg2 + 2),CONCAT24((ushort)arg2,arg1)))) {
      flagByte = false;
    }
    else {
      flagByte = true;
    }
    while ((*( undefined1 *)((int)&arg2 + 2) & 0x10) == 0) {
      value = CONCAT13(*( undefined1 *)((int)&arg2 + 3),CONCAT12(*( undefined1 *)((int)&arg2 + 2),(ushort)arg2)) << 1;
      *( undefined2 *)((int)&arg2 + 0) = (ushort)value;
      *( undefined1 *)((int)&arg2 + 2) = (byte)((uint)value >> 0x10);
      *( undefined1 *)((int)&arg2 + 3) = (byte)((uint)value >> 0x18);
      if ((arg1 & 0x80000000) != 0) {
        *( undefined2 *)((int)&arg2 + 0) = (ushort)arg2 | 1;
      }
      arg1 = arg1 << 1;
      value2 = value2 + -1;
    }
    value3 = CONCAT11(*( undefined1 *)((int)&arg2 + 3),*( undefined1 *)((int)&arg2 + 2)) & 0xffef;
    *( undefined1 *)((int)&arg2 + 2) = (byte)value3;
    *( undefined1 *)((int)&arg2 + 3) = (byte)(value3 >> 8);
    if (flagByte) {
      *( undefined1 *)((int)&arg2 + 3) = *( undefined1 *)((int)&arg2 + 3) | 0x80;
    }
    floatValue = (float10)BuildLongDoubleFromScaledDouble
                               (CONCAT17(*( undefined1 *)((int)&arg2 + 3),
                                         CONCAT16(*( undefined1 *)((int)&arg2 + 2),CONCAT24((ushort)arg2,arg1))),
                                0);
    localState = (double)floatValue;
  }
  else {
    floatValue = (float10)BuildLongDoubleFromScaledDouble
                               (CONCAT17(*( undefined1 *)((int)&arg2 + 3),
                                         CONCAT16(*( undefined1 *)((int)&arg2 + 2),CONCAT24((ushort)arg2,arg1))),
                                0);
    localState = (double)floatValue;
    value2 = (short)((ushort)(arg2 >> 0x14) & 0x7ff) + -0x3fe;
  }
  *arg3 = value2;
  return (float10)localState;
}

