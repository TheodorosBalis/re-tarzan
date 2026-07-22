#include "tarzan_ghidra_types.hpp"

// Address: 0x004B7D52
// Label: BackwardScanForZero
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int BackwardScanForZero(char *arg1,int arg2)

{
  char *stringCursor;
  int value;
  
  value = arg2;
  for (stringCursor = arg1; (value != 0 && (value = value + -1, *stringCursor != '\0')); stringCursor = stringCursor + 1)
  {
  }
  if (*stringCursor != '\0') {
    return arg2;
  }
  return (int)stringCursor - (int)arg1;
}

