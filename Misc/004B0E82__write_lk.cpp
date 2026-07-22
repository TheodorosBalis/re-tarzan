#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0E82
// Label: _write_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _write_lk(DWORD arg1,char *arg2,uint arg3)

{
  int *intCursor;
  char *stringCursor;
  char resultFlag;
  int value2;
  char *stringCursor2;
  BOOL value;
  undefined4 *dataCursor;
  char localState3 [1028];
  int localState2;
  DWORD localState;
  DWORD localState5;
  char *localState4;
  
  localState5 = 0;
  localState2 = 0;
  if (arg3 == 0) {
LAB_004b0e9b:
    value2 = 0;
  }
  else {
    intCursor = &g_FileDescriptorBlockTable + ((int)arg1 >> 5);
    value2 = (arg1 & 0x1f) * 0x24;
    if ((*(byte *)(*intCursor + 4 + value2) & 0x20) != 0) {
      _lseek_lk(arg1,0,2);
    }
    if ((*(byte *)((undefined4 *)(*intCursor + value2) + 1) & 0x80) == 0) {
      value = WriteFile(*(HANDLE *)(*intCursor + value2),arg2,arg3,&localState,(LPOVERLAPPED)0x0);
      if (value == 0) {
        arg1 = GetLastError();
      }
      else {
        localState5 = localState;
        arg1 = 0;
      }
LAB_004b0f6a:
      if (localState5 != 0) {
        return localState5 - localState2;
      }
      if (arg1 == 0) goto LAB_004b0fdc;
      if (arg1 == 5) {
        dataCursor = (undefined4 *)_errno();
        *dataCursor = 9;
        dataCursor = (undefined4 *)__doserrno();
        *dataCursor = 5;
      }
      else {
        _dosmaperr(arg1);
      }
    }
    else {
      localState4 = arg2;
      arg1 = 0;
      if (arg3 != 0) {
        do {
          stringCursor2 = localState3;
          do {
            if (arg3 <= (uint)((int)localState4 - (int)arg2)) break;
            stringCursor = localState4 + 1;
            resultFlag = *localState4;
            localState4 = stringCursor;
            if (resultFlag == '\n') {
              localState2 = localState2 + 1;
              *stringCursor2 = '\r';
              stringCursor2 = stringCursor2 + 1;
            }
            *stringCursor2 = resultFlag;
            stringCursor2 = stringCursor2 + 1;
          } while ((int)stringCursor2 - (int)localState3 < 0x400);
          value = WriteFile(*(HANDLE *)(*intCursor + value2),localState3,(int)stringCursor2 - (int)localState3,
                            &localState,(LPOVERLAPPED)0x0);
          if (value == 0) {
            arg1 = GetLastError();
            goto LAB_004b0f6a;
          }
          localState5 = localState5 + localState;
          if (((int)localState < (int)stringCursor2 - (int)localState3) ||
             (arg3 <= (uint)((int)localState4 - (int)arg2))) goto LAB_004b0f6a;
        } while( true );
      }
LAB_004b0fdc:
      if (((*(byte *)(*intCursor + 4 + value2) & 0x40) != 0) && (*arg2 == '\x1a')) goto LAB_004b0e9b;
      dataCursor = (undefined4 *)_errno();
      *dataCursor = 0x1c;
      dataCursor = (undefined4 *)__doserrno();
      *dataCursor = 0;
    }
    value2 = -1;
  }
  return value2;
}

