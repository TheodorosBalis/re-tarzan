#include "tarzan_ghidra_types.hpp"

// Address: 0x0044BF90
// Label: LoadSaborBattleResources
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LoadSaborBattleResources(void)

{
  undefined4 value;
  
  UnloadEncodedResourceId(0x1005);
  UnloadEncodedResourceId(0x1002);
  if (_g_CurrentSaborEncounterIndex == 1) {
    value = 0x2026;
  }
  else {
    if (_g_CurrentSaborEncounterIndex != 2) goto LAB_0044bfc8;
    value = 0x2029;
  }
  UnloadEncodedResourceId(value);
LAB_0044bfc8:
  LoadEncodedResourceId(0x1007);
  LoadEncodedResourceId(0x2c);
  LoadEncodedResourceId(0x1017);
  return;
}

