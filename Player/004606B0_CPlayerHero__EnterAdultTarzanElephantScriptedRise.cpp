#include "tarzan_ghidra_types.hpp"

// Address: 0x004606B0
// Label: CPlayerHero::EnterAdultTarzanElephantScriptedRise
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanElephantScriptedRise(void)

{
  g_AdultTarzanElephantCameraLeadTarget = 0x708;
  g_AdultTarzanElephantScriptedRiseActive = 1;
  PlayAudioById(0x5b,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  PlayAudioById(0x3b6,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  return;
}

