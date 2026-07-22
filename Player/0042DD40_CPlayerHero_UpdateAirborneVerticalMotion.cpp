#include "tarzan_ghidra_types.hpp"

// Address: 0x0042DD40
// Label: CPlayerHero_UpdateAirborneVerticalMotion
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero_UpdateAirborneVerticalMotion(void)

{
  undefined2 value;
  
  if (*(char *)(g_PlayerMotionState + 0xd) != '\0') {
    CEntities::TryCorrectEntitySceneObjectVerticalCollisionPenetration(g_PlayerEntitySceneObject);
    *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
    *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
    value = g_PlayerActionState;
    if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\x04') {
      g_PlayerActionState = 3;
      g_PreviousPlayerActionState = value;
      (*(code *)g_StampedeEnterFallingHandlerPtr)();
    }
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) - *(int *)(g_PlayerMotionState + 0x20);
    return;
  }
  *(int *)(g_PlayerMotionState + 0x20) =
       *(int *)(g_PlayerMotionState + 0x20) + *(int *)(g_PlayerMotionState + 0x24);
  if (*(int *)(g_PlayerMotionState + 0x2c) < *(int *)(g_PlayerMotionState + 0x20)) {
    *(int *)(g_PlayerMotionState + 0x20) = *(int *)(g_PlayerMotionState + 0x2c);
  }
  *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
       *(int *)(g_PlayerEntitySceneObjectData + 0xc) + *(int *)(g_PlayerMotionState + 0x20);
  return;
}

