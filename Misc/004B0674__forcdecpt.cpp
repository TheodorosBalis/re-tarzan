#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0674
// Label: _forcdecpt
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _forcdecpt(char *arg1)

{
  char resultFlag;
  char resultFlag2;
  int value;
  uint value2;
  
  value = tolower((int)*arg1);
  if (value != 0x65) {
    do {
      arg1 = arg1 + 1;
      if (g_CrtLocaleEnabled < 2) {
        value2 = (byte)g_CrtCtypeTable[*arg1 * 2] & 4;
      }
      else {
        value2 = _isctype((int)*arg1,4);
      }
    } while (value2 != 0);
  }
  resultFlag2 = *arg1;
  *arg1 = g_CrtDecimalPointString;
  do {
    arg1 = arg1 + 1;
    resultFlag = *arg1;
    *arg1 = resultFlag2;
    resultFlag2 = resultFlag;
  } while (*arg1 != '\0');
  return;
}

