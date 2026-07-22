#include "tarzan_ghidra_types.hpp"

// Address: 0x004947D0
// Label: UpdateCFGFile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateCFGFile(byte arg1,int arg2)

{
  uint *dataCursor;
  int value;
  
  if (-1 < arg2) {
    value = arg2 + 1;
    dataCursor = (uint *)(&g_CfgUnlockedLevelBitmasksByDifficulty + arg2 * 4);
    do {
      value = value + -1;
      *dataCursor = *dataCursor | 1 << (arg1 & 0x1f);
      dataCursor = dataCursor + -1;
    } while (value != 0);
  }
  SaveTarzanCFGFile();
  return;
}

