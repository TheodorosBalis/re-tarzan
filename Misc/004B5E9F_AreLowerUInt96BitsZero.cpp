#include "tarzan_ghidra_types.hpp"

// Address: 0x004B5E9F
// Label: AreLowerUInt96BitsZero
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 AreLowerUInt96BitsZero(int arg1,int arg2)

{
  int *intCursor;
  int value;
  
  if ((*(uint *)(arg1 + (arg2 / 0x20) * 4) & ~(-1 << (0x1fU - (char)(arg2 % 0x20) & 0x1f)))
      != 0) {
    return 0;
  }
  value = arg2 / 0x20 + 1;
  if (value < 3) {
    intCursor = (int *)(arg1 + value * 4);
    do {
      if (*intCursor != 0) {
        return 0;
      }
      value = value + 1;
      intCursor = intCursor + 1;
    } while (value < 3);
  }
  return 1;
}

