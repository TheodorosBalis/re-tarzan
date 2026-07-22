#include "tarzan_ghidra_types.hpp"

// Address: 0x004B6A7D
// Label: _sopen
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint _sopen(LPCSTR arg1,uint arg2,uint arg3,uint arg4)

{
  byte *value3;
  uint value4;
  uint value5;
  undefined4 *dataCursor;
  HANDLE hFile;
  DWORD apiResult;
  int *intCursor;
  int value;
  int value2;
  bool flagByte;
  _SECURITY_ATTRIBUTES localState3;
  DWORD localState2;
  DWORD localState;
  DWORD localState5;
  byte localState4;
  
  flagByte = (arg2 & 0x80) == 0;
  localState3.nLength = 0xc;
  localState3.lpSecurityDescriptor = (LPVOID)0x0;
  if (flagByte) {
    localState4 = 0;
  }
  else {
    localState4 = 0x10;
  }
  localState3.bInheritHandle = (BOOL)flagByte;
  if (((arg2 & 0x8000) == 0) &&
     (((arg2 & 0x4000) != 0 || (g_CrtSopenShareModeState != 0x8000)))) {
    localState4 = localState4 | 0x80;
  }
  value4 = arg2 & 3;
  if (value4 == 0) {
    localState = 0x80000000;
  }
  else if (value4 == 1) {
    localState = 0x40000000;
  }
  else {
    if (value4 != 2) goto LAB_004b6b81;
    localState = 0xc0000000;
  }
  if (arg3 == 0x10) {
    localState2 = 0;
  }
  else if (arg3 == 0x20) {
    localState2 = 1;
  }
  else if (arg3 == 0x30) {
    localState2 = 2;
  }
  else {
    if (arg3 != 0x40) goto LAB_004b6b81;
    localState2 = 3;
  }
  value4 = arg2 & 0x700;
  if (value4 < 0x401) {
    if ((value4 == 0x400) || (value4 == 0)) {
      localState5 = 3;
    }
    else if (value4 == 0x100) {
      localState5 = 4;
    }
    else {
      if (value4 == 0x200) goto LAB_004b6b9b;
      if (value4 != 0x300) goto LAB_004b6b81;
      localState5 = 2;
    }
  }
  else {
    if (value4 != 0x500) {
      if (value4 == 0x600) {
LAB_004b6b9b:
        localState5 = 5;
        goto LAB_004b6bab;
      }
      if (value4 != 0x700) {
LAB_004b6b81:
        dataCursor = (undefined4 *)_errno();
        *dataCursor = 0x16;
        dataCursor = (undefined4 *)__doserrno();
        *dataCursor = 0;
        return 0xffffffff;
      }
    }
    localState5 = 1;
  }
LAB_004b6bab:
  value4 = 0x80;
  if (((arg2 & 0x100) != 0) && ((~g_CrtSharedOpenFileMode & arg4 & 0x80) == 0)) {
    value4 = 1;
  }
  if ((arg2 & 0x40) != 0) {
    value4 = value4 | 0x4000000;
    localState = CONCAT13(*( undefined1 *)((int)&localState + 3),0x10000);
  }
  if ((arg2 & 0x1000) != 0) {
    value4 = value4 | 0x100;
  }
  if ((arg2 & 0x20) == 0) {
    if ((arg2 & 0x10) != 0) {
      value4 = value4 | 0x10000000;
    }
  }
  else {
    value4 = value4 | 0x8000000;
  }
  value5 = _alloc_osfhnd();
  if (value5 == 0xffffffff) {
    dataCursor = (undefined4 *)_errno();
    *dataCursor = 0x18;
    dataCursor = (undefined4 *)__doserrno();
    *dataCursor = 0;
    return 0xffffffff;
  }
  hFile = CreateFileA(arg1,localState,localState2,&localState3,localState5,value4,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    apiResult = GetFileType(hFile);
    if (apiResult != 0) {
      if (apiResult == 2) {
        localState4 = localState4 | 0x40;
      }
      else if (apiResult == 3) {
        localState4 = localState4 | 8;
      }
      _set_osfhnd(value5,hFile);
      value2 = (value5 & 0x1f) * 0x24;
      *( undefined1 *)((int)&arg1 + 3) = localState4 & 0x48;
      *(byte *)((&g_FileDescriptorBlockTable)[(int)value5 >> 5] + 4 + value2) = localState4 | 1;
      if ((((localState4 & 0x48) == 0) && ((localState4 & 0x80) != 0)) && ((arg2 & 2) != 0)) {
        localState2 = _lseek_lk(value5,0xffffffff,2);
        if (localState2 == 0xffffffff) {
          intCursor = (int *)__doserrno();
          if (*intCursor == 0x83) goto LAB_004b6d25;
        }
        else {
          arg3 = arg3 & 0xffffff;
          value = _read_lk(value5,(int)&arg3 + 3,1);
          if ((((value != 0) || (*( undefined1 *)((int)&arg3 + 3) != '\x1a')) ||
              (value = _chsize_lk(value5,localState2), value != -1)) &&
             (value = _lseek_lk(value5,0,0), value != -1)) goto LAB_004b6d25;
        }
        _close(value5);
        value4 = 0xffffffff;
      }
      else {
LAB_004b6d25:
        value4 = value5;
        if ((*( undefined1 *)((int)&arg1 + 3) == 0) && ((arg2 & 8) != 0)) {
          value3 = (byte *)((&g_FileDescriptorBlockTable)[(int)value5 >> 5] + 4 + value2);
          *value3 = *value3 | 0x20;
        }
      }
      goto LAB_004b6d3e;
    }
    CloseHandle(hFile);
  }
  apiResult = GetLastError();
  _dosmaperr(apiResult);
  value4 = 0xffffffff;
LAB_004b6d3e:
  _unlock_fhandle(value5);
  return value4;
}

