#include "tarzan_ghidra_types.hpp"

// Address: 0x004417F0
// Label: ActivateLevelStartupRuntimeDescriptors
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ActivateLevelStartupRuntimeDescriptors(void)

{
  code *stringCursor;
  int value;
  int *intCursor;
  
  intCursor = g_RuntimeDescriptorArray;
  stringCursor = *(code **)(g_CurrentLevelRuntimeHookTable + 8);
  if (*(code **)(g_CurrentLevelRuntimeHookTable + 0x1c) != (code *)0x0) {
    (**(code **)(g_CurrentLevelRuntimeHookTable + 0x1c))();
  }
  if (*(code **)(g_CurrentLevelRuntimeHookTable + 4) == (code *)0x0) {
    BuildDefaultRuntimeActivationBounds(&g_RuntimeActivationBounds,&g_RuntimeOuterActivationBounds);
  }
  else {
    (**(code **)(g_CurrentLevelRuntimeHookTable + 4))();
  }
  value = 0;
  if (0 < g_RuntimeDescriptorCount) {
    do {
      if ((*(ushort *)((int)intCursor + 0x1a) & 0x8001) == 0) {
        if ((*(ushort *)((int)intCursor + 0x1a) & 0x40) == 0) {
          if (stringCursor == (code *)0x0) {
            if ((((g_RuntimeActivationBounds < *intCursor) && (*intCursor < g_RuntimeActivationMaxX)) &&
                (g_RuntimeActivationMinZ < intCursor[2])) && (intCursor[2] < g_RuntimeActivationMaxZ))
            goto LAB_00441882;
          }
          else {
            (*stringCursor)(intCursor);
          }
        }
        else {
LAB_00441882:
          InstantiateEntityFromDescriptor(intCursor);
        }
      }
      value = value + 1;
      intCursor = intCursor + 7;
    } while (value < g_RuntimeDescriptorCount);
  }
  return;
}

