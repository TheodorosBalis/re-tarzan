#include "tarzan_ghidra_types.hpp"

// Address: 0x004B7E57
// Label: __mtold12
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void __mtold12(char *arg1,int arg2,uint *arg3)

{
  uint *dataCursor;
  uint localState2;
  uint localState;
  uint localState4;
  int localState3;
  
  dataCursor = arg3;
  localState3 = 0x404e;
  *arg3 = 0;
  arg3[1] = 0;
  arg3[2] = 0;
  if (arg2 != 0) {
    arg3 = (uint *)arg2;
    do {
      localState2 = *dataCursor;
      localState = dataCursor[1];
      localState4 = dataCursor[2];
      ShiftUInt96LeftOne(dataCursor);
      ShiftUInt96LeftOne(dataCursor);
      ___add_12(dataCursor,&localState2);
      ShiftUInt96LeftOne(dataCursor);
      localState = 0;
      localState4 = 0;
      localState2 = (uint)*arg1;
      ___add_12(dataCursor,&localState2);
      arg1 = arg1 + 1;
      arg3 = (uint *)((int)arg3 + -1);
    } while (arg3 != (uint *)0x0);
  }
  while (dataCursor[2] == 0) {
    dataCursor[2] = dataCursor[1] >> 0x10;
    localState3 = localState3 + 0xfff0;
    dataCursor[1] = *dataCursor >> 0x10 | dataCursor[1] << 0x10;
    *dataCursor = *dataCursor << 0x10;
  }
  while ((dataCursor[2] & 0x8000) == 0) {
    ShiftUInt96LeftOne(dataCursor);
    localState3 = localState3 + 0xffff;
  }
  *(undefined2 *)((int)dataCursor + 10) = (undefined2)localState3;
  return;
}

