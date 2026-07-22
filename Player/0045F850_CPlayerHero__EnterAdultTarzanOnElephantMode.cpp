#include "tarzan_ghidra_types.hpp"

// Address: 0x0045F850
// Label: CPlayerHero::EnterAdultTarzanOnElephantMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanOnElephantMode(void)

{
  g_AdultTarzanElephantRouteEvent10Active = 0;
  g_TarzanToTheRescueTrackedKnifeEnemyGroupB3 = 0;
  CPlayerHero::ResetAdultTarzanElephantRideState();
  PlayAudioById(200,(int *)0,(undefined4 *)0);
  *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2) = 0;
  g_TarzanToTheRescueElephantRideMountState = 0;
  return;
}

