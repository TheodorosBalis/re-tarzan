#include "tarzan_ghidra_types.hpp"

// Address: 0x004B5EE8
// Label: RoundUInt96UpAtBit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int RoundUInt96UpAtBit(int arg1,int arg2)

{
  int value;
  int value2;
  undefined4 *dataCursor;
  
  dataCursor = (undefined4 *)(arg1 + (arg2 / 0x20) * 4);
  value = AddUInt32WithCarry(*dataCursor,1 << (0x1fU - (char)(arg2 % 0x20) & 0x1f),dataCursor);
  value2 = arg2 / 0x20 + -1;
  if (-1 < value2) {
    dataCursor = (undefined4 *)(arg1 + value2 * 4);
    do {
      if (value == 0) {
        return 0;
      }
      value = AddUInt32WithCarry(*dataCursor,1,dataCursor);
      value2 = value2 + -1;
      dataCursor = dataCursor + -1;
    } while (-1 < value2);
  }
  return 0;
}

