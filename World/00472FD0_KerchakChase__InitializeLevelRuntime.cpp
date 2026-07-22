#include "tarzan_ghidra_types.hpp"

// Address: 0x00472FD0
// Label: KerchakChase::InitializeLevelRuntime
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void KerchakChase::InitializeLevelRuntime(void)

{
  InitHudCountdownFromLevelConfig();
  PlayAudioById(200,(int *)0,(undefined4 *)0);
  g_PlayerPickupTriggerRadius = 0x200;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x142) = 0x200;
  CEntities::ResetRandomAmbientSoundCountdown();
  return;
}

