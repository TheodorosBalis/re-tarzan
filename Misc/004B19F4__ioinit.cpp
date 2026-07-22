#include "tarzan_ghidra_types.hpp"

// Address: 0x004B19F4
// Label: _ioinit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _ioinit(void)

{
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  undefined4 *dataCursor3;
  DWORD apiResult;
  HANDLE hFile;
  UINT *value5;
  int value3;
  uint value4;
  UINT value;
  UINT value2;
  _STARTUPINFOA localState;
  byte *localState2;
  
  dataCursor2 = malloc(0x480);
  if (dataCursor2 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  g_FileDescriptorCapacity = 0x20;
  g_FileDescriptorBlockTable = dataCursor2;
  for (; dataCursor2 < g_FileDescriptorBlockTable + 0x120; dataCursor2 = dataCursor2 + 9) {
    *(undefined1 *)(dataCursor2 + 1) = 0;
    *dataCursor2 = 0xffffffff;
    dataCursor2[2] = 0;
    *(undefined1 *)((int)dataCursor2 + 5) = 10;
  }
  GetStartupInfoA(&localState);
  if ((localState.cbReserved2 != 0) && ((UINT *)localState.lpReserved2 != (UINT *)0x0)) {
    value = *(UINT *)localState.lpReserved2;
    value5 = (UINT *)((int)localState.lpReserved2 + 4);
    localState2 = (byte *)((int)value5 + value);
    if (0x7ff < (int)value) {
      value = 0x800;
    }
    value2 = value;
    if ((int)g_FileDescriptorCapacity < (int)value) {
      dataCursor2 = &DAT_00c47264;
      do {
        dataCursor3 = malloc(0x480);
        value2 = g_FileDescriptorCapacity;
        if (dataCursor3 == (undefined4 *)0x0) break;
        g_FileDescriptorCapacity = g_FileDescriptorCapacity + 0x20;
        *dataCursor2 = dataCursor3;
        dataCursor = dataCursor3;
        for (; dataCursor3 < dataCursor + 0x120; dataCursor3 = dataCursor3 + 9) {
          *(undefined1 *)(dataCursor3 + 1) = 0;
          *dataCursor3 = 0xffffffff;
          dataCursor3[2] = 0;
          *(undefined1 *)((int)dataCursor3 + 5) = 10;
          dataCursor = (undefined4 *)*dataCursor2;
        }
        dataCursor2 = dataCursor2 + 1;
        value2 = value;
      } while ((int)g_FileDescriptorCapacity < (int)value);
    }
    value4 = 0;
    if (0 < (int)value2) {
      do {
        if (((*(HANDLE *)localState2 != (HANDLE)0xffffffff) && ((*value5 & 1) != 0)) &&
           (((*value5 & 8) != 0 || (apiResult = GetFileType(*(HANDLE *)localState2), apiResult != 0)))) {
          dataCursor2 = (undefined4 *)
                   ((int)(&g_FileDescriptorBlockTable)[(int)value4 >> 5] + (value4 & 0x1f) * 0x24);
          *dataCursor2 = *(undefined4 *)localState2;
          *(byte *)(dataCursor2 + 1) = (byte)*value5;
        }
        localState2 = localState2 + 4;
        value4 = value4 + 1;
        value5 = (UINT *)((int)value5 + 1);
      } while ((int)value4 < (int)value2);
    }
  }
  value3 = 0;
  do {
    dataCursor2 = g_FileDescriptorBlockTable + value3 * 9;
    if (g_FileDescriptorBlockTable[value3 * 9] == -1) {
      *(undefined1 *)(dataCursor2 + 1) = 0x81;
      if (value3 == 0) {
        apiResult = 0xfffffff6;
      }
      else {
        apiResult = 0xfffffff5 - (value3 != 1);
      }
      hFile = GetStdHandle(apiResult);
      if ((hFile != (HANDLE)0xffffffff) && (apiResult = GetFileType(hFile), apiResult != 0)) {
        *dataCursor2 = hFile;
        if ((apiResult & 0xff) != 2) {
          if ((apiResult & 0xff) == 3) {
            *(byte *)(dataCursor2 + 1) = *(byte *)(dataCursor2 + 1) | 8;
          }
          goto LAB_004b1b99;
        }
      }
      *(byte *)(dataCursor2 + 1) = *(byte *)(dataCursor2 + 1) | 0x40;
    }
    else {
      *(byte *)(dataCursor2 + 1) = *(byte *)(dataCursor2 + 1) | 0x80;
    }
LAB_004b1b99:
    value3 = value3 + 1;
    if (2 < value3) {
      SetHandleCount(g_FileDescriptorCapacity);
      return;
    }
  } while( true );
}

