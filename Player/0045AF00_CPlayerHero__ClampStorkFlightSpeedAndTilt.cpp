#include "tarzan_ghidra_types.hpp"

// Address: 0x0045AF00
// Label: CPlayerHero::ClampStorkFlightSpeedAndTilt
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::ClampStorkFlightSpeedAndTilt(void)

{
  if (*(int *)(g_PlayerMotionState + 0x1c) <= *(int *)(g_PlayerMotionState + 0x10)) {
    *(int *)(g_PlayerMotionState + 0x10) = *(int *)(g_PlayerMotionState + 0x1c);
  }
  if (*(int *)(g_PlayerMotionState + 0x10) < 1) {
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  }
  if (0x180 < *(short *)(g_PlayerEntitySceneObject + 0xa0)) {
    *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0) = 0x180;
  }
  if (*(short *)(g_PlayerEntitySceneObject + 0xa0) < -0x180) {
    *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0) = 0xfe80;
  }
  if (0x80 < *(short *)(g_PlayerEntitySceneObject + 0xa4)) {
    *(undefined2 *)(g_PlayerEntitySceneObject + 0xa4) = 0x80;
  }
  if (*(short *)(g_PlayerEntitySceneObject + 0xa4) < -0x80) {
    *(undefined2 *)(g_PlayerEntitySceneObject + 0xa4) = 0xff80;
  }
  if (*(int *)(g_PlayerMotionState + 0x10) < 1) {
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  }
  return;
}

