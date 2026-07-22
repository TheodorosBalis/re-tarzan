#include "tarzan_ghidra_types.hpp"

// Address: 0x004929D0
// Label: CPlayerHero::EnterYoungSwingPump
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterYoungSwingPump(void)

{
  int value;
  int value2;
  
  if (g_CurrentSwingEntity != 0) {
    value = *(int *)(g_CurrentSwingEntity + 0x38);
    if (value != 0) {
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x110) = *(undefined4 *)(value + 0x110);
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c) = *(undefined4 *)(value + 0x10c);
    }
    value = CEntities::FindEntityAttachmentByFlags(g_CurrentSwingEntity,0x8000000);
    if (value != 0) {
      value2 = *(int *)(value + 0x20) >> 3;
      if (value2 < *(int *)(value + 0x14)) {
        *(int *)(value + 0x14) = value2;
      }
      *(undefined2 *)(value + 0xe) = 2;
      g_PlayerCurrentAnimationId = 0;
      if ((g_PreviousPlayerActionState < 7) ||
         ((8 < g_PreviousPlayerActionState && (g_PreviousPlayerActionState != 0x17)))) {
        if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
          *(undefined2 *)(value + 0x10) = 0x49;
        }
        else {
          *(undefined2 *)(value + 0x10) = 0x5a;
        }
        PlayAudioById(0x13,(int *)0,(undefined4 *)0);
      }
      else {
        value2 = *(int *)(g_PlayerMotionState + 0x10);
        if (*(int *)(value + 0x14) < value2) {
          if (*(int *)(value + 0x20) < value2) {
            *(int *)(value + 0x14) = *(int *)(value + 0x20);
          }
          else {
            *(int *)(value + 0x14) = value2;
          }
        }
        *(int *)(value + 0x14) = *(int *)(value + 0x20) >> 1;
        if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
          *(undefined2 *)(value + 0x10) = 0x6b;
        }
        else {
          *(undefined2 *)(value + 0x10) = 0x74;
        }
      }
    }
    UpdatePlayerOnSwing(g_CurrentSwingEntity);
  }
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
  *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  _g_PlayerSwingPumpCooldown = 10;
  return;
}

