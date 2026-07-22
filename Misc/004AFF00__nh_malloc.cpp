#include "tarzan_ghidra_types.hpp"

// Address: 0x004AFF00
// Label: _nh_malloc
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _nh_malloc(size_t _Size,int _NhFlag)

{
  void *value2;
  int value;
  
  if (_Size < 0xffffffe1) {
    do {
      value2 = (void *)_heap_alloc(_Size);
      if (value2 != (void *)0x0) {
        return value2;
      }
      if (_NhFlag == 0) {
        return (void *)0x0;
      }
      value = _callnewh(_Size);
    } while (value != 0);
  }
  return (void *)0x0;
}

