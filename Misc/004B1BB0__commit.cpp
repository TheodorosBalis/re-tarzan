#include "tarzan_ghidra_types.hpp"

// Address: 0x004B1BB0
// Label: _commit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 _commit(uint arg1)

{
  HANDLE hFile;
  BOOL value;
  DWORD apiResult;
  DWORD *value4;
  undefined4 *dataCursor;
  int value2;
  undefined4 value3;
  
  if (g_FileDescriptorCapacity <= arg1) {
LAB_004b1c31:
    dataCursor = (undefined4 *)_errno();
    *dataCursor = 9;
    return 0xffffffff;
  }
  value2 = (arg1 & 0x1f) * 0x24;
  if ((*(byte *)((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + 4 + value2) & 1) == 0)
  goto LAB_004b1c31;
  _lock_fhandle(arg1);
  if ((*(byte *)((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + 4 + value2) & 1) != 0) {
    hFile = (HANDLE)_get_osfhandle(arg1);
    value = FlushFileBuffers(hFile);
    if (value == 0) {
      apiResult = GetLastError();
    }
    else {
      apiResult = 0;
    }
    value3 = 0;
    if (apiResult == 0) goto LAB_004b1c26;
    value4 = (DWORD *)__doserrno();
    *value4 = apiResult;
  }
  dataCursor = (undefined4 *)_errno();
  *dataCursor = 9;
  value3 = 0xffffffff;
LAB_004b1c26:
  _unlock_fhandle(arg1);
  return value3;
}

