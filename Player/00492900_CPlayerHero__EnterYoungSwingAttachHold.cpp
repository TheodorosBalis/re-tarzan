#include "tarzan_ghidra_types.hpp"

// Address: 0x00492900
// Label: CPlayerHero::EnterYoungSwingAttachHold
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterYoungSwingAttachHold(void)

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
      *(undefined2 *)(value + 0xe) = 2;
      if (value2 < *(int *)(value + 0x14)) {
        *(int *)(value + 0x14) = value2;
      }
    }
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

