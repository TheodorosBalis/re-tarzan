#include "tarzan_ghidra_types.hpp"

// Address: 0x00437F10
// Label: CPlayerHero::UpdateDebugFreeMovement
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateDebugFreeMovement(void)

{
  undefined2 value;
  short shortValue;
  bool flagByte;
  
  value = g_PlayerActionState;
  if (((g_PlayerEdgeBalanceInputMask & g_PlayerInputHeldMask) != 0) &&
     (shortValue = g_PlayerBalanceWobbleTimer + 1, flagByte = g_PlayerBalanceWobbleTimer < 0,
     g_PlayerBalanceWobbleTimer = shortValue, flagByte)) {
LAB_00437f38:
    g_PlayerActionState = 4;
    g_PreviousPlayerActionState = value;
    (*(code *)g_JaneEnterFallingHandlerPtr)();
    return;
  }
  if ((g_PlayerEdgeBalanceInputMask & g_PlayerInputHeldMask) == 0) {
    flagByte = 5 < g_PlayerBalanceWobbleTimer;
    g_PlayerBalanceWobbleTimer = g_PlayerBalanceWobbleTimer + 1;
    if (flagByte) goto LAB_00437f38;
    g_PlayerBalanceWobbleTimer = -8;
  }
  if ((g_PlayerInputHeldMask & 0x10) != 0) {
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + -4;
  }
  if ((g_PlayerInputHeldMask & 0x40) != 0) {
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + 4;
  }
  if ((g_PlayerInputHeldMask & 0x80) != 0) {
    *(int *)(g_PlayerEntitySceneObjectData + 8) = *(int *)(g_PlayerEntitySceneObjectData + 8) + -4;
  }
  if ((g_PlayerInputHeldMask & 0x20) != 0) {
    *(int *)(g_PlayerEntitySceneObjectData + 8) = *(int *)(g_PlayerEntitySceneObjectData + 8) + 4;
  }
  if ((g_PlayerInputHeldMask & 0x8000) != 0) {
    *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
         *(int *)(g_PlayerEntitySceneObjectData + 0x10) + -4;
  }
  if ((g_PlayerInputHeldMask & 0x2000) != 0) {
    *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
         *(int *)(g_PlayerEntitySceneObjectData + 0x10) + 4;
  }
  return;
}

