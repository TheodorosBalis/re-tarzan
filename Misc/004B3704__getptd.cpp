#include "tarzan_ghidra_types.hpp"

// Address: 0x004B3704
// Label: _getptd
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

DWORD * _getptd(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL value;
  DWORD apiResult;
  
  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(TlsIndex);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)calloc(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      value = TlsSetValue(TlsIndex,lpTlsValue);
      if (value != 0) {
        _initptd(lpTlsValue);
        apiResult = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = apiResult;
        goto LAB_004b375f;
      }
    }
    __amsg_exit(0x10);
  }
LAB_004b375f:
  SetLastError(dwErrCode);
  return lpTlsValue;
}

