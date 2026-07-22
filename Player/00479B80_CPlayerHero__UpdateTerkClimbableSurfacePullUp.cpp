#include "tarzan_ghidra_types.hpp"

// Address: 0x00479B80
// Label: CPlayerHero::UpdateTerkClimbableSurfacePullUp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateTerkClimbableSurfacePullUp(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  undefined4 value3;
  
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_TerkEnterFallingHandlerPtr)();
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 7) {
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && (g_PlayerCurrentCollisionMode == 2)) {
      resultFlag = CPlayerHero::IsFacingCurrentCollisionSurface();
      value2 = g_PlayerActionState;
      if ((resultFlag == '\0') &&
         (((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0 &&
          (g_PlayerCollisionFacingFlags == '\0')))) {
        g_PlayerActionState = 1;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00479c47. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_TerkEnterMoveForwardHandlerPtr)();
        return;
      }
    }
  }
  else if (value == 8) {
    value = *(int *)(g_PlayerEntitySceneObject + 0x110) * 4 + 4;
    value3 = ProjectWorldPositionToJungleSurfaceCoord
                      (g_PlayerEntitySceneObject + 0x14,
                       *(int *)(value + g_CollisionSurfaceTable) + value + g_CollisionSurfaceTable);
    *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c) = value3;
  }
  return;
}

