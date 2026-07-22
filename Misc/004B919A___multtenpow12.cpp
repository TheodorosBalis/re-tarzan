#include "tarzan_ghidra_types.hpp"

// Address: 0x004B919A
// Label: __multtenpow12
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void __multtenpow12(undefined2 *arg1,uint arg2,int arg3)

{
  uint value;
  uint value2;
  undefined **dataCursor;
  undefined **dataCursor2;
  undefined2 localState;
  undefined4 localState2;
  undefined2 localState3;
  undefined *localState4;
  
  dataCursor = &PTR_s_November_0051be70;
  if (arg2 != 0) {
    if ((int)arg2 < 0) {
      arg2 = -arg2;
      dataCursor = (undefined **)0x51bfd0;
    }
    if (arg3 == 0) {
      *arg1 = 0;
    }
    while (arg2 != 0) {
      dataCursor = dataCursor + 0x15;
      value = (int)arg2 >> 3;
      value2 = arg2 & 7;
      arg2 = value;
      if (value2 != 0) {
        dataCursor2 = dataCursor + value2 * 3;
        if (0x7fff < *(ushort *)(dataCursor + value2 * 3)) {
          localState = SUB42(*dataCursor2,0);
          *( undefined2 *)((int)&localState2 + 0) = (undefined2)((uint)*dataCursor2 >> 0x10);
          *( undefined2 *)((int)&localState2 + 2) = SUB42(dataCursor2[1],0);
          localState3 = (undefined2)((uint)dataCursor2[1] >> 0x10);
          localState4 = dataCursor2[2];
          localState2 = CONCAT22(*( undefined2 *)((int)&localState2 + 2),(undefined2)localState2) + -1;
          dataCursor2 = (undefined **)&localState;
        }
        __ld12mul(arg1,dataCursor2);
      }
    }
  }
  return;
}

