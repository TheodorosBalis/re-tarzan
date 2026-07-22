#include "tarzan_ghidra_types.hpp"

// Address: 0x0044C5D0
// Label: SelectSaborEncounterIndexFromPlayerX
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SelectSaborEncounterIndexFromPlayerX(void)

{
  int count;
  int count2;
  
  _g_CurrentSaborEncounterIndex = 0xffff;
  count2 = 0;
  count = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14);
  while ((count < (int)(&g_SaborFightAnchor0LeftX)[count2] ||
         ((int)(&g_SaborFightAnchor0RightX)[count2] < count))) {
    count2 = count2 + 1;
    if (2 < count2) {
      return;
    }
  }
  _g_CurrentSaborEncounterIndex = (short)count2;
  return;
}

