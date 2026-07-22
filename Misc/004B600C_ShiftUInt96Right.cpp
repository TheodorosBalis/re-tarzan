#include "tarzan_ghidra_types.hpp"

// Address: 0x004B600C
// Label: ShiftUInt96Right
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ShiftUInt96Right(uint *arg1,uint arg2)

{
  uint value4;
  int value;
  byte flagByte;
  int value2;
  int value3;
  uint *dataCursor;
  int localState;
  
  localState = 3;
  value = (int)arg2 / 0x20;
  value3 = (int)arg2 % 0x20;
  arg2 = 0;
  flagByte = (byte)value3;
  dataCursor = arg1;
  do {
    value4 = *dataCursor;
    *dataCursor = value4 >> (flagByte & 0x1f) | arg2;
    dataCursor = dataCursor + 1;
    arg2 = (value4 & ~(-1 << (flagByte & 0x1f))) << (0x20 - flagByte & 0x1f);
    localState = localState + -1;
  } while (localState != 0);
  value3 = 2;
  value2 = 8;
  do {
    if (value3 < value) {
      *(undefined4 *)(value2 + (int)arg1) = 0;
    }
    else {
      *(undefined4 *)(value2 + (int)arg1) = *(undefined4 *)(value2 + value * -4 + (int)arg1);
    }
    value3 = value3 + -1;
    value2 = value2 + -4;
  } while (-1 < value2);
  return;
}

