#include "tarzan_ghidra_types.hpp"

// Address: 0x004B181B
// Label: _read_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _read_lk(uint arg1,char *arg2,char *arg3)

{
  int *intCursor;
  byte *value3;
  char resultFlag;
  byte flagByte;
  BOOL value;
  DWORD apiResult;
  undefined4 *dataCursor;
  char *stringCursor;
  int value2;
  DWORD scratchBuffer;
  char *scratchBuffer3;
  char scratchBuffer2;
  
  scratchBuffer3 = (char *)0x0;
  if (arg3 != (char *)0x0) {
    intCursor = &g_FileDescriptorBlockTable + ((int)arg1 >> 5);
    value2 = (arg1 & 0x1f) * 0x24;
    flagByte = *(byte *)((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + value2 + 4);
    if ((flagByte & 2) == 0) {
      stringCursor = arg2;
      if (((flagByte & 0x48) != 0) &&
         (resultFlag = *(char *)((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + value2 + 5),
         resultFlag != '\n')) {
        arg3 = (char *)((int)arg3 - 1);
        *arg2 = resultFlag;
        stringCursor = arg2 + 1;
        scratchBuffer3 = (char *)0x1;
        *(undefined1 *)(*intCursor + 5 + value2) = 10;
      }
      value = ReadFile(*(HANDLE *)(*intCursor + value2),stringCursor,(DWORD)arg3,&scratchBuffer,
                       (LPOVERLAPPED)0x0);
      if (value == 0) {
        apiResult = GetLastError();
        if (apiResult == 5) {
          dataCursor = (undefined4 *)_errno();
          *dataCursor = 9;
          dataCursor = (undefined4 *)__doserrno();
          *dataCursor = 5;
        }
        else {
          if (apiResult == 0x6d) {
            return 0;
          }
          _dosmaperr(apiResult);
        }
        return -1;
      }
      flagByte = *(byte *)(*intCursor + 4 + value2);
      if ((flagByte & 0x80) == 0) {
        return (int)scratchBuffer3 + scratchBuffer;
      }
      if ((scratchBuffer == 0) || (*arg2 != '\n')) {
        flagByte = flagByte & 0xfb;
      }
      else {
        flagByte = flagByte | 4;
      }
      *(byte *)(*intCursor + 4 + value2) = flagByte;
      arg3 = arg2;
      scratchBuffer3 = arg2 + (int)scratchBuffer3 + scratchBuffer;
      stringCursor = arg2;
      if (arg2 < scratchBuffer3) {
        do {
          resultFlag = *arg3;
          if (resultFlag == '\x1a') {
            value3 = (byte *)(*intCursor + 4 + value2);
            flagByte = *value3;
            if ((flagByte & 0x40) == 0) {
              *value3 = flagByte | 2;
            }
            break;
          }
          if (resultFlag == '\r') {
            if (arg3 < scratchBuffer3 + -1) {
              if (arg3[1] == '\n') {
                arg3 = arg3 + 2;
                goto LAB_004b19a6;
              }
              *stringCursor = '\r';
              stringCursor = stringCursor + 1;
              arg3 = arg3 + 1;
            }
            else {
              arg3 = arg3 + 1;
              value = ReadFile(*(HANDLE *)(*intCursor + value2),&scratchBuffer2,1,&scratchBuffer,(LPOVERLAPPED)0x0);
              if (((value == 0) && (apiResult = GetLastError(), apiResult != 0)) || (scratchBuffer == 0)) {
LAB_004b19c0:
                *stringCursor = '\r';
LAB_004b19c3:
                stringCursor = stringCursor + 1;
              }
              else if ((*(byte *)(*intCursor + 4 + value2) & 0x48) == 0) {
                if ((stringCursor == arg2) && (scratchBuffer2 == '\n')) {
LAB_004b19a6:
                  *stringCursor = '\n';
                  goto LAB_004b19c3;
                }
                _lseek_lk(arg1,0xffffffff,1);
                if (scratchBuffer2 != '\n') goto LAB_004b19c0;
              }
              else {
                if (scratchBuffer2 == '\n') goto LAB_004b19a6;
                *stringCursor = '\r';
                stringCursor = stringCursor + 1;
                *(char *)(*intCursor + 5 + value2) = scratchBuffer2;
              }
            }
          }
          else {
            *stringCursor = resultFlag;
            stringCursor = stringCursor + 1;
            arg3 = arg3 + 1;
          }
        } while (arg3 < scratchBuffer3);
      }
      return (int)stringCursor - (int)arg2;
    }
  }
  return 0;
}

