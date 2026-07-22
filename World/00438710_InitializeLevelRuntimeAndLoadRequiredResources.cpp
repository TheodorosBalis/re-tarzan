#include "tarzan_ghidra_types.hpp"

// Address: 0x00438710
// Label: InitializeLevelRuntimeAndLoadRequiredResources
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitializeLevelRuntimeAndLoadRequiredResources(void)

{
  ushort *dataCursor;
  short shortValue;
  ushort value2;
  undefined2 upperWord;
  uint value3;
  undefined2 upperWord2;
  undefined2 upperWord3;
  undefined2 value4;
  int value;
  short *value5;
  ushort *dataCursor2;
  undefined4 *dataCursor3;
  
  InitializeWorldSceneObjectArray(&g_ResourceSetDescriptorTable,0x91);
  *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = 0;
  *( undefined2 *)((int)&g_GameplayStateFlags + 0) = 0;
  _g_RockinTheBoatLevelStateTable = 1;
  CEntities::SelectLevelRuntimeDescriptorConfig(&DAT_00511270);
  CEntities::InitEntityAttachmentHeap(g_CurrentLevelRuntimeHookTable);
  CEntities::ResetEntityTemplates();
  CWorld::InitGameplayHudForLevel();
  g_EntityPoolBase =
       CompactAndAllocModelHeapBlock
                 ((uint)(ushort)g_EntityPoolLimit * 0x54,&g_ModelLoadHeapState);
  _g_LevelRuntimeResourceLoadState =
       g_EntityPoolBase + -0x54 + (uint)(ushort)g_EntityPoolLimit * 0x54;
  g_Phase2EntityList =
       (undefined4 *)
       CompactAndAllocModelHeapBlock
                 ((uint)(ushort)g_EntityPoolLimit << 2,&g_ModelLoadHeapState);
  *g_Phase2EntityList = 0;
  g_LateEntityList =
       (undefined4 *)
       CompactAndAllocModelHeapBlock
                 ((uint)(ushort)g_EntityPoolLimit << 2,&g_ModelLoadHeapState);
  *g_LateEntityList = 0;
  CEntities::ResetHudTextRendererState();
  value4 = 0;
  dataCursor3 = &g_WorldSceneAuxResourceSlotTable;
  for (value = 0x10; value != 0; value = value + -1) {
    *dataCursor3 = 0;
    dataCursor3 = dataCursor3 + 1;
  }
  if (*( undefined2 *)((int)&g_LevelTransitionRequestFlags + 2) != 0) {
    value = g_CurrentWorldSceneContext;
    if (*( undefined2 *)((int)&g_LevelTransitionRequestFlags + 2) != 0x8000) {
      value = g_WorldEntitySceneObjectArrayBase + (uint)*( undefined2 *)((int)&g_LevelTransitionRequestFlags + 2) * 0x68;
    }
    CWorld::LoadNatureTerrainSceneContext
              (&g_CurrentWorldSceneContext,value,g_CurrentLevelResourceConfig);
    value4 = upperWord;
  }
  value5 = *(short **)(g_CurrentLevelStartPositionX + 4);
  shortValue = *value5;
  value3 = CONCAT22(value4,shortValue);
  while (-1 < shortValue) {
    if ((value3 & 0x4000) == 0) {
      LoadNecessaryEncodedResourceId(value3);
      value4 = upperWord3;
    }
    else {
      ReleaseEncodedResourceId();
      value4 = upperWord2;
    }
    shortValue = value5[1];
    value3 = CONCAT22(value4,shortValue);
    value5 = value5 + 1;
  }
  dataCursor2 = *(ushort **)(g_CurrentLevelStartPositionZ + 0x20 + g_CurrentCheckpointId * 0x24);
  value2 = *dataCursor2;
  while (-1 < (short)value2) {
    if ((value2 & 0x4000) == 0) {
      LoadNecessaryEncodedResourceId(value2);
    }
    else {
      ReleaseEncodedResourceId();
    }
    dataCursor = dataCursor2 + 1;
    dataCursor2 = dataCursor2 + 1;
    value2 = *dataCursor;
  }
  return;
}

