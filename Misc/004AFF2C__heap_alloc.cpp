#include "tarzan_ghidra_types.hpp"

// Address: 0x004AFF2C
// Label: _heap_alloc
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _heap_alloc(uint arg1)

{
  int value;
  uint dwBytes;
  void *localState;
  code *localState3;
  undefined *localState4;
  undefined4 localState2;
  
  localState2 = 0xffffffff;
  localState4 = &DAT_004ba4d0;
  localState3 = _except_handler3;
  localState = ExceptionList;
  if (OsVerResult == 3) {
    ExceptionList = &localState;
    if (arg1 <= g_CrtSmallBlockHeapInitMode) {
      ExceptionList = &localState;
      _lock(9);
      localState2 = 0;
      value = __sbh_alloc_block(arg1);
      localState2 = 0xffffffff;
      heap_alloc_UnlockHeapPathA();
      if (value != 0) {
        ExceptionList = localState;
        return;
      }
    }
  }
  else {
    ExceptionList = &localState;
    if (OsVerResult == 2) {
      if (arg1 == 0) {
        dwBytes = 0x10;
      }
      else {
        dwBytes = arg1 + 0xf & 0xfffffff0;
      }
      ExceptionList = &localState;
      if (dwBytes <= g_CrtVirtualSmallBlockMaxAllocSize) {
        ExceptionList = &localState;
        _lock(9);
        localState2 = 1;
        value = AllocateVirtualSmallBlockHeapBlock(dwBytes >> 4);
        localState2 = 0xffffffff;
        heap_alloc_UnlockHeapPathB();
        if (value != 0) {
          ExceptionList = localState;
          return;
        }
      }
      goto LAB_004b000b;
    }
  }
  if (arg1 == 0) {
    arg1 = 1;
  }
  dwBytes = arg1 + 0xf & 0xfffffff0;
LAB_004b000b:
  HeapAlloc(newHeapPTR,0,dwBytes);
  ExceptionList = localState;
  return;
}

