#include "tarzan_ghidra_types.hpp"

// Address: 0x004319C0
// Label: GoingApe::InitializeAmbientSoundCue
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::InitializeAmbientSoundCue(void)

{
  PlayAudioById(200,(int *)0,(undefined4 *)0);
  CEntities::ResetRandomAmbientSoundCountdown();
  *(undefined4 *)(g_CurrentWorldSceneContextPtr + 0x54) = 0;
  return;
}

