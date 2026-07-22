#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0286
// Label: _local_unwind2
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __local_unwind2
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

void _local_unwind2(int arg1,int arg2)

{
  int value;
  int value2;
  void *localState4;
  code *localState3;
  undefined4 localState2;
  int localState;
  
  localState = arg1;
  localState3 = _local_unwind2_exception_handler;
  localState4 = ExceptionList;
  ExceptionList = &localState4;
  while( true ) {
    value = *(int *)(arg1 + 8);
    value2 = *(int *)(arg1 + 0xc);
    if ((value2 == -1) || (value2 == arg2)) break;
    localState2 = *(undefined4 *)(value + value2 * 0xc);
    *(undefined4 *)(arg1 + 0xc) = localState2;
    if (*(int *)(value + 4 + value2 * 0xc) == 0) {
      _NLG_Notify(0x101);
      (**(code **)(value + 8 + value2 * 0xc))();
    }
  }
  ExceptionList = localState4;
  return;
}

