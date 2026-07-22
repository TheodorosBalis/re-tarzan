#include "tarzan_ghidra_types.hpp"

// Address: 0x004B5397
// Label: GetInputCharacter
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint GetInputCharacter(undefined4 *arg1)

{
  int *intCursor;
  byte flagByte;
  uint value;
  
  intCursor = arg1 + 1;
  *intCursor = *intCursor + -1;
  if (-1 < *intCursor) {
    flagByte = *(byte *)*arg1;
    *arg1 = (byte *)*arg1 + 1;
    return (uint)flagByte;
  }
  value = _filbuf(arg1);
  return value;
}

