#include "tarzan_ghidra_types.hpp"

// Address: 0x004B369D
// Label: _mtinit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 _mtinit(void)

{
  DWORD *lpTlsValue;
  BOOL value;
  DWORD apiResult;
  
  _mtinitlocks();
  TlsIndex = TlsAlloc();
  if (TlsIndex != 0xffffffff) {
    lpTlsValue = (DWORD *)calloc(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      value = TlsSetValue(TlsIndex,lpTlsValue);
      if (value != 0) {
        _initptd(lpTlsValue);
        apiResult = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = apiResult;
        return 1;
      }
    }
  }
  return 0;
}

