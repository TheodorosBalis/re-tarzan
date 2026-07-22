#include "tarzan_ghidra_types.hpp"

// Address: 0x00494C50
// Label: SetCurrentDirectoryToExePath
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetCurrentDirectoryToExePath(void)

{
  char resultFlag;
  char *stringCursor;
  DWORD directXResult;
  uint value2;
  int value;
  CHAR scratchRect [1024];
  
  directXResult = GetModuleFileNameA((HMODULE)0x0,scratchRect,0x400);
  if (directXResult != 0) {
    value2 = 0xffffffff;
    stringCursor = scratchRect;
    do {
      if (value2 == 0) break;
      value2 = value2 - 1;
      resultFlag = *stringCursor;
      stringCursor = stringCursor + 1;
    } while (resultFlag != '\0');
    for (value = ~value2 - 2; 0 < value; value = value + -1) {
      if (scratchRect[value] == '\\') {
        scratchRect[value] = '\0';
        break;
      }
    }
    SetCurrentDirectoryA(scratchRect);
  }
  return;
}

