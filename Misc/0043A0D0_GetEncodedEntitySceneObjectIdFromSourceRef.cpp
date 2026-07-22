#include "tarzan_ghidra_types.hpp"

// Address: 0x0043A0D0
// Label: GetEncodedEntitySceneObjectIdFromSourceRef
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint GetEncodedEntitySceneObjectIdFromSourceRef(char *arg1)

{
  char resultFlag;
  
  resultFlag = *arg1;
  if (resultFlag == '\0') {
    return (int)((uint)(arg1 + (*(int *)(arg1 + 4) - g_NatureTerrainModelSourceRefTable)) |
                0x28000) >> 3;
  }
  if (resultFlag != '\x01') {
    if (resultFlag != '\x02') {
      return 0xffffffff;
    }
    return ((*(int *)(arg1 + 4) - *(int *)(g_CurrentWorldSceneContext + 0xc)) + -0x34) / 0x30 |
           0x2000;
  }
  return (int)(arg1 +
              ((*(int *)(arg1 + 4) + 4 + arg1[3] * 4) -
              g_NatureTerrainSceneObjectSourceRefTable)) >> 2;
}

