#include "tarzan_ghidra_types.hpp"

// Address: 0x00444580
// Label: CEntities::UpdateStreaming
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::UpdateStreaming(void)

{
  int value;
  uint value3;
  int value2;
  uint value4;
  
  _g_RuntimeProcessingPhase = 1;
  *g_Phase2EntityList = 0;
  *g_LateEntityList = 0;
  ActivateRuntimeDescriptorsInBounds();
  if (*(code **)(g_CurrentLevelRuntimeHookTable + 0x14) != (code *)0x0) {
    (**(code **)(g_CurrentLevelRuntimeHookTable + 0x14))();
  }
  value4 = (uint)g_EntityEntryPoolEnd;
  if (value4 < g_EntityPoolCount) {
    value2 = value4 * 0x54;
    do {
      value = g_EntityPoolBase + value2;
      if ((*(byte *)(g_EntityPoolBase + value2) & 1) != 0) {
        value3 = *(uint *)(value + 0x28);
        if ((value3 & 1) != 0) {
          ((Entity *)value)->Update((Entity *)value);
        }
        if ((value3 & 2) != 0) {
          *g_Phase2EntityList = *g_Phase2EntityList + 1;
          g_Phase2EntityList[*g_Phase2EntityList] = value;
        }
        if ((value3 & 0x1000) != 0) {
          *g_LateEntityList = *g_LateEntityList + 1;
          g_LateEntityList[*g_LateEntityList] = value;
        }
      }
      value4 = value4 + 1;
      value2 = value2 + 0x54;
    } while ((int)value4 < (int)(uint)g_EntityPoolCount);
    _g_RuntimeProcessingPhase = 0;
    return;
  }
  _g_RuntimeProcessingPhase = 0;
  return;
}

