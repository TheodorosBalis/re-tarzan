#include "tarzan_ghidra_types.hpp"

// Address: 0x004418A0
// Label: ActivateRuntimeDescriptorsInBounds
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ActivateRuntimeDescriptorsInBounds(void)

{
  code *stringCursor;
  int value;
  int *intCursor;
  
  intCursor = g_RuntimeDescriptorArray;
  stringCursor = *(code **)(g_CurrentLevelRuntimeHookTable + 8);
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
        if (stringCursor == (code *)0x0) {
          if ((((g_RuntimeActivationBounds < *intCursor) && (*intCursor < g_RuntimeActivationMaxX)) &&
              (g_RuntimeActivationMinZ < intCursor[2])) && (intCursor[2] < g_RuntimeActivationMaxZ)) {
            InstantiateEntityFromDescriptor(intCursor);
          }
        }
        else {
          (*stringCursor)(intCursor);
        }
      }
      value = value + 1;
      intCursor = intCursor + 7;
    } while (value < g_RuntimeDescriptorCount);
  }
  return;
}

