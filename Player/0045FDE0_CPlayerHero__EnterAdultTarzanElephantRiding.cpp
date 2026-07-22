#include "tarzan_ghidra_types.hpp"

// Address: 0x0045FDE0
// Label: CPlayerHero::EnterAdultTarzanElephantRiding
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanElephantRiding(void)

{
  *(int *)(g_PlayerEntitySceneObjectData + 4) = g_WorldEntitySceneObjectArrayBase + 0x2a40;
  g_PlayerCurrentAnimationId = 0;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_AdultTarzanElephantRidingAnimationScriptPtr;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  *(ushort *)(g_PlayerAnimationState + 0x16) = (ushort)*(byte *)(g_PlayerEntitySceneObject + 0x74);
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 100;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = *(undefined4 *)(g_PlayerMotionState + 0x1c);
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x18;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 0x18;
  return;
}

