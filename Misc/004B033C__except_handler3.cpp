#include "tarzan_ghidra_types.hpp"

// Address: 0x004B033C
// Label: _except_handler3
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 _except_handler3(int arg1,int arg2,undefined4 arg3)

{
  int value;
  int callResult;
  undefined1 *dataCursor;
  int value2;
  int localState;
  undefined4 localState2;
  
  dataCursor = &stack0xfffffffc;
  if ((*(uint *)(arg1 + 4) & 6) == 0) {
    localState = arg1;
    localState2 = arg3;
    *(int **)(arg2 + -4) = &localState;
    value = *(int *)(arg2 + 8);
    for (value2 = *(int *)(arg2 + 0xc); value2 != -1; value2 = *(int *)(value + value2 * 0xc)) {
      if (*(int *)(value + 4 + value2 * 0xc) != 0) {
        value = (**(code **)(value + 4 + value2 * 0xc))();
        arg2 = *(int *)(dataCursor + 0xc);
        if (value != 0) {
          if (value < 0) {
            return 0;
          }
          value = *(int *)(arg2 + 8);
          _global_unwind2(arg2);
          dataCursor = (undefined1 *)(arg2 + 0x10);
          _local_unwind2(arg2,value2);
          _NLG_Notify(1);
          *(undefined4 *)(arg2 + 0xc) = *(undefined4 *)(value + callResult * 4);
          (**(code **)(value + 8 + callResult * 4))();
        }
      }
      value = *(int *)(arg2 + 8);
    }
  }
  else {
    _local_unwind2(arg2,0xffffffff,&stack0xfffffffc,&stack0xfffffffc);
  }
  return 1;
}

