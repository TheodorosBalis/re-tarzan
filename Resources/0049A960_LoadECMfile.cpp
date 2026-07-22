#include "tarzan_ghidra_types.hpp"

// Address: 0x0049A960
// Label: LoadECMfile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined * LoadECMfile(char *arg1)

{
  char resultFlag;
  DWORD apiResult;
  int value;
  int value2;
  uint value3;
  uint value4;
  uint value5;
  char *stringCursor2;
  undefined4 *dataCursor;
  char *stringCursor;
  
  if (g_EcmLoadScratch_Field00D4 != '\0') {
    dataCursor = (undefined4 *)&g_EcmLoadScratch_Field20C4B0;
    for (value2 = 6; value2 != 0; value2 = value2 + -1) {
      *dataCursor = 0;
      dataCursor = dataCursor + 1;
    }
    g_EcmLoadScratch_Field00D4 = '\0';
    *(undefined2 *)dataCursor = 0;
    apiResult = GetLogicalDrives();
    if ((apiResult & 1) != 0) {
      value2 = (int)g_EcmLoadStateByte;
      g_EcmLoadStateByte = g_EcmLoadStateByte + '\x01';
      (&g_EcmLoadScratch_Field20C4B0)[value2] = 0x2e;
    }
  }
  value3 = 0xffffffff;
  stringCursor2 = &DAT_00515c40;
  do {
    if (value3 == 0) break;
    value3 = value3 - 1;
    resultFlag = *stringCursor2;
    stringCursor2 = stringCursor2 + 1;
  } while (resultFlag != '\0');
  value4 = 0xffffffff;
  do {
    stringCursor2 = arg1;
    if (value4 == 0) break;
    value4 = value4 - 1;
    stringCursor2 = arg1 + 1;
    resultFlag = *arg1;
    arg1 = stringCursor2;
  } while (resultFlag != '\0');
  value4 = ~value4;
  stringCursor2 = stringCursor2 + -value4;
  stringCursor = &DAT_00515ad7 + ~value3;
  for (value5 = value4 >> 2; value5 != 0; value5 = value5 - 1) {
    *(undefined4 *)stringCursor = *(undefined4 *)stringCursor2;
    stringCursor2 = stringCursor2 + 4;
    stringCursor = stringCursor + 4;
  }
  g_EcmLoadScratch_Field20C8F0 = 0x2e;
  for (value4 = value4 & 3; value4 != 0; value4 = value4 - 1) {
    *stringCursor = *stringCursor2;
    stringCursor2 = stringCursor2 + 1;
    stringCursor = stringCursor + 1;
  }
  g_EcmLoadScratch_Field00D8 = 0x2e;
  value2 = _access(&g_EcmLoadScratch_Field00D8,0);
  if (value2 != 0) {
    value2 = 0;
    if ('\0' < g_EcmLoadStateByte) {
      do {
        g_EcmLoadScratch_Field00D8 = (&g_EcmLoadScratch_Field20C4B0)[value2];
        g_EcmLoadScratch_Field20C8F0 = g_EcmLoadScratch_Field00D8;
        value = _access(&g_EcmLoadScratch_Field00D8,0);
        if (value == 0) goto LAB_0049aa33;
        value2 = value2 + 1;
      } while (value2 < g_EcmLoadStateByte);
    }
    return (undefined *)0x0;
  }
LAB_0049aa33:
  return &g_EcmLoadScratch_Field00D8;
}

