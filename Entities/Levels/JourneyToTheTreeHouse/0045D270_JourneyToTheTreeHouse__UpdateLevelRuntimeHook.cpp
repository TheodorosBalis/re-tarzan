#include "tarzan_ghidra_types.hpp"

// Address: 0x0045D270
// Label: JourneyToTheTreeHouse::UpdateLevelRuntimeHook
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdateLevelRuntimeHook(void)

{
  CEntities::UpdateRandomAmbientSoundCue();
  RebuildModelHeapStats(&g_ModelLoadHeapState);
  return;
}

