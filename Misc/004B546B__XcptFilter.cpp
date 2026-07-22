#include "tarzan_ghidra_types.hpp"

// Address: 0x004B546B
// Label: _XcptFilter
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

LONG _XcptFilter(undefined4 arg1,_EXCEPTION_POINTERS *arg2)

{
  code *stringCursor;
  undefined4 value5;
  undefined4 value6;
  int value2;
  int *intCursor;
  LONG value;
  int value3;
  int value4;
  
  value2 = _getptd();
  intCursor = (int *)xcptlookup(arg1,*(undefined4 *)(value2 + 0x50));
  if ((intCursor == (int *)0x0) || (stringCursor = (code *)intCursor[2], stringCursor == (code *)0x0)) {
    value = UnhandledExceptionFilter(arg2);
  }
  else if (stringCursor == (code *)0x5) {
    intCursor[2] = 0;
    value = 1;
  }
  else {
    if (stringCursor != (code *)0x1) {
      value5 = *(undefined4 *)(value2 + 0x54);
      *(_EXCEPTION_POINTERS **)(value2 + 0x54) = arg2;
      if (intCursor[1] == 8) {
        if (g_CrtExceptionFilterEntry0 < g_CrtExceptionFilterEntry1 + g_CrtExceptionFilterEntry0) {
          value3 = g_CrtExceptionFilterEntry0 * 0xc;
          value4 = g_CrtExceptionFilterEntry0;
          do {
            *(undefined4 *)(value3 + 8 + *(int *)(value2 + 0x50)) = 0;
            value4 = value4 + 1;
            value3 = value3 + 0xc;
          } while (value4 < g_CrtExceptionFilterEntry1 + g_CrtExceptionFilterEntry0);
        }
        value3 = *intCursor;
        value6 = *(undefined4 *)(value2 + 0x58);
        if (value3 == -0x3fffff72) {
          *(undefined4 *)(value2 + 0x58) = 0x83;
        }
        else if (value3 == -0x3fffff70) {
          *(undefined4 *)(value2 + 0x58) = 0x81;
        }
        else if (value3 == -0x3fffff6f) {
          *(undefined4 *)(value2 + 0x58) = 0x84;
        }
        else if (value3 == -0x3fffff6d) {
          *(undefined4 *)(value2 + 0x58) = 0x85;
        }
        else if (value3 == -0x3fffff73) {
          *(undefined4 *)(value2 + 0x58) = 0x82;
        }
        else if (value3 == -0x3fffff71) {
          *(undefined4 *)(value2 + 0x58) = 0x86;
        }
        else if (value3 == -0x3fffff6e) {
          *(undefined4 *)(value2 + 0x58) = 0x8a;
        }
        (*stringCursor)(8,*(undefined4 *)(value2 + 0x58));
        *(undefined4 *)(value2 + 0x58) = value6;
      }
      else {
        intCursor[2] = 0;
        (*stringCursor)(intCursor[1]);
      }
      *(undefined4 *)(value2 + 0x54) = value5;
    }
    value = -1;
  }
  return value;
}

