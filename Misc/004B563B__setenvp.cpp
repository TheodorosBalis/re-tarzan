#include "tarzan_ghidra_types.hpp"

// Address: 0x004B563B
// Label: _setenvp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _setenvp(void)

{
  char resultFlag;
  size_t shortValue;
  undefined4 *dataCursor;
  void *value2;
  int value;
  char *stringCursor;
  
  if (g_CrtRuntimeStringBuffersInitialized == 0) {
    ConvertStringBuffersIfNeeded();
  }
  value = 0;
  for (stringCursor = g_CrtRawEnvironmentStrings; *stringCursor != '\0'; stringCursor = stringCursor + shortValue + 1) {
    if (*stringCursor != '=') {
      value = value + 1;
    }
    shortValue = strlen(stringCursor);
  }
  dataCursor = malloc(value * 4 + 4);
  _g_CrtEnvpBufferPtr = dataCursor;
  if (dataCursor == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  resultFlag = *g_CrtRawEnvironmentStrings;
  stringCursor = g_CrtRawEnvironmentStrings;
  while (resultFlag != '\0') {
    shortValue = strlen(stringCursor);
    if (*stringCursor != '=') {
      value2 = malloc(shortValue + 1);
      *dataCursor = value2;
      if (value2 == (void *)0x0) {
        __amsg_exit(9);
      }
      strcpy(*dataCursor,stringCursor);
      dataCursor = dataCursor + 1;
    }
    stringCursor = stringCursor + shortValue + 1;
    resultFlag = *stringCursor;
  }
  free(g_CrtRawEnvironmentStrings);
  g_CrtRawEnvironmentStrings = (char *)0x0;
  *dataCursor = 0;
  _g_CrtEnvironmentBlockPtr = 1;
  return;
}

