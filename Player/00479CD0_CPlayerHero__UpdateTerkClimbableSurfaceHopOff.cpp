#include "tarzan_ghidra_types.hpp"

// Address: 0x00479CD0
// Label: CPlayerHero::UpdateTerkClimbableSurfaceHopOff
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateTerkClimbableSurfaceHopOff(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  uint value3;
  
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 8) {
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x80;
    g_PlayerTargetMoveSpeed = 0x80;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x40;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 2;
    *(undefined4 *)(g_PlayerMotionState + 0x20) = 8;
    *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xf0;
    *(undefined4 *)(g_PlayerMotionState + 0x24) = 8;
    *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  }
  else if (((value == 0xe) && (g_PlayerLatchedInteractionCollisionSurface != 0)) &&
          ((*(uint *)(g_PlayerLatchedInteractionCollisionSurface + 0x14) & 0xc000) != 0)) {
    value3 = (uint)*(ushort *)(g_PlayerLatchedInteractionCollisionSurface + 0x18);
    value = *(int *)(g_CollisionSurfaceTable + 4 + value3 * 4) + 0x34 +
            ((uint)*(ushort *)(g_PlayerLatchedInteractionCollisionSurface + 0x1a) * 7 + value3) * 4 +
            g_CollisionSurfaceTable;
    *(uint *)(g_PlayerEntitySceneObject + 0x110) = value3;
    if ((*(uint *)(value + 0x14) & 0x2000) == 0) {
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c) = *(undefined4 *)(value + 0xc);
    }
    else {
      *(int *)(g_PlayerEntitySceneObject + 0x10c) = *(int *)(value + 0xc) + -1;
    }
  }
  CPlayerHero::UpdateJumpArcVerticalMotion(0);
  CPlayerHero::UpdateRunInputAndMovement();
  resultFlag = CPlayerHero::TryResolveGroundContactSnap();
  value2 = g_PlayerActionState;
  if (resultFlag != '\0') {
    g_PlayerActionState = 0xc;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00479dee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_TerkEnterLandingRecoveryHandlerPtr)();
    return;
  }
  return;
}

