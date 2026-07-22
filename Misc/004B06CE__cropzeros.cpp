#include "tarzan_ghidra_types.hpp"

// Address: 0x004B06CE
// Label: _cropzeros
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _cropzeros(char *arg1)

{
  char resultFlag;
  char *stringCursor;
  char *stringCursor2;
  
  resultFlag = *arg1;
  while ((resultFlag != '\0' && (resultFlag != g_CrtDecimalPointString))) {
    stringCursor = arg1 + 1;
    arg1 = arg1 + 1;
    resultFlag = *stringCursor;
  }
  if (*arg1 != '\0') {
    do {
      arg1 = arg1 + 1;
      resultFlag = *arg1;
      stringCursor = arg1;
      if ((resultFlag == '\0') || (resultFlag == 'e')) break;
    } while (resultFlag != 'E');
    do {
      stringCursor2 = stringCursor;
      stringCursor = stringCursor2 + -1;
    } while (*stringCursor == '0');
    if (*stringCursor == g_CrtDecimalPointString) {
      stringCursor = stringCursor2 + -2;
    }
    do {
      resultFlag = *arg1;
      stringCursor = stringCursor + 1;
      arg1 = arg1 + 1;
      *stringCursor = resultFlag;
    } while (resultFlag != '\0');
  }
  return;
}

