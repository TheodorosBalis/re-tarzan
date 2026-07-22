#include "tarzan_ghidra_types.hpp"

// Address: 0x00455D70
// Label: CPlayerHero::EnterStampedeTerrainHazardStumble
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterStampedeTerrainHazardStumble(void)

{
  int value;
  
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x56;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 3;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 3;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x80;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 1;
  g_PlayerCurrentAnimationId = 4;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_StampedeHazardStumbleAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0xffffb000;
  value = CEntities::SpawnEntityByTypeAtPosition
                    (*(undefined4 *)(g_PlayerEntitySceneObject + 0x14),
                     *(undefined4 *)(g_PlayerEntitySceneObject + 0x18),
                     *(int *)(g_PlayerEntitySceneObject + 0x1c) + -0x200,0x15e,0x11);
  if (value != 0) {
    *(undefined4 *)(*(int *)(value + 0x38) + 0xb4) = 1;
    *(undefined4 *)(*(int *)(value + 0x38) + 0xa8) = 0x2134;
    *(undefined4 *)(*(int *)(value + 0x38) + 0xac) = 0x2134;
    *(undefined4 *)(*(int *)(value + 0x38) + 0xb0) = 0x2134;
    *(undefined4 *)(*(int *)(value + 0x38) + 0x6c) = 0xffffffc0;
  }
  PlayAudioById(0x1de,(int *)0,(undefined4 *)0);
  return;
}

