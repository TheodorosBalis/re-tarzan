#include "tarzan_ghidra_types.hpp"

// Address: 0x0045BF40
// Label: CPlayerHero::DampStorkPitchAndRoll
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::DampStorkPitchAndRoll(void)

{
  short shortValue;
  int value;
  
  shortValue = *(short *)(g_PlayerEntitySceneObject + 0xa4);
  value = *(short *)(g_PlayerEntitySceneObject + 0xa0) * 0x10000;
  if (((byte)g_PlayerInputHeldMask & 0xa0) != 0) {
    g_StorkRollDampingTicks = 0;
  }
  if (((byte)g_PlayerInputHeldMask & 0x50) != 0) {
    g_StorkPitchDampingTicks = 0;
  }
  if (0x3f < g_StorkRollDampingTicks) {
    *(undefined2 *)(g_PlayerEntitySceneObject + 0xa4) = 0;
    g_StorkRollDampingTicks = 0;
  }
  if (*(short *)(g_PlayerEntitySceneObject + 0xa4) == 0) {
    g_StorkRollDampingTicks = 0;
  }
  else {
    *(short *)(g_PlayerEntitySceneObject + 0xa4) =
         *(short *)(g_PlayerEntitySceneObject + 0xa4) -
         (short)((uint)((((int)shortValue << 0x10) >> 6) * g_StorkRollDampingTicks) >> 0x10);
    g_StorkRollDampingTicks = g_StorkRollDampingTicks + 1;
  }
  if (0x1ff < g_StorkPitchDampingTicks) {
    *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0) = 0;
    g_StorkPitchDampingTicks = 0;
  }
  if (value == 0) {
    g_StorkPitchDampingTicks = 0;
    return;
  }
  *(short *)(g_PlayerEntitySceneObject + 0xa0) =
       *(short *)(g_PlayerEntitySceneObject + 0xa0) -
       (short)((uint)((value >> 9) * g_StorkPitchDampingTicks) >> 0x10);
  g_StorkPitchDampingTicks = g_StorkPitchDampingTicks + 1;
  return;
}

