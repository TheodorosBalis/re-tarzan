#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0448
// Label: fgets
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

char * fgets(char *arg1,int arg2,undefined4 *arg3)

{
  int *intCursor;
  uint value;
  char *stringCursor;
  
  if (arg2 < 1) {
    arg1 = (char *)0x0;
  }
  else {
    _lock_file(arg3);
    stringCursor = arg1;
    do {
      arg2 = arg2 + -1;
      if (arg2 == 0) break;
      intCursor = arg3 + 1;
      *intCursor = *intCursor + -1;
      if (*intCursor < 0) {
        value = _filbuf(arg3);
      }
      else {
        value = (uint)*(byte *)*arg3;
        *arg3 = (byte *)*arg3 + 1;
      }
      if (value == 0xffffffff) {
        if (stringCursor == arg1) {
          arg1 = (char *)0x0;
          goto LAB_004b049c;
        }
        break;
      }
      *stringCursor = (char)value;
      stringCursor = stringCursor + 1;
    } while ((char)value != '\n');
    *stringCursor = '\0';
LAB_004b049c:
    _unlock_file(arg3);
  }
  return arg1;
}

