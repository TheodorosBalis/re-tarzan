#include "tarzan_ghidra_types.hpp"

// Address: 0x00445120
// Label: ResolveModelDataIndexedRelativePointer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ResolveModelDataIndexedRelativePointer(int arg1,int arg2,int arg3)

{
  int value;
  char resultFlag;
  int value2;
  
  value2 = *(int *)(arg2 + 8 + arg3 * 4);
  resultFlag = (char)value2;
  value2 = value2 >> 8;
  if (resultFlag == '\0') {
    return value2 + *(int *)(arg1 + 0xc);
  }
  value = *(int *)(arg1 + 0x28 + resultFlag * 8);
  if (value == 0) {
    return 0;
  }
  return value2 + value;
}

