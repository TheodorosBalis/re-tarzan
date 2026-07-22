#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0C57
// Label: _close_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 _close_lk(uint arg1)

{
  int value2;
  int value3;
  HANDLE hObject;
  BOOL value;
  DWORD apiResult;
  undefined4 value4;
  
  value2 = _get_osfhandle(arg1);
  if (value2 != -1) {
    if ((arg1 == 1) || (arg1 == 2)) {
      value2 = _get_osfhandle(2);
      value3 = _get_osfhandle(1);
      if (value3 == value2) goto LAB_004b0ca5;
    }
    hObject = (HANDLE)_get_osfhandle(arg1);
    value = CloseHandle(hObject);
    if (value == 0) {
      apiResult = GetLastError();
      goto LAB_004b0ca7;
    }
  }
LAB_004b0ca5:
  apiResult = 0;
LAB_004b0ca7:
  _free_osfhnd(arg1);
  *(undefined1 *)((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + 4 + (arg1 & 0x1f) * 0x24) =
       0;
  if (apiResult == 0) {
    value4 = 0;
  }
  else {
    _dosmaperr(apiResult);
    value4 = 0xffffffff;
  }
  return value4;
}

