#include "tarzan_ghidra_types.hpp"

// Address: 0x0049A620
// Label: HashVirtualGamePath
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int HashVirtualGamePath(char *arg1)

{
  int value;
  char resultFlag;
  byte flagByte;
  int value2;
  int value3;
  int value4;
  
  value4 = 0;
  value2 = 0;
  value3 = 0;
  resultFlag = *arg1;
  while (resultFlag != '\0') {
    flagByte = (byte)value2;
    value2 = value2 + 8;
    value4 = value4 + ((int)resultFlag << (flagByte & 0x1f));
    if (0x18 < value2) {
      value2 = 0;
    }
    value = value3 + 1;
    value3 = value3 + 1;
    resultFlag = arg1[value];
  }
  return value4 + value3;
}

