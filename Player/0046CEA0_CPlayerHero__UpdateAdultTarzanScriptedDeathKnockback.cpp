#include "tarzan_ghidra_types.hpp"

// Address: 0x0046CEA0
// Label: CPlayerHero::UpdateAdultTarzanScriptedDeathKnockback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanScriptedDeathKnockback(void)

{
  int value;
  
  CPlayerHero::AdvanceAnimationScript();
  if (*(char *)(g_PlayerMotionState + 0xd) == '\0') {
    *(int *)(g_PlayerMotionState + 0x20) =
         *(int *)(g_PlayerMotionState + 0x20) + *(int *)(g_PlayerMotionState + 0x24);
    if (*(int *)(g_PlayerMotionState + 0x2c) < *(int *)(g_PlayerMotionState + 0x20)) {
      *(int *)(g_PlayerMotionState + 0x20) = *(int *)(g_PlayerMotionState + 0x2c);
    }
    value = *(int *)(g_PlayerEntitySceneObjectData + 0xc) + *(int *)(g_PlayerMotionState + 0x20);
  }
  else {
    *(int *)(g_PlayerMotionState + 0x20) =
         *(int *)(g_PlayerMotionState + 0x20) - *(int *)(g_PlayerMotionState + 0x28);
    if (*(int *)(g_PlayerMotionState + 0x20) < 1) {
      *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
      *(byte *)(g_PlayerMotionState + 0xd) = ~*(byte *)(g_PlayerMotionState + 0xd);
    }
    value = *(int *)(g_PlayerEntitySceneObjectData + 0xc) - *(int *)(g_PlayerMotionState + 0x20);
  }
  *(int *)(g_PlayerEntitySceneObjectData + 0xc) = value;
  value = *(int *)(g_PlayerMotionState + 0x10);
  if (value < 0) {
    *(int *)(g_PlayerMotionState + 0x10) = *(int *)(g_PlayerMotionState + 0x18) + value;
    if (0 < *(int *)(g_PlayerMotionState + 0x10)) {
LAB_0043610a:
      *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    }
  }
  else {
    *(int *)(g_PlayerMotionState + 0x10) = value - *(int *)(g_PlayerMotionState + 0x18);
    if (*(int *)(g_PlayerMotionState + 0x10) < 0) goto LAB_0043610a;
  }
  value = *(int *)(g_PlayerMotionState + 0x30);
  if (value < 0) {
    *(int *)(g_PlayerMotionState + 0x30) = *(int *)(g_PlayerMotionState + 0x38) + value;
    if (*(int *)(g_PlayerMotionState + 0x30) < 1) goto LAB_00436144;
  }
  else {
    *(int *)(g_PlayerMotionState + 0x30) = value - *(int *)(g_PlayerMotionState + 0x38);
    if (-1 < *(int *)(g_PlayerMotionState + 0x30)) goto LAB_00436144;
  }
  *(undefined4 *)(g_PlayerMotionState + 0x30) = 0;
LAB_00436144:
  *(int *)(g_PlayerEntitySceneObjectData + 8) =
       *(int *)(g_PlayerEntitySceneObjectData + 8) + *(int *)(g_PlayerMotionState + 0x10);
  *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
       *(int *)(g_PlayerEntitySceneObjectData + 0x10) + *(int *)(g_PlayerMotionState + 0x30);
  return;
}

