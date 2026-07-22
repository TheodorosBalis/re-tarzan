#include "tarzan_ghidra_types.hpp"

// Address: 0x004B6A10
// Label: _getbuf
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _getbuf(undefined4 *arg1)

{
  void *value;
  
  _g_AllocatedStreamBufferCount = _g_AllocatedStreamBufferCount + 1;
  value = malloc(0x1000);
  arg1[2] = value;
  if (value == (void *)0x0) {
    arg1[3] = arg1[3] | 4;
    arg1[2] = arg1 + 5;
    arg1[6] = 2;
  }
  else {
    arg1[3] = arg1[3] | 8;
    arg1[6] = 0x1000;
  }
  arg1[1] = 0;
  *arg1 = arg1[2];
  return;
}

