#include "tarzan_ghidra_types.hpp"

// Address: 0x004B6DA5
// Label: _wctomb_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _wctomb_lk(LPSTR arg1,WCHAR arg2)

{
  LPSTR lpMultiByteStr;
  int value;
  undefined4 *dataCursor;
  
  lpMultiByteStr = arg1;
  if (arg1 == (LPSTR)0x0) {
    return 0;
  }
  if (g_CrtMultibyteLocaleActive == 0) {
    if ((ushort)arg2 < 0x100) {
      *arg1 = (CHAR)arg2;
      return 1;
    }
  }
  else {
    arg1 = (LPSTR)0x0;
    value = WideCharToMultiByte(g_CrtLocaleCodePage,0x220,&arg2,1,lpMultiByteStr,
                                g_CrtLocaleEnabled,(LPCSTR)0x0,(LPBOOL)&arg1);
    if ((value != 0) && (arg1 == (LPSTR)0x0)) {
      return value;
    }
  }
  dataCursor = (undefined4 *)_errno();
  *dataCursor = 0x2a;
  return -1;
}

