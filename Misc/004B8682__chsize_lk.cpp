#include "tarzan_ghidra_types.hpp"

// Address: 0x004B8682
// Label: _chsize_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _chsize_lk(undefined4 arg1,int arg2)

{
  int value2;
  int *intCursor;
  undefined4 *dataCursor;
  HANDLE hFile;
  BOOL value;
  DWORD apiResult;
  DWORD *value4;
  int value3;
  undefined1 localState [4064];
  undefined4 uStackY_28;
  undefined4 uStackY_24;
  undefined4 uStackY_20;
  
  SafeCheckStackPtr();
  value3 = 0;
  value2 = _lseek_lk();
  if ((value2 == -1) || (value2 = _lseek_lk(), value2 == -1)) {
    value3 = -1;
  }
  else {
    arg2 = arg2 - value2;
    if (arg2 < 1) {
      if (arg2 < 0) {
        uStackY_20 = 0x4b8753;
        _lseek_lk();
        uStackY_20 = arg1;
        uStackY_24 = 0x4b875b;
        hFile = (HANDLE)_get_osfhandle();
        value = SetEndOfFile(hFile);
        value3 = (value != 0) - 1;
        if (value3 == -1) {
          dataCursor = (undefined4 *)_errno();
          *dataCursor = 0xd;
          apiResult = GetLastError();
          value4 = (DWORD *)__doserrno();
          *value4 = apiResult;
        }
      }
    }
    else {
      uStackY_20 = 0x4b86e2;
      memset(localState,0,0x1000);
      uStackY_20 = 0x8000;
      uStackY_24 = arg1;
      uStackY_28 = 0x4b86ef;
      _setmode_lk();
      do {
        uStackY_20 = 0x4b870d;
        value2 = _write_lk();
        if (value2 == -1) {
          intCursor = (int *)__doserrno();
          if (*intCursor == 5) {
            dataCursor = (undefined4 *)_errno();
            *dataCursor = 0xd;
          }
          value3 = -1;
          break;
        }
        arg2 = arg2 - value2;
      } while (0 < arg2);
      _setmode_lk();
    }
    uStackY_20 = 0x4b8799;
    _lseek_lk();
  }
  return value3;
}

