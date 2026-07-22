#include "tarzan_ghidra_types.hpp"

// Address: 0x00435C40
// Label: CPlayerHero::UpdateRunInputAndMovement
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateRunInputAndMovement(void)

{
  uint value;
  
  value = _g_PlayerCurrentCollisionMode & 0xffff;
  if ((value == 1) || (value == 4)) {
    if ((g_CameraFollowFlags & g_PlayerInputHeldMask) == 0) {
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
      CPlayerHero::UpdateMovementAndCollision(1);
      return;
    }
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = g_PlayerTargetMoveSpeed;
  }
  else {
    if (value == 5) {
      g_PlayerLateralSurfaceOffset = 0;
      CPlayerHero::UpdateMovementAndCollision(1);
      return;
    }
    if ((g_CameraFollowFlags & g_PlayerInputHeldMask) == 0) {
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    }
    else {
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = g_PlayerTargetMoveSpeed;
    }
    if (((g_PlayerActiveSurfaceDefinition != 0) &&
        (*(int *)(g_PlayerActiveSurfaceDefinition + 0x14) != 5)) &&
       ((_g_CameraRelativeTurnInputMask & 0xffff & g_PlayerInputPressedMask) != 0)) {
      *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
      CPlayerHero::UpdateMovementAndCollision(1);
      return;
    }
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  return;
}

