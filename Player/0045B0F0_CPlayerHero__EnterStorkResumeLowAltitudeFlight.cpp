#include "tarzan_ghidra_types.hpp"

// Address: 0x0045B0F0
// Label: CPlayerHero::EnterStorkResumeLowAltitudeFlight
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterStorkResumeLowAltitudeFlight(void)

{
  *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 6;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x76) = *g_PlayerEntitySceneObjectData;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
  *(undefined2 *)(g_PlayerAnimationState + 0x1c) = 0x33;
  g_PlayerCurrentAnimationId = 2;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_StorkLowAltitudeFlightAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

