#include "tarzan_ghidra_types.hpp"

// Address: 0x004B6510
// Label: memset
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    _memset
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  uint value;
  uint value2;
  size_t shortValue;
  uint *dataCursor;
  
  if (_Size == 0) {
    return _Dst;
  }
  value = _Val & 0xff;
  dataCursor = _Dst;
  if (3 < _Size) {
    value2 = -(int)_Dst & 3;
    shortValue = _Size;
    if (value2 != 0) {
      shortValue = _Size - value2;
      do {
        *(undefined1 *)dataCursor = (undefined1)_Val;
        dataCursor = (uint *)((int)dataCursor + 1);
        value2 = value2 - 1;
      } while (value2 != 0);
    }
    value = value * 0x1010101;
    _Size = shortValue & 3;
    value2 = shortValue >> 2;
    if (value2 != 0) {
      for (; value2 != 0; value2 = value2 - 1) {
        *dataCursor = value;
        dataCursor = dataCursor + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)dataCursor = (char)value;
    dataCursor = (uint *)((int)dataCursor + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}

