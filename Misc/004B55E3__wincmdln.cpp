#include "tarzan_ghidra_types.hpp"

// Address: 0x004B55E3
// Label: _wincmdln
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

byte * _wincmdln(void)

{
  byte flagByte;
  int value;
  byte *value2;
  byte *value3;
  
  if (g_CrtRuntimeStringBuffersInitialized == 0) {
    ConvertStringBuffersIfNeeded();
  }
  flagByte = *EXEfilePath;
  value3 = EXEfilePath;
  if (flagByte == 0x22) {
    while( true ) {
      value2 = value3;
      flagByte = value2[1];
      value3 = value2 + 1;
      if ((flagByte == 0x22) || (flagByte == 0)) break;
      value = _ismbblead(flagByte);
      if (value != 0) {
        value3 = value2 + 2;
      }
    }
    if (*value3 == 0x22) goto LAB_004b5620;
  }
  else {
    while (0x20 < flagByte) {
      flagByte = value3[1];
      value3 = value3 + 1;
    }
  }
  for (; (*value3 != 0 && (*value3 < 0x21)); value3 = value3 + 1) {
LAB_004b5620:
  }
  return value3;
}

