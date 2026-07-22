#include "tarzan_ghidra_types.hpp"

// Address: 0x0045D250
// Label: JourneyToTheTreeHouse::InitLevelRuntimeHook
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::InitLevelRuntimeHook(void)

{
  PlayAudioById(200,(int *)0,(undefined4 *)0);
  CEntities::ResetRandomAmbientSoundCountdown();
  return;
}

