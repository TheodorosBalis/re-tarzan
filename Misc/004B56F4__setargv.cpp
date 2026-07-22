#include "tarzan_ghidra_types.hpp"

// Address: 0x004B56F4
// Label: _setargv
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _setargv(void)

{
  void *value;
  char *stringCursor;
  int localState2;
  int localState;
  
  if (g_CrtRuntimeStringBuffersInitialized == 0) {
    ConvertStringBuffersIfNeeded();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_00c46d3c,0x104);
  _g_CrtArgvParseState = &DAT_00c46d3c;
  stringCursor = &DAT_00c46d3c;
  if (*EXEfilePath != '\0') {
    stringCursor = EXEfilePath;
  }
  ScanFilePath(stringCursor,0,0,&localState,&localState2);
  value = malloc(localState2 + localState * 4);
  if (value == (void *)0x0) {
    __amsg_exit(8);
  }
  ScanFilePath(stringCursor,value,(void *)((int)value + localState * 4),&localState,&localState2);
  _g_CrtArgvBufferPtr = value;
  _g_CrtArgvModeFlag = localState + -1;
  return;
}

