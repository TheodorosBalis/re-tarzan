#include "tarzan_ghidra_types.hpp"

// Address: 0x00415D30
// Label: ComingOfAge::ResetAmbientSoundCue
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::ResetAmbientSoundCue(void)

{
  CEntities::ResetRandomAmbientSoundCountdown();
  PlayAudioById(200,(int *)0,(undefined4 *)0);
  *(undefined4 *)(g_CurrentWorldSceneContextPtr + 0x54) = 0;
  return;
}

