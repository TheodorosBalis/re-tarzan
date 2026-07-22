#include "tarzan_ghidra_types.hpp"

// Address: 0x0046C720
// Label: CPlayerHero::UpdateAdultTarzanClimbableEdgePullUp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanClimbableEdgePullUp(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  undefined4 value3;
  
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
  }
  value = CPlayerHero::AdvanceAnimationScript();
  value2 = g_PlayerActionState;
  if (value == 7) {
    if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
      if (g_PlayerCurrentCollisionMode == 1) {
        if (((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) &&
           (g_PlayerCollisionFacingFlags == '\0')) {
          g_PlayerActionState = 0x41;
          g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046c8a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)g_AdultTarzanEnterFreeMovementForwardHandlerPtr)();
          return;
        }
      }
      else if (g_PlayerCurrentCollisionMode == 2) {
        resultFlag = CPlayerHero::IsFacingCurrentCollisionSurface();
        value2 = g_PlayerActionState;
        if (((resultFlag == '\0') && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) &&
           (g_PlayerCollisionFacingFlags == '\0')) {
          g_PlayerActionState = 1;
          g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046c868. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)g_AdultTarzanEnterMoveForwardHandlerPtr)();
          return;
        }
      }
      else if ((g_PlayerCurrentCollisionMode == 5) && (g_PlayerCollisionFacingFlags == '\0')) {
        g_PlayerActionState = 0xd;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046c827. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_AdultTarzanEnterTreeSurfingHandlerPtr)();
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
    ComputeEntitySceneObjectCollisionMoveDelta(0,0,g_PlayerEntitySceneObject);
    *(int *)(g_PlayerEntitySceneObjectData + 8) =
         *(int *)(g_PlayerEntitySceneObjectData + 8) + *(int *)(g_PlayerEntitySceneObject + 0x54);
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + *(int *)(g_PlayerEntitySceneObject + 0x58);
    *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
         *(int *)(g_PlayerEntitySceneObjectData + 0x10) + *(int *)(g_PlayerEntitySceneObject + 0x5c)
    ;
  }
  return;
}

