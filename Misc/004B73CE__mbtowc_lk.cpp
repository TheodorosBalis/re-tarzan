#include "tarzan_ghidra_types.hpp"

// Address: 0x004B73CE
// Label: _mbtowc_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint _mbtowc_lk(LPWSTR arg1,byte *arg2,uint arg3)

{
  byte flagByte;
  int value;
  undefined4 *dataCursor;
  
  if ((arg2 != (byte *)0x0) && (arg3 != 0)) {
    flagByte = *arg2;
    if (flagByte != 0) {
      if (g_CrtMultibyteLocaleActive == 0) {
        if (arg1 != (LPWSTR)0x0) {
          *arg1 = (ushort)flagByte;
        }
        return 1;
      }
      if ((g_CrtCtypeTable[(uint)flagByte * 2 + 1] & 0x80) == 0) {
        value = MultiByteToWideChar(g_CrtLocaleCodePage,9,(LPCSTR)arg2,1,arg1,
                                    (uint)(arg1 != (LPWSTR)0x0));
        if (value != 0) {
          return 1;
        }
      }
      else {
        if (1 < (int)g_CrtLocaleEnabled) {
          if ((int)arg3 < (int)g_CrtLocaleEnabled) goto LAB_004b7460;
          value = MultiByteToWideChar(g_CrtLocaleCodePage,9,(LPCSTR)arg2,g_CrtLocaleEnabled,
                                      arg1,(uint)(arg1 != (LPWSTR)0x0));
          if (value != 0) {
            return g_CrtLocaleEnabled;
          }
        }
        if ((g_CrtLocaleEnabled <= arg3) && (arg2[1] != 0)) {
          return g_CrtLocaleEnabled;
        }
      }
LAB_004b7460:
      dataCursor = (undefined4 *)_errno();
      *dataCursor = 0x2a;
      return 0xffffffff;
    }
    if (arg1 != (LPWSTR)0x0) {
      *arg1 = L'\0';
    }
  }
  return 0;
}

