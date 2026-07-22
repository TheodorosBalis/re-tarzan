#include "tarzan_ghidra_types.hpp"

// Address: 0x004B7120
// Label: strncmp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    _strncmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char resultFlag;
  char resultFlag2;
  size_t shortValue;
  int value;
  uint value2;
  char *stringCursor;
  char *stringCursor2;
  
  value2 = 0;
  shortValue = _MaxCount;
  stringCursor = _Str1;
  if (_MaxCount != 0) {
    do {
      if (shortValue == 0) break;
      shortValue = shortValue - 1;
      resultFlag = *stringCursor;
      stringCursor = stringCursor + 1;
    } while (resultFlag != '\0');
    value = _MaxCount - shortValue;
    do {
      stringCursor = _Str2;
      stringCursor2 = _Str1;
      if (value == 0) break;
      value = value + -1;
      stringCursor2 = _Str1 + 1;
      stringCursor = _Str2 + 1;
      resultFlag2 = *_Str1;
      resultFlag = *_Str2;
      _Str2 = stringCursor;
      _Str1 = stringCursor2;
    } while (resultFlag == resultFlag2);
    value2 = 0;
    if ((byte)stringCursor[-1] <= (byte)stringCursor2[-1]) {
      if (stringCursor[-1] == stringCursor2[-1]) {
        return 0;
      }
      value2 = 0xfffffffe;
    }
    value2 = ~value2;
  }
  return value2;
}

