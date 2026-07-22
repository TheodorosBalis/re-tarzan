#include "tarzan_ghidra_types.hpp"

// Address: 0x00486F70
// Label: TrashingTheCamp::InitLevelRuntimeHook
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitLevelRuntimeHook(void)

{
  *(undefined4 *)(g_CurrentWorldSceneContextPtr + 0x54) = 0;
  PlayAudioById(200,(int *)0,(undefined4 *)0);
  CEntities::ResetRandomAmbientSoundCountdown();
  g_TrashingTheCampHeldThrownPropEntity = 0;
  g_TrashingTheCampAmbientBirdVariantCounter = TotalGameLoopTicks;
  g_TrashingTheCampImpactThrownPropEntity = 0;
  return;
}

