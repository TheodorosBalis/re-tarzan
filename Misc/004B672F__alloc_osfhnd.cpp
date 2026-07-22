#include "tarzan_ghidra_types.hpp"

// Address: 0x004B672F
// Label: _alloc_osfhnd
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _alloc_osfhnd(void)

{
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  int *intCursor;
  int value;
  int localState2;
  int localState;
  
  value = -1;
  _lock(0x12);
  localState2 = 0;
  localState = 0;
  intCursor = &g_FileDescriptorBlockTable;
  while (dataCursor2 = (undefined4 *)*intCursor, dataCursor = dataCursor2, dataCursor2 != (undefined4 *)0x0) {
    for (; dataCursor2 < dataCursor + 0x120; dataCursor2 = dataCursor2 + 9) {
      if ((*(byte *)(dataCursor2 + 1) & 1) == 0) {
        if (dataCursor2[2] == 0) {
          _lock(0x11);
          if (dataCursor2[2] == 0) {
            InitializeCriticalSection((LPCRITICAL_SECTION)(dataCursor2 + 3));
            dataCursor2[2] = dataCursor2[2] + 1;
          }
          _unlock(0x11);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(dataCursor2 + 3));
        if ((*(byte *)(dataCursor2 + 1) & 1) == 0) {
          *dataCursor2 = 0xffffffff;
          value = ((int)dataCursor2 - *intCursor) / 0x24 + localState;
          if (value != -1) goto LAB_004b6841;
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(dataCursor2 + 3));
      }
      dataCursor = (undefined4 *)*intCursor;
    }
    localState = localState + 0x20;
    intCursor = intCursor + 1;
    localState2 = localState2 + 1;
    if (0xc4735f < (int)intCursor) goto LAB_004b6841;
  }
  dataCursor2 = malloc(0x480);
  if (dataCursor2 != (undefined4 *)0x0) {
    g_FileDescriptorCapacity = g_FileDescriptorCapacity + 0x20;
    (&g_FileDescriptorBlockTable)[localState2] = dataCursor2;
    dataCursor = dataCursor2;
    for (; dataCursor2 < dataCursor + 0x120; dataCursor2 = dataCursor2 + 9) {
      *(undefined1 *)(dataCursor2 + 1) = 0;
      *dataCursor2 = 0xffffffff;
      dataCursor2[2] = 0;
      *(undefined1 *)((int)dataCursor2 + 5) = 10;
      dataCursor = (undefined4 *)(&g_FileDescriptorBlockTable)[localState2];
    }
    value = localState2 << 5;
    _lock_fhandle(value);
  }
LAB_004b6841:
  _unlock(0x12);
  return value;
}

