#include "tarzan_ghidra_types.hpp"

// Address: 0x004B628B
// Label: _fptostr
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _fptostr(char *arg1,int arg2,int arg3)

{
  char *_Str;
  char *stringCursor;
  char *stringCursor2;
  size_t shortValue;
  char *stringCursor3;
  char resultFlag;
  
  stringCursor = arg1;
  stringCursor3 = *(char **)(arg3 + 0xc);
  _Str = arg1 + 1;
  *arg1 = '0';
  stringCursor2 = _Str;
  if (0 < arg2) {
    arg1 = (char *)arg2;
    arg2 = 0;
    do {
      resultFlag = *stringCursor3;
      if (resultFlag == '\0') {
        resultFlag = '0';
      }
      else {
        stringCursor3 = stringCursor3 + 1;
      }
      *stringCursor2 = resultFlag;
      stringCursor2 = stringCursor2 + 1;
      arg1 = (char *)((int)arg1 + -1);
    } while (arg1 != (char *)0x0);
  }
  *stringCursor2 = '\0';
  if ((-1 < arg2) && ('4' < *stringCursor3)) {
    while (stringCursor2 = stringCursor2 + -1, *stringCursor2 == '9') {
      *stringCursor2 = '0';
    }
    *stringCursor2 = *stringCursor2 + '\x01';
  }
  if (*stringCursor == '1') {
    *(int *)(arg3 + 4) = *(int *)(arg3 + 4) + 1;
  }
  else {
    shortValue = strlen(_Str);
    memmove(stringCursor,_Str,shortValue + 1);
  }
  return;
}

