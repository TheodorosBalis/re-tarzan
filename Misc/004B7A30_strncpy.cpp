#include "tarzan_ghidra_types.hpp"

// Address: 0x004B7A30
// Label: strncpy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    _strncpy
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl strncpy(char *_Dest,char *_Source,size_t _Count)

{
  uint value;
  uint value2;
  char resultFlag;
  uint value3;
  uint *dataCursor;
  
  if (_Count == 0) {
    return _Dest;
  }
  dataCursor = (uint *)_Dest;
  if (((uint)_Source & 3) != 0) {
    while( true ) {
      value3 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 1);
      *(char *)dataCursor = (char)value3;
      dataCursor = (uint *)((int)dataCursor + 1);
      _Count = _Count - 1;
      if (_Count == 0) {
        return _Dest;
      }
      if ((char)value3 == '\0') break;
      if (((uint)_Source & 3) == 0) {
        value3 = _Count >> 2;
        goto joined_r0x004b7a6e;
      }
    }
    do {
      if (((uint)dataCursor & 3) == 0) {
        value3 = _Count >> 2;
        resultFlag = '\0';
        if (value3 == 0) goto LAB_004b7aab;
        goto LAB_004b7b19;
      }
      *(char *)dataCursor = '\0';
      dataCursor = (uint *)((int)dataCursor + 1);
      _Count = _Count - 1;
    } while (_Count != 0);
    return _Dest;
  }
  value3 = _Count >> 2;
  if (value3 != 0) {
    do {
      value = *(uint *)_Source;
      value2 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 4);
      if (((value ^ 0xffffffff ^ value + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)value2 == '\0') {
          *dataCursor = 0;
joined_r0x004b7b15:
          while( true ) {
            value3 = value3 - 1;
            dataCursor = dataCursor + 1;
            if (value3 == 0) break;
LAB_004b7b19:
            *dataCursor = 0;
          }
          resultFlag = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_004b7aab;
          return _Dest;
        }
        if ((char)(value2 >> 8) == '\0') {
          *dataCursor = value2 & 0xff;
          goto joined_r0x004b7b15;
        }
        if ((value2 & 0xff0000) == 0) {
          *dataCursor = value2 & 0xffff;
          goto joined_r0x004b7b15;
        }
        if ((value2 & 0xff000000) == 0) {
          *dataCursor = value2;
          goto joined_r0x004b7b15;
        }
      }
      *dataCursor = value2;
      dataCursor = dataCursor + 1;
      value3 = value3 - 1;
joined_r0x004b7a6e:
    } while (value3 != 0);
    _Count = _Count & 3;
    if (_Count == 0) {
      return _Dest;
    }
  }
  do {
    resultFlag = (char)*(uint *)_Source;
    _Source = (char *)((int)_Source + 1);
    *(char *)dataCursor = resultFlag;
    dataCursor = (uint *)((int)dataCursor + 1);
    if (resultFlag == '\0') {
      while (_Count = _Count - 1, _Count != 0) {
LAB_004b7aab:
        *(char *)dataCursor = resultFlag;
        dataCursor = (uint *)((int)dataCursor + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}

