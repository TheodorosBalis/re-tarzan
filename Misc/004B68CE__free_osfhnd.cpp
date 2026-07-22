#include "tarzan_ghidra_types.hpp"

// Address: 0x004B68CE
// Label: _free_osfhnd
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 _free_osfhnd(uint arg1)

{
  int *intCursor;
  undefined4 *dataCursor;
  int value;
  DWORD nStdHandle;
  
  if (arg1 < g_FileDescriptorCapacity) {
    value = (arg1 & 0x1f) * 0x24;
    intCursor = (int *)((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + value);
    if (((*(byte *)(intCursor + 1) & 1) != 0) && (*intCursor != -1)) {
      if (g_CrtFileHandleTable == 1) {
        if (arg1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (arg1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (arg1 != 2) goto LAB_004b692a;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_004b692a:
      *(undefined4 *)((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + value) = 0xffffffff;
      return 0;
    }
  }
  dataCursor = (undefined4 *)_errno();
  *dataCursor = 9;
  dataCursor = (undefined4 *)__doserrno();
  *dataCursor = 0;
  return 0xffffffff;
}

