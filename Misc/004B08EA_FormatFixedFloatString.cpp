#include "tarzan_ghidra_types.hpp"

// Address: 0x004B08EA
// Label: FormatFixedFloatString
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined1 * FormatFixedFloatString(undefined1 *arg1,size_t arg2,int *arg3,char arg4)

{
  int value;
  int value2;
  undefined1 *dataCursor;
  
  value = arg3[1];
  if ((arg4 != '\0') && (value - 1U == arg2)) {
    value2 = *arg3;
    arg1[(uint)(value2 == 0x2d) + (value - 1U)] = 0x30;
    (arg1 + (uint)(value2 == 0x2d) + (value - 1U))[1] = 0;
  }
  dataCursor = arg1;
  if (*arg3 == 0x2d) {
    *arg1 = 0x2d;
    dataCursor = arg1 + 1;
  }
  if (arg3[1] < 1) {
    ShiftStringRight(dataCursor,1);
    *dataCursor = 0x30;
    dataCursor = dataCursor + 1;
  }
  else {
    dataCursor = dataCursor + arg3[1];
  }
  if (0 < (int)arg2) {
    ShiftStringRight(dataCursor,1);
    *dataCursor = g_CrtDecimalPointString;
    value = arg3[1];
    if (value < 0) {
      if ((arg4 != '\0') || (-value <= (int)arg2)) {
        arg2 = -value;
      }
      ShiftStringRight(dataCursor + 1,arg2);
      memset(dataCursor + 1,0x30,arg2);
    }
  }
  return arg1;
}

