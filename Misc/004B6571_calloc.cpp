#include "tarzan_ghidra_types.hpp"

// Address: 0x004B6571
// Label: calloc
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

LPVOID calloc(int arg1,int arg2)

{
  int value;
  uint value2;
  uint value3;
  uint _Size;
  LPVOID localState2;
  void *localState;
  code *localState4;
  undefined *localState5;
  undefined4 localState3;
  
  localState3 = 0xffffffff;
  localState5 = &DAT_004ba900;
  localState4 = _except_handler3;
  localState = ExceptionList;
  value2 = arg1 * arg2;
  value3 = value2;
  ExceptionList = &localState;
  if (value2 < 0xffffffe1) {
    if (value2 == 0) {
      value3 = 1;
    }
    value3 = value3 + 0xf & 0xfffffff0;
    ExceptionList = &localState;
  }
  do {
    localState2 = (LPVOID)0x0;
    if (value3 < 0xffffffe1) {
      if (OsVerResult == 3) {
        if (value2 <= g_CrtSmallBlockHeapInitMode) {
          _lock(9);
          localState3 = 0;
          localState2 = (LPVOID)__sbh_alloc_block(value2);
          localState3 = 0xffffffff;
          calloc_UnlockHeapV6();
          _Size = value2;
          if (localState2 == (void *)0x0) goto LAB_004b665e;
LAB_004b664d:
          memset(localState2,0,_Size);
        }
LAB_004b6659:
        if (localState2 != (LPVOID)0x0) {
          ExceptionList = localState;
          return localState2;
        }
      }
      else {
        if ((OsVerResult != 2) || (g_CrtVirtualSmallBlockMaxAllocSize < value3)) goto LAB_004b6659;
        _lock(9);
        localState3 = 1;
        localState2 = (LPVOID)AllocateVirtualSmallBlockHeapBlock(value3 >> 4);
        localState3 = 0xffffffff;
        calloc_UnlockHeapV5();
        _Size = value3;
        if (localState2 != (void *)0x0) goto LAB_004b664d;
      }
LAB_004b665e:
      localState2 = HeapAlloc(newHeapPTR,8,value3);
    }
    if (localState2 != (LPVOID)0x0) {
      ExceptionList = localState;
      return localState2;
    }
    if (g_CrtHeapAllocationState == 0) {
      ExceptionList = localState;
      return (LPVOID)0x0;
    }
    value = _callnewh(value3);
    if (value == 0) {
      ExceptionList = localState;
      return (LPVOID)0x0;
    }
  } while( true );
}

