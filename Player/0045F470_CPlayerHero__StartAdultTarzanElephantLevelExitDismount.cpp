#include "tarzan_ghidra_types.hpp"

// Address: 0x0045F470
// Label: CPlayerHero::StartAdultTarzanElephantLevelExitDismount
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::StartAdultTarzanElephantLevelExitDismount(void)

{
  if (g_PlayerActionState != 4) {
    g_AdultTarzanElephantLevelExitDismountActive = 1;
    PlayAudioById(0x45,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 4;
    (*(code *)g_AdultTarzanElephantEnterMountTransitionHandlerPtr)();
    SetHudExtraLifeMeterEnabled(0);
  }
  return;
}

