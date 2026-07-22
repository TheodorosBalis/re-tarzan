#include "tarzan_ghidra_types.hpp"

// Address: 0x004B24FD
// Label: WriteCharacterToStreamAndCount
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void WriteCharacterToStreamAndCount(uint arg1,int *arg2,int *arg3)

{
  int *intCursor;
  
  intCursor = arg2 + 1;
  *intCursor = *intCursor + -1;
  if (*intCursor < 0) {
    arg1 = _flsbuf(arg1,arg2);
  }
  else {
    *(undefined1 *)*arg2 = (undefined1)arg1;
    *arg2 = *arg2 + 1;
    arg1 = arg1 & 0xff;
  }
  if (arg1 == 0xffffffff) {
    *arg3 = -1;
    return;
  }
  *arg3 = *arg3 + 1;
  return;
}

