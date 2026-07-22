#include "tarzan_ghidra_types.hpp"

// Address: 0x004B1667
// Label: _lseek_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

DWORD _lseek_lk(uint arg1,LONG arg2,DWORD arg3)

{
  byte *value;
  HANDLE hFile;
  undefined4 *dataCursor;
  DWORD apiResult;
  DWORD apiResult2;
  
  hFile = (HANDLE)_get_osfhandle(arg1);
  if (hFile == (HANDLE)0xffffffff) {
    dataCursor = (undefined4 *)_errno();
    *dataCursor = 9;
  }
  else {
    apiResult = SetFilePointer(hFile,arg2,(PLONG)0x0,arg3);
    if (apiResult == 0xffffffff) {
      apiResult2 = GetLastError();
    }
    else {
      apiResult2 = 0;
    }
    if (apiResult2 == 0) {
      value = (byte *)((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + 4 +
                       (arg1 & 0x1f) * 0x24);
      *value = *value & 0xfd;
      return apiResult;
    }
    _dosmaperr(apiResult2);
  }
  return 0xffffffff;
}

