#include "tarzan_ghidra_types.hpp"

// Address: 0x00437E10
// Label: CPlayerHero::EnterJaneScriptedEntityFollow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterJaneScriptedEntityFollow(void)

{
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  _g_PlayerCameraOverrideTargetX = *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
  _g_PlayerCameraOverrideTargetY = *(undefined4 *)(g_PlayerEntitySceneObject + 0x18);
  *( undefined1 *)((int)&g_PlayerSequenceFlags + 1) = *( undefined1 *)((int)&g_PlayerSequenceFlags + 1) | 0x10;
  _g_PlayerCameraOverrideTargetZ = *(undefined4 *)(g_PlayerEntitySceneObject + 0x1c);
  g_CameraOverrideTargetPtr = &g_PlayerCameraOverrideTargetX;
  return;
}

