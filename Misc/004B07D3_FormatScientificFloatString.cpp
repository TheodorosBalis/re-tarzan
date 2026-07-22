#include "tarzan_ghidra_types.hpp"

// Address: 0x004B07D3
// Label: FormatScientificFloatString
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined1 *
FormatScientificFloatString(undefined1 *arg1,int arg2,int arg3,int *arg4,char arg5)

{
  undefined1 *dataCursor;
  undefined1 *dataCursor2;
  int value;
  
  if (arg5 != '\0') {
    ShiftStringRight(arg1 + (*arg4 == 0x2d),0 < arg2);
  }
  dataCursor2 = arg1;
  if (*arg4 == 0x2d) {
    *arg1 = 0x2d;
    dataCursor2 = arg1 + 1;
  }
  dataCursor = dataCursor2;
  if (0 < arg2) {
    dataCursor = dataCursor2 + 1;
    *dataCursor2 = dataCursor2[1];
    *dataCursor = g_CrtDecimalPointString;
  }
  dataCursor2 = (undefined1 *)strcpy(dataCursor + arg2 + (uint)(arg5 == '\0'),"e+000");
  if (arg3 != 0) {
    *dataCursor2 = 0x45;
  }
  if (*(char *)arg4[3] != '0') {
    value = arg4[1] + -1;
    if (value < 0) {
      value = -value;
      dataCursor2[1] = 0x2d;
    }
    if (99 < value) {
      dataCursor2[2] = dataCursor2[2] + (char)(value / 100);
      value = value % 100;
    }
    if (9 < value) {
      dataCursor2[3] = dataCursor2[3] + (char)(value / 10);
      value = value % 10;
    }
    dataCursor2[4] = dataCursor2[4] + (char)value;
  }
  return arg1;
}

