#include "tarzan_ghidra_types.hpp"

// Address: 0x004B5F3E
// Label: RoundAndTruncateUInt96
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 RoundAndTruncateUInt96(int arg1,int arg2)

{
  uint *dataCursor;
  int value;
  byte flagByte;
  int value2;
  undefined4 *dataCursor2;
  undefined4 localState;
  
  localState = 0;
  dataCursor = (uint *)(arg1 + (arg2 / 0x20) * 4);
  flagByte = 0x1f - (char)(arg2 % 0x20);
  if (((*dataCursor & 1 << (flagByte & 0x1f)) != 0) &&
     (value = AreLowerUInt96BitsZero(arg1,arg2 + 1), value == 0)) {
    localState = RoundUInt96UpAtBit(arg1,arg2 + -1);
  }
  *dataCursor = *dataCursor & -1 << (flagByte & 0x1f);
  value = arg2 / 0x20 + 1;
  if (value < 3) {
    dataCursor2 = (undefined4 *)(arg1 + value * 4);
    for (value2 = 3 - value; value2 != 0; value2 = value2 + -1) {
      *dataCursor2 = 0;
      dataCursor2 = dataCursor2 + 1;
    }
  }
  return localState;
}

