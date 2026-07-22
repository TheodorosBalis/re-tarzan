#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0028
// Label: _access
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 _access(LPCSTR arg1,byte arg2)

{
  DWORD apiResult;
  undefined4 *dataCursor;
  
  apiResult = GetFileAttributesA(arg1);
  if (apiResult == 0xffffffff) {
    apiResult = GetLastError();
    _dosmaperr(apiResult);
  }
  else {
    if (((apiResult & 1) == 0) || ((arg2 & 2) == 0)) {
      return 0;
    }
    dataCursor = (undefined4 *)_errno();
    *dataCursor = 0xd;
    dataCursor = (undefined4 *)__doserrno();
    *dataCursor = 5;
  }
  return 0xffffffff;
}

