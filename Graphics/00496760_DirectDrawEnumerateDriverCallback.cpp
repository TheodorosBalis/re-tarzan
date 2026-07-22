#include "tarzan_ghidra_types.hpp"

// Address: 0x00496760
// Label: DirectDrawEnumerateDriverCallback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 DirectDrawEnumerateDriverCallback(int driverGuid,char *driverDescription)

{
  char resultFlag;
  int value;
  uint value2;
  uint value3;
  char *stringCursor;
  uint driverCapsFlags;
  char *stringCursor2;
  undefined4 *dataCursor;
  uint scratchRect;
  char upperDriverDescription [1024];
  
  if (driverGuid == 0) {
    return 1;
  }
  if (driverDescription != (char *)0x0) {
    value2 = 0xffffffff;
    do {
      stringCursor = driverDescription;
      if (value2 == 0) break;
      value2 = value2 - 1;
      stringCursor = driverDescription + 1;
      resultFlag = *driverDescription;
      driverDescription = stringCursor;
    } while (resultFlag != '\0');
    value2 = ~value2;
    stringCursor = stringCursor + -value2;
    stringCursor2 = upperDriverDescription;
    for (value3 = value2 >> 2; value3 != 0; value3 = value3 - 1) {
      *(undefined4 *)stringCursor2 = *(undefined4 *)stringCursor;
      stringCursor = stringCursor + 4;
      stringCursor2 = stringCursor2 + 4;
    }
    for (value2 = value2 & 3; value2 != 0; value2 = value2 - 1) {
      *stringCursor2 = *stringCursor;
      stringCursor = stringCursor + 1;
      stringCursor2 = stringCursor2 + 1;
    }
    _strupr(upperDriverDescription);
    value = strstr(upperDriverDescription,&DAT_00515830);
    if ((value != 0) || (value = strstr(upperDriverDescription), value != 0)) {
      if (g_DirectDrawEnumeratedDriverGuid != 0) {
        return 1;
      }
      g_DirectDrawSelectedDriverGuid = 1;
    }
  }
  value = (*g_DirectDrawCreateProc)(driverGuid,&g_DirectDraw);
  if (value != 0) {
    return 1;
  }
  dataCursor = (undefined4 *)&stack0xfffffa88;
  for (value = 0x5b; value != 0; value = value + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  if ((g_DirectDraw == (int *)0x0) ||
     (value = (**(code **)(*g_DirectDraw + 0x2c))(g_DirectDraw,&stack0xfffffa88,0), value == 0)) {
    if (((driverCapsFlags & 1) != 0) && (0x32bfff < scratchRect)) {
      return 0;
    }
    if (g_DirectDraw != (int *)0x0) {
      (**(code **)(*g_DirectDraw + 8))(g_DirectDraw);
    }
  }
  else {
    (**(code **)(*g_DirectDraw + 8))(g_DirectDraw);
  }
  g_DirectDraw = (int *)0x0;
  return 1;
}

