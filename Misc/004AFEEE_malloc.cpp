#include "tarzan_ghidra_types.hpp"

// Address: 0x004AFEEE
// Label: malloc
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl malloc(size_t _Size)

{
  void *value;
  
  value = _nh_malloc(_Size,g_CrtHeapAllocationState);
  return value;
}

