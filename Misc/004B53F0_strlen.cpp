#include "tarzan_ghidra_types.hpp"

// Address: 0x004B53F0
// Label: strlen
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    _strlen
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl strlen(char *_Str)

{
  uint value;
  uint *dataCursor;
  uint *dataCursor2;
  
  dataCursor = (uint *)_Str;
  do {
    if (((uint)dataCursor & 3) == 0) goto LAB_004b5410;
    value = *dataCursor;
    dataCursor = (uint *)((int)dataCursor + 1);
  } while ((char)value != '\0');
LAB_004b5443:
  return (size_t)((int)dataCursor + (-1 - (int)_Str));
LAB_004b5410:
  do {
    do {
      dataCursor2 = dataCursor;
      dataCursor = dataCursor2 + 1;
    } while (((*dataCursor2 ^ 0xffffffff ^ *dataCursor2 + 0x7efefeff) & 0x81010100) == 0);
    value = *dataCursor2;
    if ((char)value == '\0') {
      return (int)dataCursor2 - (int)_Str;
    }
    if ((char)(value >> 8) == '\0') {
      return (size_t)((int)dataCursor2 + (1 - (int)_Str));
    }
    if ((value & 0xff0000) == 0) {
      return (size_t)((int)dataCursor2 + (2 - (int)_Str));
    }
  } while ((value & 0xff000000) != 0);
  goto LAB_004b5443;
}

