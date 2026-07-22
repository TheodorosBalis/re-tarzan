#include "tarzan_ghidra_types.hpp"

// Address: 0x004B6852
// Label: _set_osfhnd
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 _set_osfhnd(uint arg1,HANDLE arg2)

{
  undefined4 *dataCursor;
  int value;
  DWORD nStdHandle;
  
  if (arg1 < g_FileDescriptorCapacity) {
    value = (arg1 & 0x1f) * 0x24;
    if (*(int *)((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + value) == -1) {
      if (g_CrtFileHandleTable == 1) {
        if (arg1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (arg1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (arg1 != 2) goto LAB_004b68ab;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,arg2);
      }
LAB_004b68ab:
      *(HANDLE *)((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + value) = arg2;
      return 0;
    }
  }
  dataCursor = (undefined4 *)_errno();
  *dataCursor = 9;
  dataCursor = (undefined4 *)__doserrno();
  *dataCursor = 0;
  return 0xffffffff;
}

