#include "tarzan_ghidra_types.hpp"

// Address: 0x004B43B6
// Label: ComputeLongDoubleRemainderReduced
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ComputeLongDoubleRemainderReduced(undefined4 arg1,uint arg2,ushort arg3)

{
  undefined4 inputEax;
  int value3;
  float10 value;
  float10 value2;
  undefined4 incomingStackArg;
  undefined2 localState;
  undefined2 localState2;
  ushort incomingStackArg2;
  
  if ((((((CONCAT22(arg3,*( undefined2 *)((int)&arg2 + 2)) ^ 0x700) & 0x700) == 0) &&
       ((&g_CrtLongDoubleRemainderByteTable)[(*( undefined2 *)((int)&arg2 + 2) & 0x7800) >> 0xb] != '\0')) &&
      ((arg3 & 0x7fff) != 0x7fff)) &&
     ((((incomingStackArg2 & 0x7fff) != 0 && ((incomingStackArg2 & 0x7fff) != 0x7fff)) &&
      (((_uStack00000020 & 0x7fffffff) == 0 && ((arg2 & 0x7fffffff) == 0)))))) {
    if ((ushort)((arg3 & 0x7fff) + 0x3f) < (incomingStackArg2 & 0x7fff)) {
      value3 = ((incomingStackArg2 & 0x7fff) - (arg3 & 0x7fff) & 0x3f | 0x20) + 1;
      value2 = ABS((float10)CONCAT28(incomingStackArg2 & 0x7fff | arg3 & 0x8000,
                                    CONCAT26(*( undefined2 *)((int)&arg2 + 2),CONCAT24((undefined2)arg2,arg1))));
      value = ABS((float10)CONCAT28(incomingStackArg2,
                                    CONCAT26(localState2,
                                             CONCAT24(localState,incomingStackArg))));
      do {
        if (value2 <= value) {
          value = value - value2;
        }
        value2 = value2 * (float10)_k_CrtLongDoubleRemainderScaleB;
        value3 = value3 + -1;
      } while (value3 != 0);
    }
    else {
      while (-1 < (int)((incomingStackArg2 & 0x7fff) - ((arg3 & 0x7fff) + 10))) {
        value = (float10)CONCAT28(incomingStackArg2,
                                  CONCAT26(localState2,CONCAT24(localState,incomingStackArg)
                                          ));
        value2 = (float10)CONCAT28((incomingStackArg2 & 0x7fff) -
                                  ((incomingStackArg2 & 0x7fff) - arg3 & 7 | 4) |
                                  arg3 & 0x8000,
                                  CONCAT26(*( undefined2 *)((int)&arg2 + 2),CONCAT24((undefined2)arg2,arg1)));
        value = value - (value / value2) * value2;
        incomingStackArg = SUB104(value,0);
        localState = (undefined2)((unkuint10)value >> 0x20);
        localState2 = (undefined2)((unkuint10)value >> 0x30);
        incomingStackArg2 = (ushort)((unkuint10)value >> 0x40);
      }
    }
  }
  return inputEax;
}

