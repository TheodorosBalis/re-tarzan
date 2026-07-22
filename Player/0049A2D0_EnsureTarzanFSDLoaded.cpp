#include "tarzan_ghidra_types.hpp"

// Address: 0x0049A2D0
// Label: EnsureTarzanFSDLoaded
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void EnsureTarzanFSDLoaded(void)

{
  int *intCursor;
  char resultFlag;
  bool flagByte;
  uint *dataCursor2;
  DWORD apiResult;
  int value2;
  uint value4;
  undefined4 *dataCursor3;
  int value3;
  uint *dataCursor;
  int value;
  char *stringCursor;
  CHAR scratchBuffer [1024];
  
  if (g_TarzanFsdInitAttempted == 0) {
    dataCursor3 = &g_TarzanFsdEntryTable;
    for (value2 = 0x1800; value2 != 0; value2 = value2 + -1) {
      *dataCursor3 = 0;
      dataCursor3 = dataCursor3 + 1;
    }
    g_IsTarzanFsdArchiveActive = 0;
    dataCursor3 = &g_TarzanFsdHandleOffsets;
    for (value2 = 0x800; value2 != 0; value2 = value2 + -1) {
      *dataCursor3 = 0xffffffff;
      dataCursor3 = dataCursor3 + 1;
    }
    g_TarzanFsdArchiveHandle = 0;
    g_TarzanFsdEntryCount = 0;
    apiResult = GetModuleFileNameA((HMODULE)0x0,scratchBuffer,0x400);
    if (apiResult == 0) {
      InternalError(s_FSYS_Init_1__00515bf8);
    }
    value4 = 0xffffffff;
    stringCursor = scratchBuffer;
    do {
      if (value4 == 0) break;
      value4 = value4 - 1;
      resultFlag = *stringCursor;
      stringCursor = stringCursor + 1;
    } while (resultFlag != '\0');
    scratchBuffer[~value4 - 4] = 'f';
    value4 = 0xffffffff;
    stringCursor = scratchBuffer;
    do {
      if (value4 == 0) break;
      value4 = value4 - 1;
      resultFlag = *stringCursor;
      stringCursor = stringCursor + 1;
    } while (resultFlag != '\0');
    scratchBuffer[~value4 - 3] = 's';
    value4 = 0xffffffff;
    stringCursor = scratchBuffer;
    do {
      if (value4 == 0) break;
      value4 = value4 - 1;
      resultFlag = *stringCursor;
      stringCursor = stringCursor + 1;
    } while (resultFlag != '\0');
    scratchBuffer[~value4 - 2] = 'd';
    g_TarzanFsdArchiveHandle = fopen(scratchBuffer,&s_FileModeReadBinary);
    if (g_TarzanFsdArchiveHandle != 0) {
      g_IsTarzanFsdArchiveActive = 1;
      value2 = fread(&g_TarzanFsdEntryTable,0x6000,1,g_TarzanFsdArchiveHandle);
      if (value2 != 1) {
        InternalError(s_FSYS_Init_2__00515be8);
      }
      value2 = 0;
      g_TarzanFsdEntryCount = 0;
      if (g_TarzanFsdEntryTable != 0) {
        dataCursor3 = &g_TarzanFsdEntryTable;
        do {
          g_TarzanFsdEntryCount = value2;
          if (0x71feaf < (int)dataCursor3) break;
          intCursor = dataCursor3 + 3;
          dataCursor3 = dataCursor3 + 3;
          value2 = value2 + 1;
          g_TarzanFsdEntryCount = value2;
        } while (*intCursor != 0);
      }
      if (0 < g_TarzanFsdEntryCount) {
        dataCursor = (uint *)&g_TarzanFsdEntryTable;
        value2 = g_TarzanFsdEntryCount;
        value3 = 1;
        do {
          value = value3;
          dataCursor2 = dataCursor;
          if (value3 < value2) {
            do {
              if (dataCursor2[3] <= *dataCursor) {
                InternalError(s_FSYS_Init_3__00515bd8);
                value2 = g_TarzanFsdEntryCount;
              }
              value = value + 1;
              dataCursor2 = dataCursor2 + 3;
            } while (value < value2);
          }
          dataCursor = dataCursor + 3;
          flagByte = value3 < value2;
          value3 = value3 + 1;
        } while (flagByte);
      }
    }
    g_TarzanFsdInitAttempted = 1;
  }
  return;
}

