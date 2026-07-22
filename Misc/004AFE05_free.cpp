#include "tarzan_ghidra_types.hpp"

// Address: 0x004AFE05
// Label: free
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void free(LPVOID arg1)

{
  int value;
  undefined4 localState5;
  int localState4;
  undefined4 localState3;
  int localState2;
  void *localState;
  code *localState7;
  undefined *localState8;
  undefined4 localState6;
  
  localState6 = 0xffffffff;
  localState8 = &DAT_004ba4b8;
  localState7 = _except_handler3;
  localState = ExceptionList;
  if (arg1 == (LPVOID)0x0) {
    return;
  }
  if (OsVerResult == 3) {
    ExceptionList = &localState;
    _lock(9);
    localState6 = 0;
    localState2 = __sbh_find_block(arg1);
    if (localState2 != 0) {
      __sbh_free_block(localState2,arg1);
    }
    localState6 = 0xffffffff;
    free_UnlockHeapPathA();
    value = localState2;
  }
  else {
    ExceptionList = &localState;
    if (OsVerResult != 2) goto LAB_004afed1;
    ExceptionList = &localState;
    _lock(9);
    localState6 = 1;
    localState4 = FindVirtualSmallBlockHeapAllocation(arg1,&localState5,&localState3);
    if (localState4 != 0) {
      FreeVirtualSmallBlockHeapAllocation(localState5,localState3,localState4);
    }
    localState6 = 0xffffffff;
    free_UnlockHeapPathB();
    value = localState4;
  }
  if (value != 0) {
    ExceptionList = localState;
    return;
  }
LAB_004afed1:
  HeapFree(newHeapPTR,0,arg1);
  ExceptionList = localState;
  return;
}

