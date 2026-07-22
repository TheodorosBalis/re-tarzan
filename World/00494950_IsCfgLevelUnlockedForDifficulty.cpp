#include "tarzan_ghidra_types.hpp"

// Address: 0x00494950
// Label: IsCfgLevelUnlockedForDifficulty
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint IsCfgLevelUnlockedForDifficulty(byte arg1,int arg2)

{
  return *(int *)(&g_CfgUnlockedLevelBitmasksByDifficulty + arg2 * 4) >> (arg1 & 0x1f) & 1;
}

