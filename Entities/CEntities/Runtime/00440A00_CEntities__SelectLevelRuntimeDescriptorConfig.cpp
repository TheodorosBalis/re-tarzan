#include "tarzan_ghidra_types.hpp"

// Address: 0x00440A00
// Label: CEntities::SelectLevelRuntimeDescriptorConfig
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::SelectLevelRuntimeDescriptorConfig(ushort *descriptor)

{
  ushort value2;
  int value;
  ushort *dataCursor;
  
  value = 0;
  value2 = *descriptor;
  if (value2 != 999) {
    dataCursor = descriptor;
    do {
      if ((uint)value2 == (int)*( undefined1 *)((int)&g_LevelTransitionContext + 2)) break;
      value2 = dataCursor[8];
      dataCursor = dataCursor + 8;
      value = value + 1;
    } while (value2 != 999);
  }
  g_EntityEntryPoolEnd = descriptor[value * 8 + 2];
  *( undefined2 *)((int)&g_EntityPoolLimit + 0) = descriptor[value * 8 + 1];
  g_EntityPoolCount = descriptor[value * 8 + 1];
  g_CurrentLevelRuntimeHookTable = (uint)descriptor[value * 8 + 3] << 10;
  g_CurrentLevelStartPositionX = *(undefined2 **)(descriptor + value * 8 + 4);
  if (g_CurrentLevelStartPositionX == (undefined2 *)0x0) {
    g_CurrentLevelStartPositionX = &DAT_004ef4b8;
  }
  g_CurrentLevelRuntimeHookTable = *(undefined **)(descriptor + value * 8 + 6);
  if (g_CurrentLevelRuntimeHookTable == (undefined *)0x0) {
    g_CurrentLevelRuntimeHookTable = &DAT_00531df8;
  }
  g_CurrentLevelStartPositionZ = *(int *)(g_CurrentLevelStartPositionX + 6);
  *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 2) = *g_CurrentLevelStartPositionX;
  g_CurrentLevelResourceConfig = *(undefined4 *)(g_CurrentLevelStartPositionX + 4);
  value = *(int *)(g_CurrentLevelStartPositionZ + g_CurrentCheckpointId * 0x24);
  if (value != -1) {
    *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 2) = (undefined2)value;
  }
  return g_CurrentLevelStartPositionZ + g_CurrentCheckpointId * 0x24;
}

