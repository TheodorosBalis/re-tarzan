#include "tarzan_ghidra_types.hpp"

// Address: 0x0045B160
// Label: CPlayerHero::EnterStorkLowAltitudeFlight
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterStorkLowAltitudeFlight(void)

{
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 5;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xffffffe8;
  if (0x7fff < *(ushort *)(g_PlayerAnimationState + 0x16)) {
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0;
  }
  if (*(undefined **)(g_PlayerAnimationState + 0xc) == &DAT_00503f94) {
    *(undefined2 *)(g_PlayerAnimationState + 0x16) =
         *(undefined2 *)
          (&g_StorkLowAltitudeFlightAnimationFrameRemapTable +
          *(short *)(g_PlayerAnimationState + 0x16) * 4);
  }
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

