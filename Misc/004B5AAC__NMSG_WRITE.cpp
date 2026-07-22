#include "tarzan_ghidra_types.hpp"

// Address: 0x004B5AAC
// Label: _NMSG_WRITE
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _NMSG_WRITE(DWORD arg1)

{
  DWORD *value2;
  DWORD apiResult;
  size_t shortValue;
  HANDLE hFile;
  int value;
  char acStackY_1e3 [7];
  undefined1 *puStackY_1dc;
  char *pcStackY_1d8;
  undefined4 uStackY_1d4;
  undefined1 *puStackY_1d0;
  undefined4 uStackY_1cc;
  undefined1 *puStackY_1c8;
  undefined *puStackY_1c4;
  LPCVOID lpBuffer;
  LPDWORD lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  CHAR localState [260];
  undefined1 localState2 [160];
  
  value = 0;
  value2 = &g_CrtRuntimeErrorMessageId;
  do {
    if (arg1 == *value2) break;
    value2 = value2 + 2;
    value = value + 1;
  } while ((int)value2 < 0x51ba68);
  if (arg1 == (&g_CrtRuntimeErrorMessageId)[value * 2]) {
    if ((g_CrtRuntimeErrorOutputMode == 1) ||
       ((g_CrtRuntimeErrorOutputMode == 0 && (g_CrtFileHandleTable == 1)))) {
      lpNumberOfBytesWritten = &arg1;
      lpOverlapped = (LPOVERLAPPED)0x0;
      shortValue = strlen(*(char **)(&g_CrtRuntimeErrorMessageText + value * 8));
      lpBuffer = *(LPCVOID *)(&g_CrtRuntimeErrorMessageText + value * 8);
      puStackY_1c4 = (undefined *)0x4b5bf5;
      hFile = GetStdHandle(0xfffffff4);
      puStackY_1c4 = (undefined *)0x4b5bfc;
      WriteFile(hFile,lpBuffer,shortValue,lpNumberOfBytesWritten,lpOverlapped);
    }
    else if (arg1 != 0xfc) {
      apiResult = GetModuleFileNameA((HMODULE)0x0,localState,0x104);
      if (apiResult == 0) {
        strcpy();
      }
      shortValue = strlen(localState);
      if (0x3c < shortValue + 1) {
        shortValue = strlen(localState);
        puStackY_1c4 = (undefined *)0x4b5b76;
        strncpy(acStackY_1e3 + shortValue,"...",3);
      }
      strcpy();
      puStackY_1c4 = (undefined *)0x4b5b97;
      strcat();
      puStackY_1c8 = localState2;
      puStackY_1c4 = &DAT_004ba8c4;
      uStackY_1cc = 0x4b5ba8;
      strcat();
      uStackY_1cc = *(undefined4 *)(&g_CrtRuntimeErrorMessageText + value * 8);
      puStackY_1d0 = localState2;
      uStackY_1d4 = 0x4b5bba;
      strcat();
      uStackY_1d4 = 0x12010;
      puStackY_1dc = localState2;
      pcStackY_1d8 = "Microsoft Visual C++ Runtime Library";
      acStackY_1e3[3] = -0x30;
      acStackY_1e3[4] = '[';
      acStackY_1e3[5] = 'K';
      acStackY_1e3[6] = '\0';
      __crtMessageBoxA();
    }
  }
  return;
}

