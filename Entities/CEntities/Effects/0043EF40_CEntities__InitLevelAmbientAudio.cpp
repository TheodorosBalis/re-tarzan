#include "tarzan_ghidra_types.hpp"

// Address: 0x0043EF40
// Label: CEntities::InitLevelAmbientAudio
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitLevelAmbientAudio(void)

{
  PlayAudioById(200,(int *)0,(undefined4 *)0);
  CEntities::ResetRandomAmbientSoundCountdown();
  *(undefined4 *)(g_CurrentWorldSceneContextPtr + 0x54) = 0;
  return;
}

