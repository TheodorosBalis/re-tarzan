#include "tarzan_ghidra_types.hpp"

// Address: 0x004948E0
// Label: BuildTarzanCFGPath
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined1 * BuildTarzanCFGPath(void)

{
  char resultFlag;
  DWORD apiResult;
  uint value;
  char *stringCursor;
  
  apiResult = GetModuleFileNameA((HMODULE)0x0,&g_TarzanCFGPathBuffer,0x400);
  if (apiResult == 0) {
    return (undefined1 *)0x0;
  }
  value = 0xffffffff;
  stringCursor = &g_TarzanCFGPathBuffer;
  do {
    if (value == 0) break;
    value = value - 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor + 1;
  } while (resultFlag != '\0');
  (&g_TarzanCFGPathExtCWriteBase)[~value] = 99;
  value = 0xffffffff;
  stringCursor = &g_TarzanCFGPathBuffer;
  do {
    if (value == 0) break;
    value = value - 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor + 1;
  } while (resultFlag != '\0');
  (&g_TarzanCFGPathExtFWriteBase)[~value] = 0x66;
  value = 0xffffffff;
  stringCursor = &g_TarzanCFGPathBuffer;
  do {
    if (value == 0) break;
    value = value - 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor + 1;
  } while (resultFlag != '\0');
  (&g_TarzanCFGPathExtGWriteBase)[~value] = 0x67;
  return &g_TarzanCFGPathBuffer;
}

